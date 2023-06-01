/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:05:36 by cgross            #+#    #+#             */
/*   Updated: 2023/06/01 16:54:09 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg *arg;

	if (arg_init(argc, argv) == NULL)
	{
		return (0);
	}
	else
	{
		arg = arg_init(argc, argv);
		printf("total:	%d\n", arg->total);
		printf("death:	%d\n", arg->death);
		printf("eat:	%d\n", arg->eat);
		printf("sleep:	%d\n", arg->sleep);
		if (argc == 6)
		printf("m_eat:	%d\n", arg->m_eat);
	}
	free(arg);
}
