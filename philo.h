/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:46:48 by cgross            #+#    #+#             */
/*   Updated: 2023/06/06 13:58:37 by cgross           ###   ########.fr       */
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

typedef struct	s_philo
{
	int				id;
	int				x_ate;
	int				l_fork;
	int				r_fork;
	long long		t_lastmeal;
	pthread_t		thread_id;
	struct s_rules	*rules;
}					t_philo;

typedef struct	s_rules
{
	int				total;
	int				death;
	int				eat;
	int				sleep;
	int				m_eat;
	int				died;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	meal_check;
	pthread_mutex_t	writing;
	t_philo			philo[250];
}				t_rules;

int		parse_input(int argc, char **argv);
int		arg_init(t_rules *rules, int argc, char **argv);

int		ft_atoi(const char *str);
int		isdigitok(char **argv);
int		isvalid(int argc, char **argv);

#endif
