/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:21 by cgross            #+#    #+#             */
/*   Updated: 2023/05/31 14:01:50 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	printf("[testing threads]\n");
	sleep(3);
	printf("[ending thread]\n");
	return (0);
}

int	main(int ac, char **av)
{
	pthread_t	t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL != 0))
		return (1);
	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
