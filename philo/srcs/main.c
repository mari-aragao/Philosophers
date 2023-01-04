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

void	*routine(void *ph)
{
	t_philo	*ph2;

	ph2 = (t_philo *)ph;
	if (ph2->id % 2 == 0)
		usleep(10000);
	while (ph2->meal_cntr < ph2->vars->meals_to_make && checker(ph2) == 0)
	{
		while(take_forks(ph2) == -1 && checker(ph2) == 0)
		{	
			if (is_dead(ph2) == -1)
				return ((void *)NULL);
		}
		if (checker(ph2) == 0)
			eating(ph2);
		if (checker(ph2) == 0)
			drop_forks(ph2);
		if (checker(ph2) == 0)
			thinking(ph2);
		if (ph2->vars->total % 2 == 1 && ph2->id == 1)
			usleep(100000);
		else
			usleep(1000);
	}
	return ((void *)NULL);
}

/*
	pthread_mutex_lock(&ph2.vars->print);
	int i = 0;
	while (i < ph2.vars->total)
	{
		printf("\narr_fk[%i] = %i", i, ph2.vars->arr_fk[i]);
		i++;
	}
	pthread_mutex_unlock(&ph2.vars->print);
*/

int	main(int argc, char **argv)
{
	t_philo		*ph;

//	if (all_checks(argc, argv) == -1)
//		return(-1);
	ph = init_all(argc, argv);
	if (ph == NULL)
		return(-1);
/*
	int i = 0;

	while(i < 5)
	{
	printf("\n\n");
	printf("PHILOS:\n");
	printf("id = %i\n", ph[i].id);
	printf("meal_cntr = %i\n", ph[i].meal_cntr);
	printf("stop = %i\n", ph[i].stop);
	printf("st_time = %ld\n", ph[i].st_time);
	printf("last_meal = %ld\n", ph[i].last_meal);
	
	printf("VARS:\n");
	printf("total = %i\n", ph[i].vars->total);
	printf("time_to_die = %i\n", ph[i].vars->time_to_die);
	printf("time_to_eat = %i\n", ph[i].vars->time_to_eat);
	printf("time_to_sleep = %i\n", ph[i].vars->time_to_sleep);
	printf("meals_to_make = %i\n", ph[i].vars->meals_to_make);
	int j = 0;
	while (j < 5)
	{
		printf("\n\nmutex_arr_forks[%i] = %i", j, ph[i].vars->arr_fk[j]);
		j++;
	}
	printf("\n\n");
	i++;
	}
	
*/
	init_threads(ph);
	destroy_all(ph->vars->total, ph);
	return (0);	
}

