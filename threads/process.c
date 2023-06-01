#include "philo.h"

int	main(void)
{
	int x = 2;
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		x++;
	sleep(2);
	printf("value of x : [%d]\n", x);
	printf("process id : [%d]\n", getpid());
	if (pid != 0)
		wait(NULL);
	return (0);
	}
