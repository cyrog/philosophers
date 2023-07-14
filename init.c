/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:07:23 by cgross            #+#    #+#             */
/*   Updated: 2023/06/19 12:53:01 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("wrong amount of arguments: ./philo 5 800 200 200 (200)\n");
		return (1);
	}
	if (isvalid(argc, argv) != 0)
		return (2);
	else
		return (0);
}

int	mutex_init(t_rules *rules)
{
	int	i;

	i = 0;
	while (i++ < rules->total)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	return (0);
}

int	philo_init(t_rules *rules)
{
	int	i;

	i = rules->total;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].x_ate = 0;
		rules->philo[i].l_fork = i;
		rules->philo[i].r_fork = (i + 1) % rules->total;
		rules->philo[i].t_lastmeal = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	arg_init(t_rules *rules, int argc, char **argv)
{
	if (parse_input(argc, argv) == 0)
	{
		rules->total = ft_atoi(argv[1]);
		rules->t_death = ft_atoi(argv[2]);
		rules->t_eat = ft_atoi(argv[3]);
		rules->t_sleep = ft_atoi(argv[4]);
		rules->died = 0;
		rules->all_ate = 0;
		if (argc == 6)
			rules->m_eat = ft_atoi(argv[5]);
		else
			rules->m_eat = -1;
	}
	else
		return (1);
	if (mutex_init(rules))
		return (2);
	philo_init(rules);
	return (0);
}
