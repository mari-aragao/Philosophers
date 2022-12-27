#include "philo.h"

void    destroy_all(int total, t_philo *ph)
{
	int	i;

        pthread_mutex_destroy(&ph->vars->print);
        i = 0;
	while (i < total)
	{
		pthread_mutex_destroy(&ph->vars->forks[i]);
		i++;
	}
	free(ph->vars->arr_fk);
        free(ph->vars);
	free(ph);
}
