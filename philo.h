/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:46:48 by cgross            #+#    #+#             */
/*   Updated: 2023/06/04 14:58:10 by cgross           ###   ########.fr       */
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

typedef struct	s_rules
{
	int			total;
	int			death;
	int			eat;
	int			sleep;
	int			m_eat;
	pthread_t	thread_id;
}				t_rules;

typedef struct	s_id
{
	int				id;
	int				id_ate;
	int				lfork_id;
	int				rfork_id;
	long long		t_lastmeal;
	pthread_t		thread_id;
	struct s_arg	arg;
}				t_id;


typedef struct	s_philo
{
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*forks;
	t_arg			*arg;
}				t_philo;

int		parse_input(int argc, char **argv);
int		arg_init(int argc, char **argv, t_arg *arg);

int		ft_atoi(const char *str);
int		isdigitok(char **argv);
int		isvalid(int argc, char **argv);

void	*routine(t_arg *arg);

#endif
