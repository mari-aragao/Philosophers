#include "philo.h"

long int	get_time(void)
{
	struct timeval	ct;
	long int	time;

	gettimeofday(&ct, NULL);
	time = (ct.tv_sec * 1000) + (ct.tv_usec / 1000);
	return (time);
}
