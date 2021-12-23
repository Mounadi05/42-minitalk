/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:44:52 by amounadi          #+#    #+#             */
/*   Updated: 2021/12/19 22:56:38 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int	ncount(unsigned int n, int k)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (k < 0)
		i++;
	return (i);
}

static	int	dev(unsigned int n)
{
	int		i;

	i = 1;
	while (n > 1)
	{
		i *= 10;
		n--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*res;
	unsigned int	i;
	unsigned int	nb;

	nb = n;
	i = 0;
	if (n < 0)
		nb = -n;
	len = ncount(nb, n) + 1;
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[i++] = '-';
		len = len - 1;
	}
	while (--len > 0)
	{
		res[i++] = (nb / dev(len)) + '0';
		nb %= dev(len);
	}
	res[i] = '\0';
	return (res);
}
