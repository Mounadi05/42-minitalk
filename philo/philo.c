/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:28:28 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/26 00:21:04 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo_plus(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->nbp)
	{
		pthread_join(philo->p, NULL);
		philo = philo->next;
	}
	i = -1;
	while (++i < philo->table->nbp)
	{
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
	}
	pthread_mutex_destroy(&philo->table->print);
}

void	create_philo(t_philo *philo)
{
	int				i;
	struct timeval	t;

	i = -1;
	pthread_mutex_init(&philo->table->print, NULL);
	while (++i < philo->table->nbp)
	{
		pthread_mutex_init(&philo->fork, NULL);
		philo = philo->next;
	}
	i = -1;
	gettimeofday(&t, NULL);
	philo->table->t = (t.tv_usec / 1000) + (t.tv_sec * 1000);
	while (++i < philo->table->nbp)
	{
		philo->is_alive = 1;
		philo->ttd = philo->table->ttd;
		pthread_create(&(philo->p), NULL, ft_routine, (void *)philo);
		philo = philo->next;
		if (philo->table->nbp > 20)
			usleep(200);
		usleep(100);
	}
	create_philo_plus(philo);
}

void	init_philo(t_var *table, int ac, char **av, int *i)
{
	*i = 0;
	table->nbp = ft_atoi(av[1]);
	table->ttd = ft_atoi(av[2]);
	table->tte = ft_atoi(av[3]);
	table->tts = ft_atoi(av[4]);
	table->lock = 1;
	if (ac == 6)
		table->nte = ft_atoi(av[5]);
	else
		table->nte = -1;
}

int	main(int ac, char **av)
{
	int			i;
	t_philo		*philo;
	t_var		*table;

	i = 0;
	if (ac != 6 && ac != 5)
		write(2, "Error in argument\n", 18);
	else
	{
		while (++i < ac)
		{
			if (ft_atoi(av[i]) == -1)
			{
				write(2, "Error in argument\n", 18);
				return (0);
			}
		}
		table = (t_var *)malloc(sizeof(t_var));
		init_philo(table, ac, av, &i);
		philo = ft_lstnew(1, table, table->nte);
		while (++i < table->nbp)
			ft_lstadd_back(&philo, ft_lstnew(i + 1, table, table->nte));
		ft_lstlast(philo)->next = philo;
		create_philo(philo);
	}
}
