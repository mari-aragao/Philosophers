#include "philo.h"

int	print(t_philo ph, int action)
{
	long int	actual_time;

	actual_time = get_time() - ph.st_time;
	pthread_mutex_lock(&ph.vars->print);
	if (action == FORK)
		printf("%ld %i has taken a fork\n", actual_time, ph.id);
	if (action == EAT)
		printf("%ld %d is eating\n", actual_time, ph.id);
	if (action == SLEEP)
		printf("%ld %d is sleeping\n", actual_time, ph.id);
	if (action == THINK)
		printf("%ld %d is thinking\n", actual_time, ph.id);
	if (action == DIE)
		printf("%ld %d died\n", actual_time, ph.id);
	pthread_mutex_unlock(&ph.vars->print);
	return (0);
}
