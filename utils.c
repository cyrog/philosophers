/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:46:33 by cgross            #+#    #+#             */
/*   Updated: 2023/06/06 14:02:57 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 10000));
}

long long	timediff(long long past, long long pres)
{
	return (past - pres);
}

void	print_action(t_rules *rules, int id, char *msg)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->died))
	{
		printf("%lli ", timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", msg);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}
