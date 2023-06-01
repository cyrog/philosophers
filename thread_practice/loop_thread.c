#include "philo.h"

long x = 0;
pthread_mutex_t mutex;

void	*routine()
{
	long i = 0;

	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		i++;
		x++;
		pthread_mutex_unlock(&mutex);
	}
	//sleep(2);
	//printf("value of x : [%lld]\n", x);
	return (0);
}

void	*routine2()
{
	sleep(2);
	printf("value of x : [%ld]\n", x);
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	th[4];
	int i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
			return 1;
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	sleep(2);
	while (i < 4)
	{
		if (pthread_join(th[i], NULL))
			return 1;
		i++;
		printf("thread %d has finished\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("value of x : [%ld]\n", x);
}
