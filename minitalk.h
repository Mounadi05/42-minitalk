/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:43:42 by amounadi          #+#    #+#             */
/*   Updated: 2021/12/19 21:47:42 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define LLONG_MAX 9223372036854775807

int		ft_atoi(const char *str);
int		ft_strlen(char *s);
void	ft_putnbr(int nb);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
void	ft_color(int color);

#endif
