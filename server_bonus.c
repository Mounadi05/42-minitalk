/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:59:49 by amounadi          #+#    #+#             */
/*   Updated: 2021/12/19 22:57:02 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_id(char c)
{
	static int	c_id = 0;
	static int	tmp = 0;

	if (c == '\0')
	{
		tmp = c_id;
		c_id = 0;
		return (tmp);
	}
	c_id = c_id * 10 + (c - 48);
	return (1);
}

void	send_signal(int c_id, int sig, int *on)
{
	if (sig == SIGUSR2)
	{
		if (*on == 1)
			kill(c_id, SIGUSR1);
	}
	if (sig == SIGUSR1)
	{
		if (*on == 1)
			kill(c_id, SIGUSR2);
	}
}

void	ft_norm(int *on)
{
	if (*on == 0)
	{
		*on = 1;
		write(1, "\n", 1);
	}
	else
		*on = 0;
}

void	check_signal(int signal)
{
	static int				count = 1;
	static unsigned int		c;
	static int				i = 0;
	static int				on = 0;
	static int				c_id = 0;

	if (signal == SIGUSR2)
		c = c + count;
	count *= 2;
	send_signal(c_id, signal, &on);
	i++;
	if (i >= 8)
	{
		if (c == '\0' || on == 0)
		{
			c_id = get_id(c);
			if (c == '\0')
				ft_norm(&on);
		}
		else
			write(1, &c, 1);
		count = 1;
		c = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_color(2);
	ft_putstr("\n\t\t\t\tWelcom to minitalk\n\n");
	ft_color(1);
	ft_putstr("\t\t===================>   ");
	ft_color(0);
	ft_putnbr(getpid());
	ft_color(1);
	ft_putstr("   <===================\n\n");
	ft_color(0);
	signal(SIGUSR2, check_signal);
	signal(SIGUSR1, check_signal);
	write(1, "\n", 1);
	while (1)
		pause();
}
