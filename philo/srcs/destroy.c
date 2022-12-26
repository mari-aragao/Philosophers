#include "philo.h"

void    destroy_mutex(t_mutex *mutex)
{
        pthread_mutex_destroy(&mutex->print);
        pthread_mutex_destroy(&mutex->forks);
        free(mutex);
}

void    destroy_philo(t_philo *ph)
{
        int i;

        i = 0;
        while (i < ph[i].total_philos)
        {
                free(ph[i].arr_forks);
                i++;
        }
        free(ph);
}
