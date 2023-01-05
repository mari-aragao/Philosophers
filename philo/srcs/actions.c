#include "philo.h"

int	take_forks(t_philo *ph)
{
	int total;
	int fork_one;
	int fork_two;

	total = ph->vars->total;
	fork_one = ph->id % total;
//	if ((ph->id % 2 == 0) || total % 2 == 1)
		fork_two = ph->id % total - 1;
//	else if ((ph->id % 2) == 1) 
//		fork_two = ph->id % total + 1;
	if (ph->vars->arr_fk[fork_one] == 0 && ph->vars->arr_fk[fork_two] == 0)
	{
		pthread_mutex_lock(&ph->vars->forks[fork_one]);
		pthread_mutex_lock(&ph->vars->forks[fork_two]);
		ph->vars->arr_fk[fork_one] = 1;
		ph->vars->arr_fk[fork_two] = 1;
		pthread_mutex_unlock(&ph->vars->forks[fork_one]);
		pthread_mutex_unlock(&ph->vars->forks[fork_two]);
		print(ph, FORK);
		print(ph, FORK);
		return (0);
	}
	return (-1);
}

void	eating(t_philo *ph)
{
	print(ph, EAT);
	usleep(ph->vars->time_to_eat * 1000);
	ph->last_meal = get_time();
	ph->meal_cntr += 1; 
}

void	sleeping(t_philo *ph)
{
	print(ph, SLEEP);
	usleep(ph->vars->time_to_sleep * 1000);
}

void	thinking(t_philo *ph)
{
	print(ph, THINK);
	usleep(1000);
}

int	is_dead(t_philo *ph)
{
	long int actual_time;

	if (ph->vars->checker == 1)
		return (-1);
	actual_time = get_time();
	if ((actual_time - ph->last_meal) > ph->vars->time_to_die && checker(ph) == 0)
	{
		ph->died = 1; 
		if (ph->vars->checker == 0)
		{	
			pthread_mutex_lock(&ph->vars->m_checker);
			ph->vars->checker = 1;
			print(ph, DIE);
			usleep (15000);
			pthread_mutex_unlock(&ph->vars->m_checker);
		}
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
//	if ((ph->id % 2) == 0 || total % 2 == 1)
		fork_two = ph->id % total - 1;
//	else if ((ph->id % 2) == 1) 
//		fork_two = ph->id % total + 1;
	pthread_mutex_lock(&ph->vars->forks[fork_one]);
	pthread_mutex_lock(&ph->vars->forks[fork_two]);
	ph->vars->arr_fk[fork_one] = 0;
	ph->vars->arr_fk[fork_two] = 0;
	pthread_mutex_unlock(&ph->vars->forks[fork_one]);
	pthread_mutex_unlock(&ph->vars->forks[fork_two]);
}

int	checker(t_philo *ph)
{
	if (ph->vars->checker == 1)
		return (-1);
	return (0);
}
