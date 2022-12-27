#include "philo.h"

void	take_forks(t_all *all)
{
	t_philo *ph1;
	t_mutex	*mutex1;

	ph1 = all->ph;
	mutex1 = all->mutex;
	if ((ph1->id % 2) == 0 && ph1->arr_forks[(ph1->id) % ph1->total] == 0 && ph1->arr_forks[(ph1->id) - 1] == 0)
	{
		pthread_mutex_lock(&mutex1->forks[(ph1->id) % ph1->total]);
		ph1->arr_forks[(ph1->id) % (ph1->total)] = 1;
		print(all, FORK);
		pthread_mutex_lock(&mutex1->forks[(ph1->id) - 1]);
		ph1->arr_forks[(ph1->id) - 1] = 1;
		print(all, FORK);
	}
	else if ((ph1->id % 2) == 1 && ph1->arr_forks[(ph1->id) % ph1->total] == 0 && ph1->arr_forks[(ph1->id) + 1] == 0)
	{
		pthread_mutex_lock(&mutex1->forks[(ph1->id) % ph1->total]);
		ph1->arr_forks[(ph1->id) % (ph1->total)] = 1;
		print(all, FORK);
		pthread_mutex_lock(&mutex1->forks[(ph1->id) + 1]);
		ph1->arr_forks[(ph1->id) + 1] = 1;
		print(all, FORK);
	}
}
