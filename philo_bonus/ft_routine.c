/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:41:35 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/26 02:12:21 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_message_plus(t_philo *philo, int a)
{
	if (a == 3 && philo->table->is_alive)
	{
		sem_wait(philo->table->print);
		printf("%llu ms : philo %d is sleeping\n", ft_time(philo), philo->ip);
		sem_post(philo->table->print);
	}
	else if (a == 4 && philo->table->is_alive)
	{
		sem_wait(philo->table->print);
		printf("%llu ms : philo %d is thinking\n", ft_time(philo), philo->ip);
		sem_post(philo->table->print);
	}
	return (1);
}

int	print_message(t_philo *philo, int a)
{
	if (a == 0 && philo->table->is_alive)
	{
		sem_wait(philo->table->print);
		printf("%llu ms : philo %d  has taken a fork %d\n",
			ft_time(philo), philo->ip, philo->ip);
		sem_post(philo->table->print);
	}
	else if (a == 1 && philo->table->is_alive)
	{
		sem_wait(philo->table->print);
		printf("%llu ms : philo %d  has taken a fork %d\n",
			ft_time(philo), philo->ip, philo->next->ip);
		sem_post(philo->table->print);
	}
	else if (a == 2 && philo->table->is_alive)
	{
		sem_wait(philo->table->print);
		printf("%llu ms : philo %d is eating\n", ft_time(philo), philo->ip);
		sem_post(philo->table->print);
	}
	else
		print_message_plus(philo, a);
	return (1);
}

void	ft_routine_plus(t_philo *philo)
{
	print_message(philo, 1);
	print_message(philo, 2);
	ft_sleep(philo->table->tte, philo);
	philo->ttd += ft_time(philo);
	sem_post(philo->fork);
	philo->e--;
	sem_post(philo->next->fork);
	print_message(philo, 3);
	ft_sleep(philo->table->tts, philo);
	print_message(philo, 4);
}

void	*ft_routine(void *var)
{	
	t_philo	*philo;

	philo = (t_philo *)var;
	while (philo->e && philo->table->is_alive)
	{
		sem_wait(philo->fork);
		print_message(philo, 0);
		if (philo->table->nbp == 1)
		{
			usleep(philo->ttd * 1000);
			ft_check(philo);
		}
		sem_wait(philo->next->fork);
		ft_check(philo);
		ft_routine_plus(philo);
	}
	exit(0);
	return (0);
}
