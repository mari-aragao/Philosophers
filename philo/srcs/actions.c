/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:02:46 by maragao           #+#    #+#             */
/*   Updated: 2023/01/10 18:25:12 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_permission(t_philo *ph)
{
	long int	actual_time;

	actual_time = get_time();
	if (ph->vars->total % 2 == 0)
		return (0);
	if ((actual_time - ph->st_time < ph->vars->time_to_eat) && ph->meal_cntr == 0)
		return (0);
	else if (actual_time - ph->st_time > ph->vars->time_to_eat)
		return (0);
	return (-1);
}

void	loop_one(t_philo *ph, int fork_one)
{
	while (1)
	{
		pthread_mutex_lock(&ph->vars->forks[fork_one]);
		if (ph->vars->arr_fk[fork_one] == 0)
		{
			ph->vars->arr_fk[fork_one] = 1;
			pthread_mutex_unlock(&ph->vars->forks[fork_one]);
			break ;
		}
		pthread_mutex_unlock(&ph->vars->forks[fork_one]);
		if (is_dead(ph) == -1)
			break ;
	}
}

	void	loop_two(t_philo *ph, int fork_two)
{
	while(1)
	{
		if (is_dead(ph) == -1)
			break ;
		pthread_mutex_lock(&ph->vars->forks[fork_two]);
		if (ph->vars->arr_fk[fork_two] == 0)
		{
			ph->vars->arr_fk[fork_two] = 1;
			print(ph, FORK);
			print(ph, FORK);
			pthread_mutex_unlock(&ph->vars->forks[fork_two]);
			break ;
		}
		pthread_mutex_unlock(&ph->vars->forks[fork_two]);
	}
}

void	take_forks(t_philo *ph)
{
	int	total;
	int	fork_one;
	int	fork_two;

	total = ph->vars->total;
	fork_one = ph->id % total;
	if (ph->id % 2 == 0 || ph->vars->total % 2 == 1)
		fork_two = (ph->id + 1) % total;
	else
		fork_two = (ph->id - 1) % total;
/*	while (1)
	{
		pthread_mutex_lock(&ph->vars->forks[fork_one]);
		if (ph->vars->arr_fk[fork_one] == 0)
		{
			ph->vars->arr_fk[fork_one] = 1;
			pthread_mutex_unlock(&ph->vars->forks[fork_one]);
			break ;
		}
		pthread_mutex_unlock(&ph->vars->forks[fork_one]);
		if (is_dead(ph) == -1)
			break ;
*/		loop_one(ph, fork_one);
/*	}
	while (1)
	{
		if (is_dead(ph) == -1)
			break ;
		pthread_mutex_lock(&ph->vars->forks[fork_two]);
		if (ph->vars->arr_fk[fork_two] == 0)
		{
			ph->vars->arr_fk[fork_two] = 1;
			print(ph, FORK);
			print(ph, FORK);
			pthread_mutex_unlock(&ph->vars->forks[fork_two]);
			break ;
		}
	pthread_mutex_unlock(&ph->vars->forks[fork_two]);
*/	loop_two(ph, fork_two);
//	}
}

void	eating(t_philo *ph)
{
	if (checker(ph) == 1)
		return ;
	print(ph, EAT);
	ph->last_meal = get_time();
	usleep(ph->vars->time_to_eat * 1000);
	ph->meal_cntr += 1;
}

void	sleeping(t_philo *ph)
{
	if (checker(ph) == 1)
		return ;
	print(ph, SLEEP);
	usleep(ph->vars->time_to_sleep * 1000);
}

void	thinking(t_philo *ph)
{
	if (checker(ph) == 1)
		return ;
	print(ph, THINK);
}

int	is_dead(t_philo *ph)
{
	long int	actual_time;

	actual_time = get_time();
	if (checker(ph) == 1)
		return (-1);
	if ((actual_time - ph->last_meal) > ph->vars->time_to_die)
	{
		ph->die = 1;
		pthread_mutex_lock(&ph->vars->m_checker);
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

	if (checker(ph) == 1)
		return ;
	total = ph->vars->total;
	fork_one = ph->id % total;
	if (ph->id % 2 == 0 || ph->vars->total % 2 == 1)
		fork_two = (ph->id + 1) % total;
	else
		fork_two = (ph->id - 1) % total;
	pthread_mutex_lock(&ph->vars->forks[fork_one]);
	pthread_mutex_lock(&ph->vars->forks[fork_two]);
	ph->vars->arr_fk[fork_one] = 0;
	ph->vars->arr_fk[fork_two] = 0;
	pthread_mutex_unlock(&ph->vars->forks[fork_one]);
	pthread_mutex_unlock(&ph->vars->forks[fork_two]);
}
