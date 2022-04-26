/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:45:20 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/26 01:20:26 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time, t_philo *philo)
{
	struct timeval		tv;
	long long unsigned	a;
	long long unsigned	c;

	gettimeofday(&tv, NULL);
	c = 0;
	a = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	while (c < time)
	{
		ft_check(philo);
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
	if (!philo->table->is_alive)
		exit(0);
	if ((philo->table->is_alive && philo->ttd <= ft_time(philo))
		|| philo->table->nbp == 1)
	{
		philo->table->is_alive = 0;
		sem_wait(philo->table->print);
		if (!philo->table->is_alive)
			printf("%d ms : philo %d is died \n", philo->ttd, philo->ip);
		exit(0);
		sem_post(philo->table->print);
		return (1);
	}
	return (0);
}
