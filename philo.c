/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:05:36 by cgross            #+#    #+#             */
/*   Updated: 2023/06/06 13:10:55 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules rules;

	if (arg_init(&rules, argc, argv) == 0)
	{
		printf("total:	%d\n", rules.total);
		printf("death:	%d\n", rules.death);
		printf("eat:	%d\n", rules.eat);
		printf("sleep:	%d\n", rules.sleep);
		if (argc == 6)
			printf("m_eat:	%d\n", rules.m_eat);
	}
	else
		return (0);
}
