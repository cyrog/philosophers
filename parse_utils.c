/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:24:19 by cgross            #+#    #+#             */
/*   Updated: 2023/06/04 13:08:15 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

	res = 0;
	neg = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f'))
			str++;
	if (*str == '-')
		neg = neg * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

int	isdigitok(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	isvalid(int argc, char **argv)
{
	int	i;

	if (ft_atoi(argv[1]) == 0)
	{
		printf("minimum amount of philosopher is 1\n");
		return (1);
	}
	i = 2;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 60)
		{
			printf("minimum time is > 60 milliseconds\n");
			return (1);
		}
		i++;
	}
	if (isdigitok(argv) != 0)
	{
		printf("all args must be postive digits\n");
		return (1);
	}
	return (0);
}

int		parse_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("wrong amount of arguments: ./philo 2 800 200 200 (200)\n");
		return (1);
	}
	if (isvalid(argc, argv) != 0)
		return (2);
	else
		return (0);
}
