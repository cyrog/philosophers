/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:46:48 by cgross            #+#    #+#             */
/*   Updated: 2023/07/14 14:12:29 by cgross           ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				l_fork;
	int				r_fork;
	long long		t_lastmeal;
	pthread_t		thread_id;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules
{
	int				total;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				m_eat;
	int				died;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	meal_check;
	pthread_mutex_t	writing;
	pthread_mutex_t	death_check;
	t_philo			philo[250];
}				t_rules;

int			parse_input(int argc, char **argv);
int			arg_init(t_rules *rules, int argc, char **argv);

long long	timestamp(void);
long long	timediff(long long past, long long pres);
void		print_action(t_rules *rules, int id, char *msg);
void		smoll_sleep(long long time, t_rules *rules);

void		philo_eats(t_philo *philo);
void		*routine(void *void_philosopher);
void		death_checker(t_rules *rules, t_philo *philo);
int			threading(t_rules *rules);
void		exit_threading(t_rules *rules, t_philo *philo);

int			ft_atoi(const char *str);
int			isdigitok(char **argv);
int			isvalid(int argc, char **argv);

#endif
