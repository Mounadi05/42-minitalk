/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:28:28 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/26 02:12:34 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delete_philo(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	while (++i < philo->table->nbp)
	{
		sem_post(philo->fork);
		philo = philo->next;
	}
	i = -1;
	while (++i < philo->table->nbp)
	{
		sem_close(philo->fork);
		philo = philo->next;
	}
	sem_close(philo->table->print);
	i = -1;
	while (++i < philo->table->nbp)
	{
		kill(philo->pid, SIGKILL);
		philo = philo->next;
	}
}

void	init_sema(t_philo *philo)
{
	int		i;
	char	*str;
	char	*str1;

	i = -1;
	str = "fork";
	str1 = "print";
	philo->table->print = sem_open(str1, O_CREAT, 0644, 1);
	sem_unlink(str1);
	while (++i < philo->table->nbp)
	{
		philo->fork = sem_open(str, O_CREAT, 0644, 1);
		sem_unlink(str);
		philo = philo->next;
	}
}

void	create_philo(t_philo *philo)
{
	int				i;
	struct timeval	t;

	i = -1;
	gettimeofday(&t, NULL);
	philo->table->t = (t.tv_usec / 1000) + (t.tv_sec * 1000);
	init_sema(philo);
	while (++i < philo->table->nbp)
	{
		philo->pid = fork();
		philo->ip = i + 1;
		philo->table->is_alive = 1;
		philo->ttd = philo->table->ttd;
		if (philo->pid == 0)
		{
			pthread_create(&(philo->p), NULL, ft_routine, (void *)philo);
			pthread_join(philo->p, NULL);
		}
		if (philo->table->nbp > 40)
			usleep(200);
		usleep(100);
		philo = philo->next;
	}
	waitpid(-1, NULL, 0);
	delete_philo(philo);
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
