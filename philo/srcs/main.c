/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:01:45 by maragao           #+#    #+#             */
/*   Updated: 2023/01/10 18:04:08 by maragao          ###   ########.rio      */
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
	while (check_meals(ph2) == 0)
	{
		take_forks(ph2);
		if (is_dead(ph2) == -1)
			return ((void *) NULL);
		eating(ph2);
		drop_forks(ph2);
		sleeping(ph2);
		thinking(ph2);
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
