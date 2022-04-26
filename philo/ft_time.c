/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:45:20 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/26 00:09:30 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time, t_philo *philo)
{
	long long unsigned		a;
	long long unsigned		c;
	struct timeval			tv;

	c = 0;
	gettimeofday(&tv, NULL);
	a = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	while (c < time)
	{
		if (ft_check(philo))
			break ;
		gettimeofday(&tv, NULL);
		c = ((tv.tv_usec / 1000) + (tv.tv_sec * 1000)) - a;
		usleep(100);
	}
}

long long unsigned	ft_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	philo->table->time = (((tv.tv_usec) / 1000)
			+ (tv.tv_sec * 1000)) - philo->table->t;
	return (philo->table->time);
}

int	ft_check(t_philo *philo)
{
	int	i;

	i = -1;
	if (!philo->is_alive)
		return (1);
	if ((philo->table->lock && philo->ttd <= ft_time(philo))
		|| philo->table->nbp == 1)
	{
		philo->table->lock = 0;
		pthread_mutex_lock(&philo->table->print);
		if (philo->is_alive)
			printf("%d ms : philo %d is died \n", philo->ttd, philo->ip);
		while (++i < philo->table->nbp)
		{
			philo->is_alive = 0;
			philo = philo->next;
		}
		pthread_mutex_unlock(&philo->table->print);
		return (1);
	}
	return (0);
}
