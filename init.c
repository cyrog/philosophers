/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:07:23 by cgross            #+#    #+#             */
/*   Updated: 2023/06/04 14:55:03 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_arg *arg)
{
	int	i;

	i = 0;
	while (i++ < arg->total)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL))
			return (1);
		printf("fork init\n");
	}
	return (0);
}

int	id_init(t_id *id)
{
	int	i;

	i = 0;
	while (i < id->arg.total)
	{
		id[i]->id = i;
		id[i]->id_ate = 0;
		id[i]->lfork_id = i;
		id[i]->rfork_id = (i + 1) % id->arg.total;
		id[i]->t_lastmeal = 0;
	}
	return (0);
}


int	arg_init(int argc, char **argv, t_arg *arg)
{
	if (parse_input(argc, argv) == 0)
	{
		arg->total = ft_atoi(argv[1]);
		arg->death = ft_atoi(argv[2]);
		arg->eat = ft_atoi(argv[3]);
		arg->sleep = ft_atoi(argv[4]);
		if (argc == 6)
			arg->m_eat = ft_atoi(argv[5]);
		return (0);
	}
	else
		return (1);
}
