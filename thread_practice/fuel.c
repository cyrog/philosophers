#include "philo.h"

pthread_mutex_t	mutexFuel;
pthread_cond_t	condFuel;

int	fuel = 0;

void	*fuel_filling(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&mutexFuel);
		fuel += 60;
		printf("Filling fuel... %d\n", fuel);
		pthread_mutex_unlock(&mutexFuel);
		//pthread_cond_signal(&condFuel); //only signal 1 thread, needs broadcast for multiple
		pthread_cond_broadcast(&condFuel);
		sleep(1);
	}
	return (0);
}

void	*car(void *arg)
{
	pthread_mutex_lock(&mutexFuel);
	while (fuel < 40)
	{
		printf("no fuel, waiting...\n");
		pthread_cond_wait(&condFuel, &mutexFuel);
		//	cond_wait is equivalent to
		// 	pthread_mutex_unlock(&mutexFuel);
		//	wait for signal on condFuel
		//	pthread_mutex_lock(&mutexFuel);
	}
	fuel -= 40;
	printf("got fuel, now left: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
	return (0);
}

int	main()
{
	pthread_t th[5];
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_cond_init(&condFuel, NULL);
	for(int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
				perror("failed to create thread\n");
		}
		else
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
				perror("failed to create thread\n");
	}

	for (int i = 0; i < 5; i++)
		if (pthread_join(th[i], NULL) != 0)
			perror("failed to join thread\n");
	pthread_mutex_destroy(&mutexFuel);
	pthread_cond_destroy(&condFuel);
	return (0);
}
