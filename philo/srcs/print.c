#include "philo.h"

int	print(t_all *all, int action)
{
	long int	actual_time;

	actual_time = get_time() - all->ph->start;
	printf("\nactual_time = %ld\n", actual_time);
	pthread_mutex_lock(&all->mutex->print);
	if (action == FORK)
		printf("%ld %d has taken a fork\n", actual_time, all->ph->id);
	if (action == EAT)
		printf("%ld %d is eating\n", actual_time, all->ph->id);
	if (action == SLEEP)
		printf("%ld %d is sleeping\n", actual_time, all->ph->id);
	if (action == THINK)
		printf("%ld %d is thinking\n", actual_time, all->ph->id);
	if (action == DIE)
		printf("%ld %d died\n", actual_time, all->ph->id);
	pthread_mutex_unlock(&all->mutex->print);
	return (0);
}
