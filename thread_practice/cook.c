#include "philo.h"

pthread_mutex_t	stoveMutexes[4];
int	stoveFuel[4] = { 100, 100, 100, 100 };

void	*routine(void *args)
{
	for (int i; i < 4; i++)
	{
		if (pthread_mutex_trylock(&stoveMutexes[i]) == 0)
		{
			int fuelNeeded = (rand() % 30);
			if (stoveFuel[i] - fuelNeeded < 0)
			{
				printf("no more fuel... going home\n");
			}
			else
			{
				stoveFuel[i] -= fuelNeeded;
				usleep(500000);
				printf("fuel left %d\n", stoveFuel[i]);
			}
			pthread_mutex_unlock(&stoveMutexes[i]);
			break;
		}
		else
		{
			if (i == 3)
			{
				printf("no stove available yet, waiting...\n");
				usleep(300000);
				i = 0;
			}
		}
	}
	return (0);
}

int		main()
{
	pthread_t	th[10];
	for (int i = 0; i < 4; i++)
		pthread_mutex_init(&stoveMutexes[i], NULL);
	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("failed to create thread\n");
	}
	for (int i = 0; i < 10; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread\n");
	}
	for (int i = 0; i < 10; i++)
		pthread_mutex_destroy(&stoveMutexes[i]);
}
