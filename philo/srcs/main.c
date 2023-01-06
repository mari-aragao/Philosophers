/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:09:49 by maragao           #+#    #+#             */
/*   Updated: 2022/12/21 13:28:29 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	check_meals(t_philo *ph)
{
	if (ph->meal_cntr < ph->vars->meals_to_make && ph->vars->checker == 0)
		return (0);
	if (ph->vars->meals_to_make == -1 && ph->vars->checker == 0)
		return (0);
	return (-1);
}

void	*routine_for_one(void *ph)
{
	t_philo *ph2;

	ph2 = (t_philo *)ph;
	count_time(ph2->vars->time_to_die);
	print(ph2, DIE);
	return ((void *)NULL);
}

void	*routine(void *ph)
{
	t_philo	*ph2;

	ph2 = (t_philo *)ph;
	if (ph2->id % 2 == 0)
		usleep(10000);
	while (check_meals(ph2) == 0)
	{
		while(take_forks(ph2) == -1 && ph2->vars->checker == 0)
		{	
			if (is_dead(ph2) == -1)
				return ((void *)NULL);
		}
		if (ph2->vars->checker == 0)
			eating(ph2);
		if (ph2->vars->checker == 0)
			drop_forks(ph2);
		if (ph2->vars->checker == 0)
			print(ph2, THINK);
	}
	return ((void *)NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*ph;

	if (all_checks(argc, argv) == -1)
		return(-1);
	ph = init_all(argc, argv);
	if (ph == NULL)
		return(-1);
	init_threads(ph);
//	destroy_all(ph-vars->total, ph);
	return (0);	
}
