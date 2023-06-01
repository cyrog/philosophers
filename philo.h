/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:46:48 by cgross            #+#    #+#             */
/*   Updated: 2023/06/01 17:21:57 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct	s_arg
{
	int		total;
	int		death;
	int		eat;
	int		sleep;
	int		m_eat;
}				t_arg;

typedef struct	s_philo
{
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	l_f;
	t_arg			*arg;
}				t_philo;

int		parse_input(int argc, char **argv);
t_arg	*arg_init(int argc, char **argv);

int		ft_atoi(const char *str);
int		isdigitok(char **argv);
int		isvalid(int argc, char **argv);

void	*routine(t_arg *arg);

#endif
