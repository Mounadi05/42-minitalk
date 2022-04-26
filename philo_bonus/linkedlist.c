/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:34:08 by amounadi          #+#    #+#             */
/*   Updated: 2022/04/20 20:43:13 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int i, t_var *table, int a)
{
	t_philo	*head;

	head = NULL;
	head = (t_philo *)malloc(sizeof(t_philo));
	head->table = table;
	if (!head)
		return (NULL);
	head->ip = i;
	head->e = a;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
