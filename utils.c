/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:00:01 by amounadi          #+#    #+#             */
/*   Updated: 2021/12/19 22:56:22 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int		n;

	n = nb;
	if (nb < 0)
	{
		ft_putstr("-");
		n = -nb;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_color(int color)
{
	if (color == 0)
		ft_putstr("\033[1;37m");
	if (color == 1)
		ft_putstr("\033[1;31m");
	if (color == 2)
		ft_putstr("\033[1;32m");
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					ng;

	i = 0;
	res = 0;
	ng = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str [i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			ng = -ng;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > LLONG_MAX)
		{
			if (ng == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return ((int)res * ng);
}
