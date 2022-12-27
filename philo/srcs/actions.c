#include "philo.h"

void	take_forks(t_philo ph)
{
	if ((ph.id % 2) == 0 && ph.vars->arr_fk[(ph.id) % ph.vars->total] == 0 && ph.vars->arr_fk[(ph.id) + 1] == 0)
	{
		pthread_mutex_lock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		ph.vars->arr_fk[(ph.id) % (ph.vars->total)] = 1;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id) + 1]);
		ph.vars->arr_fk[(ph.id) + 1] = 1;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) + 1]);
	}
	else if ((ph.id % 2) == 1 && ph.vars->arr_fk[(ph.id) % ph.vars->total] == 0 && ph.vars->arr_fk[(ph.id) - 1] == 0)
	{
		pthread_mutex_lock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		ph.vars->arr_fk[(ph.id) % (ph.vars->total)] = 1;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id) - 1]);
		ph.vars->arr_fk[(ph.id) - 1] = 1;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) - 1]);
	}
}

void	eating(t_philo ph)
{
	count_time(ph.vars->time_to_eat);
}

void	drop_forks(t_philo ph)
{
	if ((ph.id % 2) == 0 && ph.vars->arr_fk[(ph.id) % ph.vars->total] == 1 && ph.vars->arr_fk[(ph.id) - 1] == 1)
	{
		pthread_mutex_lock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		ph.vars->arr_fk[(ph.id) % (ph.vars->total)] = 0;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id) - 1]);
		ph.vars->arr_fk[(ph.id) - 1] = 0;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) - 1]);
	}
	else if ((ph.id % 2) == 1 && ph.vars->arr_fk[(ph.id) % ph.vars->total] == 0 && ph.vars->arr_fk[(ph.id) + 1] == 0)
	{
		pthread_mutex_lock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		ph.vars->arr_fk[(ph.id) % (ph.vars->total)] = 0;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) % ph.vars->total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id) + 1]);
		ph.vars->arr_fk[(ph.id) + 1] = 0;
		pthread_mutex_unlock(&ph.vars->forks[(ph.id) + 1]);
	}
}
