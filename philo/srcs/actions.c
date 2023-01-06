#include "philo.h"

int	take_forks(t_philo *ph)
{
	int	total;
	int	fork_one;
	int	fork_two;

	total = ph->vars->total;
	fork_one = ph->id % total;
	fork_two = (ph->id - 1) % total;
	if (ph->vars->arr_fk[fork_one] == 0 && ph->vars->arr_fk[fork_two] == 0)
	{
		pthread_mutex_lock(&ph->vars->forks[fork_one]);
		pthread_mutex_lock(&ph->vars->forks[fork_two]);
		ph->vars->arr_fk[fork_one] = 1;
		ph->vars->arr_fk[fork_two] = 1;
		print(ph, FORK);
		print(ph, FORK);
		pthread_mutex_unlock(&ph->vars->forks[fork_one]);
		pthread_mutex_unlock(&ph->vars->forks[fork_two]);
		return (0);
	}
	return (-1);
}

void	eating(t_philo *ph)
{
	if (is_dead(ph) == -1)
		return ;
	print(ph, EAT);
	ph->last_meal = get_time();
	count_time(ph->vars->time_to_eat);
	ph->meal_cntr += 1;
}

void	sleeping(t_philo *ph)
{
	print(ph, SLEEP);
	count_time(ph->vars->time_to_sleep);
}

int	is_dead(t_philo *ph)
{
	long int	actual_time;

	actual_time = get_time();
	if ((actual_time - ph->last_meal) > ph->vars->time_to_die)
	{
		pthread_mutex_lock(&ph->vars->m_checker);
		ph->die = 1;
		if (ph->vars->checker == 0)
		{	
			ph->vars->checker = 1;
			print(ph, DIE);
		}
		pthread_mutex_unlock(&ph->vars->m_checker);
		return (-1);
	}
	return (0);
}

void	drop_forks(t_philo *ph)
{
	int	total;
	int	fork_one;
	int	fork_two;

	total = ph->vars->total;
	fork_one = ph->id % total;
	fork_two = (ph->id - 1) % total;
	pthread_mutex_lock(&ph->vars->forks[fork_one]);
	pthread_mutex_lock(&ph->vars->forks[fork_two]);
	ph->vars->arr_fk[fork_one] = 0;
	ph->vars->arr_fk[fork_two] = 0;
	pthread_mutex_unlock(&ph->vars->forks[fork_one]);
	pthread_mutex_unlock(&ph->vars->forks[fork_two]);
	sleeping(ph);
}
