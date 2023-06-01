#include "philo.h"

long x = 0;
pthread_mutex_t mutex;

void	*routine()
{
	long long i = 0;

	while (i++ < 1000000)
	{
		pthread_mutex_lock(&mutex);
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
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;
	pthread_t	t4;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t3, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t4, NULL, &routine, NULL) != 0)
		return (1);
	//pthread_create(&t2, NULL, &routine2, NULL);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (3);
	if (pthread_join(t3, NULL))
		return (3);
	if (pthread_join(t4, NULL))
		return (3);
	pthread_mutex_destroy(&mutex);
	printf("value of x : [%ld]\n", x);
}
