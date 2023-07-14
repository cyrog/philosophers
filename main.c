/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:05:36 by cgross            #+#    #+#             */
/*   Updated: 2023/07/14 15:24:15 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philo;
	int		i;

	i = 0;
	philo = rules.philo;
	rules.first_timestamp = timestamp();
	if (arg_init(&rules, argc, argv) != 0)
		return (1);
	while (i < rules.total)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
			return (1);
		philo[i].t_lastmeal = timestamp();
		i++;
	}
	//death_checker(&rules, rules.philo);
	exit_threading(&rules, philo);
	return (0);
}
