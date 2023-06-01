#include "philo.h"

pthread_mutex_t mutex;

void	*routine(void* arg)
{
	if (pthread_mutex_trylock(&mutex) == 0)
	{
		printf("got lock\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	else
		printf("didn't get lock\n");
	return (0);
}

int	main()
{
	pthread_t	th[4];
	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("failed to create thread\n");
	}
	for (int i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread\n");
	}
}
