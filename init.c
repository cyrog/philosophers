/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:07:23 by cgross            #+#    #+#             */
/*   Updated: 2023/06/02 13:15:41 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		parse_input(int argc, char **argv)
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

t_arg	arg_init(int argc, char **argv)
{
	t_arg	arg;

	arg.total = ft_atoi(argv[1]);
	arg.death = ft_atoi(argv[2]);
	arg.eat = ft_atoi(argv[3]);
	arg.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg.m_eat = ft_atoi(argv[5]);
	else
		arg.m_eat = -1;
	return (arg);
}
