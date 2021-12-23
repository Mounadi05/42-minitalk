/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:05:10 by amounadi          #+#    #+#             */
/*   Updated: 2021/12/19 22:27:39 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	str_to_bit(unsigned char n, int p_id)
{
	int	i;

	i = 9;
	while (--i)
	{
		if ((n % 2) == 1)
		{
			kill(p_id, SIGUSR2);
			usleep(100);
		}
		if ((n % 2) == 0)
		{
			kill(p_id, SIGUSR1);
			usleep(100);
		}
		n = n / 2;
	}
}

void	str_to_char(char *str, int p_id)
{
	int				i;
	unsigned char	n;

	i = 0;
	while (str[i])
	{
		n = str[i];
		str_to_bit(n, p_id);
		i++;
	}
	n = str[i];
	str_to_bit(n, p_id);
}

void	send_c_id(char *str, int p_id)
{
	int				i;
	unsigned char	n;

	i = 0;
	while (str[i])
	{
		n = str[i];
		str_to_bit(n, p_id);
		i++;
	}
	n = str[i];
	str_to_bit(n, p_id);
}

void	recived_signal(int signal)
{
	static int	i = 0;

	(void)signal;
	ft_color(2);
	i++;
	if (i > 8)
		write(1, "Done\n", 5);
	usleep(100);
}

int	main(int ac, char **av)
{
	char	*c_id;

	signal(SIGUSR1, recived_signal);
	signal(SIGUSR2, recived_signal);
	if (ac == 3)
	{
		if (ft_atoi(av[1]) > 0)
		{
			c_id = ft_itoa(getpid());
			send_c_id(c_id, ft_atoi(av[1]));
			str_to_char(av[2], ft_atoi(av[1]));
			free(c_id);
		}
		else
		{	
			ft_color(1);
			ft_putstr("\n\tInvalid PID number 🙊\n");
		}
	}
	else
	{
		ft_color(1);
		ft_putstr("\n\tWRONG ARGUMENT 🙈\n");
	}
}
