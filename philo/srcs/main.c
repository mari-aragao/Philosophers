/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:01:45 by maragao           #+#    #+#             */
/*   Updated: 2023/01/11 16:57:10 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(t_philo *ph)
{
	pthread_mutex_lock(&ph->vars->m_checker);
	if (ph->vars->checker == 0)
	{
		pthread_mutex_unlock(&ph->vars->m_checker);
		return (0);
	}
	if (ph->vars->checker == 1)
	{
		pthread_mutex_unlock(&ph->vars->m_checker);
		return (1);
	}
	pthread_mutex_unlock(&ph->vars->m_checker);
	return (-1);
}

void	*monitoring(void *ph2)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)ph2;
	while (1)
	{
		i = -1;
		while (++i < ph->vars->total)
		{
			if (check_meals(ph) == 1)
				return ((void *) NULL);
			if ((get_time() - ph[i].last_meal) > ph[i].vars->time_to_die
				&& ph[i].stop != 1)
			{
				ph[i].die = 1;
				pthread_mutex_lock(&ph[i].vars->m_checker);
				ph[i].vars->checker = 1;
				print(&ph[i], DIE);
				pthread_mutex_unlock(&ph[i].vars->m_checker);
				return ((void *) NULL);
			}	
			usleep(100);
		}
	}
	return ((void *) NULL);
}

void	*one_philo(void *ph)
{
	t_philo	*ph2;

	ph2 = (t_philo *)ph;
	usleep(ph2->vars->time_to_die * 1000);
	printf("%ld %i died\n", (get_time() - ph2->st_time), ph2->id);
	return ((void *) NULL);
}

void	*philo(void *ph)
{
	t_philo	*ph2;

	ph2 = (t_philo *)ph;
	if (ph2->id % 2 == 1)
		usleep(100 * (ph2->vars->total / 2));
	while (checker(ph2) == 0)
	{
		take_forks(ph2);
		eating(ph2);
		drop_forks(ph2);
		sleeping(ph2);
		thinking(ph2);
		if (ph2->meal_cntr == ph2->vars->meals_to_make)
		{
			ph2->stop = 1;
			return ((void *) NULL);
		}
	}
	return ((void *) NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*ph;

	if (all_checks(argc, argv) == -1)
		return (-1);
	ph = init_all(argc, argv);
	if (ph == NULL)
		return (-1);
	init_threads(ph);
	destroy_all(ph->vars->total, ph);
	return (0);
}
