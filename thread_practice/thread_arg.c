#include "philo.h"
#include <time.h>

int	primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void	*routine(void *arg)
{
	int index = *(int*)arg;
	int sum = 0;
	for (int j = 0; j < 5; j++)
		sum += primes[index + j];
	printf("localSum = [%d]\n", sum);
	*(int*)arg = sum;
	return (arg);
}

int	main(void)
{ 
	int i = 0;
	pthread_t	th[2];
	while (i < 2)
	{
		int	*a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("failed to create threads\n");
		i++;
	}
	i = 0;
	int globalSum = 0;
	while (i < 2)
	{
		int	*res;
		if (pthread_join(th[i], (void**)&res) != 0)	//res gets value by being passing there
			perror("failed to join threads\n");
		globalSum += *res;
		free(res);
		i++;
	}
	printf("global sum: %d\n", globalSum);
	return (0);
}
