/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:05:36 by cgross            #+#    #+#             */
/*   Updated: 2023/06/01 17:37:02 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg *arg;

	arg = arg_init(argc, argv);
	if (arg == NULL)
		return (0);
	else
	{
		if (arg != NULL)
		{
			printf("total:	%d\n", arg->total);
			printf("death:	%d\n", arg->death);
			printf("eat:	%d\n", arg->eat);
			printf("sleep:	%d\n", arg->sleep);
			if (argc == 6)
				printf("m_eat:	%d\n", arg->m_eat);
		}
	}
	free(arg);
}