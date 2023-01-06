#include "philo.h"

void    destroy_all(int total, t_philo *ph)
{
	int	i;

        i = 0;
        pthread_mutex_destroy(&ph->vars->print);
        pthread_mutex_destroy(&ph->vars->m_checker);
	while (i < total)
	{
		pthread_mutex_destroy(&ph->vars->forks[i]);
		i++;
	}
	free(ph->vars->arr_fk);
        free(ph->vars->forks);
        free(ph->vars);
	free(ph);
}
