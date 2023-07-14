/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:55:40 by cgross            #+#    #+#             */
/*   Updated: 2023/07/14 15:39:00 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->l_fork]));
	print_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->r_fork]));
	print_action(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	print_action(rules, philo->id, "is eating");
	philo->t_lastmeal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smoll_sleep(rules->t_eat, rules);
	(philo->x_ate++);
	pthread_mutex_unlock(&(rules->forks[philo->l_fork]));
	pthread_mutex_unlock(&(rules->forks[philo->r_fork]));
}

void	*routine(void *void_philo)
{
	t_philo			*philo;
	t_rules			*rules;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(1500);
	while (!(rules->died))
	{
		death_checker(rules, rules->philo);
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		print_action(rules, philo->id, "is sleeping");
		smoll_sleep(rules->t_sleep, rules);
		print_action(rules, philo->id, "is thinking");
	}
	return (NULL);
}

void	exit_threading(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->total)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < rules->total)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	death_checker(t_rules *rules, t_philo *philo)
{
	int	i;

	while (!(rules->all_ate))
	{
		i = -1;
		while (++i < rules->total && !(rules->died))
		{
			pthread_mutex_lock(&(rules->meal_check));
			if (timediff(philo[i].t_lastmeal, timestamp()) > rules->t_death)
			{
				print_action(rules, i, "died");
				rules->died = 1;
			}
			pthread_mutex_unlock(&(rules->meal_check));
			usleep(100);
		}
		if (rules->died)
			break ;
		i = 0;
		while (rules->m_eat != -1 && i < rules->total && philo[i].x_ate
			>= rules->m_eat)
			i++;
		if (i == rules->total)
			rules->all_ate = 1;
	}
}
