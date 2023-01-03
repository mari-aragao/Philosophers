#include "philo.h"

int	take_forks(t_philo *ph)
{
	int total;
	int fork_one;
	int fork_two;

	total = ph->vars->total;
	fork_one = ph->id % total;
	if ((ph->id % 2) == 0)
		fork_two = ph->id % total + 1;
	else if ((ph->id % 2) == 1)
		fork_two = ph->id % total - 1;
	if (ph->vars->arr_fk[fork_one] == 0 && ph->vars->arr_fk[fork_two] == 0)
	{
		pthread_mutex_lock(&ph->vars->forks[fork_one]);
		pthread_mutex_lock(&ph->vars->forks[fork_two]);
		ph->vars->arr_fk[fork_one] = 1;
		ph->vars->arr_fk[fork_two] = 1;
		pthread_mutex_unlock(&ph->vars->forks[fork_one]);
		pthread_mutex_unlock(&ph->vars->forks[fork_two]);
		return (0);
	}
	return (-1);
}

void	eating(t_philo *ph)
{
	count_time(ph->vars->time_to_eat);
	ph->last_meal = get_time();
	ph->meal_cntr += 1; 
}

void	sleeping(t_philo *ph)
{
	count_time(ph->vars->time_to_sleep);
}

int	is_dead(t_philo *ph)
{
	long int actual_time;

	actual_time = get_time();
	if ((actual_time - ph->last_meal) > ph->vars->time_to_die)
	{
		ph->died = 1; 
		return (-1);
	}
	return (0);
}

void	drop_forks(t_philo *ph)
{
	int total;
	int fork_one;
	int fork_two;

	total = ph->vars->total;
	fork_one = ph->id % total;
	if ((ph->id % 2) == 0)
		fork_two = ph->id % total + 1;
	else if ((ph->id % 2) == 1)
		fork_two = ph->id % total - 1;
	pthread_mutex_lock(&ph->vars->forks[fork_one]);
	pthread_mutex_lock(&ph->vars->forks[fork_two]);
	ph->vars->arr_fk[fork_one] = 0;
	ph->vars->arr_fk[fork_two] = 0;
	pthread_mutex_unlock(&ph->vars->forks[fork_one]);
	pthread_mutex_unlock(&ph->vars->forks[fork_two]);
}
