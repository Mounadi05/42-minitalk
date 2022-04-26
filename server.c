/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:59:49 by amounadi          #+#    #+#             */
/*   Updated: 2021/12/23 22:44:00 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_signal(int signal)
{
	static int	count = 1;
	static int	c;
	static int	i = 0;

	if (signal == SIGUSR2)
	{
		c = c + count;
		count *= 2;
		i++;
	}
	if (signal == SIGUSR1)
	{
		count *= 2;
		i++;
	}
	if (i >= 8)
	{
		write(1, &c, 1);
		c = 0;
		count = 1;
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
