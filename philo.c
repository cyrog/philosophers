/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:05:36 by cgross            #+#    #+#             */
/*   Updated: 2023/06/04 14:52:53 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg *id;

	if (arg_init(argc, argv, &arg) == 0)
	{
		printf("total:	%d\n", id->arg.total);
		printf("death:	%d\n", id->arg.death);
		printf("eat:	%d\n", id->arg.eat);
		printf("sleep:	%d\n", id->arg.sleep);
		if (argc == 6)
			printf("m_eat:	%d\n", id->arg.m_eat);
	}
}
