#include "philo.h"

void    destroy_mutex(int total, t_mutex *mutex)
{
	int	i;

        pthread_mutex_destroy(&mutex->print);
        i = 0;
	while (i < total)
	{
		pthread_mutex_destroy(&mutex->forks[i]);
		i++;
	}
//	free(mutex->print);
//	free(mutex->forks);
        free(mutex);
}

void    destroy_philo(t_philo *ph)
{
        free(ph);
}
