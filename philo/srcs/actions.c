#include "philo.h"

int	take_forks(t_philo ph)
{
	int total;

	total = ph.vars->total;
	if ((ph.id % 2) == 0 && ph.vars->arr_fk[ph.id % total] == 0 && ph.vars->arr_fk[(ph.id % total) + 1] == 0)
	{
		pthread_mutex_lock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id % total) + 1]);
		ph.vars->arr_fk[ph.id % total] = 1;
		ph.vars->arr_fk[(ph.id % total) + 1] = 1;
		pthread_mutex_unlock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_unlock(&ph.vars->forks[(ph.id % total) + 1]);
		return (0);
	}
	else if ((ph.id % 2) == 1 && ph.vars->arr_fk[ph.id % total] == 0 && ph.vars->arr_fk[(ph.id) % total - 1] == 0)
	{
		pthread_mutex_lock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id % total) - 1]);
		ph.vars->arr_fk[ph.id % total] = 1;
		ph.vars->arr_fk[(ph.id % total) - 1] = 1;
		pthread_mutex_unlock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_unlock(&ph.vars->forks[(ph.id % total) - 1]);
		return (0);
	}
	return (-1);
}

void	eating(t_philo ph)
{
	count_time(ph.vars->time_to_eat);
	ph.last_meal = get_time();
	ph.meal_cntr += 1; 
}

void	sleeping(t_philo ph)
{
	count_time(ph.vars->time_to_sleep);
}

void	drop_forks(t_philo ph)
{
	int total;

	total = ph.vars->total;
	if ((ph.id % 2) == 0)
	{
		pthread_mutex_lock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id % total) + 1]);
		ph.vars->arr_fk[ph.id % total] = 0;
		ph.vars->arr_fk[(ph.id % total) + 1] = 0;
		pthread_mutex_unlock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_unlock(&ph.vars->forks[(ph.id % total) + 1]);
	}
	else if ((ph.id % 2) == 1)
	{
		pthread_mutex_lock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_lock(&ph.vars->forks[(ph.id % total) - 1]);
		ph.vars->arr_fk[ph.id % total] = 0;
		ph.vars->arr_fk[(ph.id % total) - 1] = 0;
		pthread_mutex_unlock(&ph.vars->forks[ph.id % total]);
		pthread_mutex_unlock(&ph.vars->forks[(ph.id % total) - 1]);
	}
}
