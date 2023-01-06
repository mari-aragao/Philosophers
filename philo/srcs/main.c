/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:09:49 by maragao           #+#    #+#             */
/*   Updated: 2023/01/06 18:48:21 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (ph2->id % 2 == 0)
		usleep(100);
	while (check_meals(ph2) == 0)
	{
		while (take_forks(ph2) == -1 && ph2->vars->checker == 0)
		{	
			if (is_dead(ph2) == -1)
				return ((void *) NULL);
		}
		if (ph2->vars->checker == 0)
			eating(ph2);
		if (ph2->vars->checker == 0)
			drop_forks(ph2);
		if (ph2->vars->checker == 0)
			print(ph2, THINK);
		if (ph2->vars->total % 2 == 1)
			usleep(1000);
		usleep(500);
		
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
