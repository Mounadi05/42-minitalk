/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 08:09:45 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/23 04:37:58 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



void	str_to_bit(char *str, int p_id)
{
	int				i;
	int				a;
	unsigned char	n;

	a = 0;
	while (str[a])
	{
		n = str[a];
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
		a++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) > 0)
			str_to_bit(av[2], ft_atoi(av[1]));
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
