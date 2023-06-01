#include "philo.h"
#include <time.h>

void	*roll_dice()
{
	int	value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));
	*result = value;
	sleep(2);
	printf("[%d]\n", value);
	printf("thread result :[%d]\n", value);
	pthread_exit ((void*) result);
}

int	main(void)
{
	int	*res;
	srand(time(NULL));
	pthread_t	th;

	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return (1);
	//	printf("thread [%i] created\n", i);
	//	pthread_exit(0);
	if (pthread_join(th,(void**)&res) != 0)
		return 2;
	//	printf("thread [%i] closed\n", i);
	printf("main result:	 [%p]\n", res);
	//printf("result: [%d]\n", *res);
	free(res);
	return (0);
}
