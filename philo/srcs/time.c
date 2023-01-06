#include "philo.h"

long int	get_time(void)
{
	struct timeval	ct;
	long int		time;

	gettimeofday(&ct, NULL);
	time = (ct.tv_sec * 1000) + (ct.tv_usec / 1000);
	return (time);
}

void	count_time(long int tm)
{
	long int	actual;
	long int	pass_time;

	actual = get_time();
	pass_time = get_time();
	while (pass_time - actual < tm)
	{
		usleep(10);
		pass_time = get_time();
	}
}
