#include "philo.h"

void	take_forks(t_all *all)
{
	t_philo *ph2;
	t_mutex	*mtx;

	ph2 = all->ph;
	mtx = all->mutex;
	if ((ph2->id % 2) == 0 && mtx->arr_forks[(ph2->id) % ph2->total] == 0 && mtx->arr_forks[(ph2->id) + 1] == 0)
	{
		pthread_mutex_lock(&mtx->forks[(ph2->id) % ph2->total]);
		mtx->arr_forks[(ph2->id) % (ph2->total)] = 1;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) % ph2->total]);
		pthread_mutex_lock(&mtx->forks[(ph2->id) + 1]);
		mtx->arr_forks[(ph2->id) + 1] = 1;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) + 1]);
	}
	else if ((ph2->id % 2) == 1 && mtx->arr_forks[(ph2->id) % ph2->total] == 0 && mtx->arr_forks[(ph2->id) - 1] == 0)
	{
		pthread_mutex_lock(&mtx->forks[(ph2->id) % ph2->total]);
		mtx->arr_forks[(ph2->id) % (ph2->total)] = 1;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) % ph2->total]);
		pthread_mutex_lock(&mtx->forks[(ph2->id) - 1]);
		mtx->arr_forks[(ph2->id) - 1] = 1;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) - 1]);
	}
}

void	eating(t_all *all)
{
	count_time(all->ph->time_to_eat);
}

void	drop_forks(t_all *all)
{
	t_philo *ph2;
	t_mutex	*mtx;

	ph2 = all->ph;
	mtx = all->mutex;
	if ((ph2->id % 2) == 0 && mtx->arr_forks[(ph2->id) % ph2->total] == 1 && mtx->arr_forks[(ph2->id) - 1] == 1)
	{
		pthread_mutex_lock(&mtx->forks[(ph2->id) % ph2->total]);
		mtx->arr_forks[(ph2->id) % (ph2->total)] = 0;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) % ph2->total]);
		pthread_mutex_lock(&mtx->forks[(ph2->id) - 1]);
		mtx->arr_forks[(ph2->id) - 1] = 0;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) - 1]);
	}
	else if ((ph2->id % 2) == 1 && mtx->arr_forks[(ph2->id) % ph2->total] == 0 && mtx->arr_forks[(ph2->id) + 1] == 0)
	{
		pthread_mutex_lock(&mtx->forks[(ph2->id) % ph2->total]);
		mtx->arr_forks[(ph2->id) % (ph2->total)] = 0;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) % ph2->total]);
		pthread_mutex_lock(&mtx->forks[(ph2->id) + 1]);
		mtx->arr_forks[(ph2->id) + 1] = 0;
		pthread_mutex_unlock(&mtx->forks[(ph2->id) + 1]);
	}
}
