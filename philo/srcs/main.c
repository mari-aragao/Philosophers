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

int	main(int argc, char **argv)
{
	t_philo		*ph;
	t_mutex		*mutex;

	if (all_checks(argc, argv) == -1)
		return(-1);
	ph = init_philo(argc, argv);
	if (ph == NULL)
		return(-1);
	mutex = init_mutex();
	if (!mutex)
		return (-1);
	pthread_mutex_lock(&mutex->print);
/*	
	int i = 0;

	while(i < ph[i].total_philos)
	{
	printf("\n\n");
	printf("philo_id = %i\n", ph[i].philo_id);
	printf("total_philos = %i\n", ph[i].total_philos);
	printf("time_to_die = %i\n", ph[i].time_to_die);
	printf("time_to_eat = %i\n", ph[i].time_to_eat);
	printf("time_to_sleep = %i\n", ph[i].time_to_sleep);
	printf("meals_to_make = %i\n", ph[i].meals_to_make);
	printf("meal_counter = %i\n", ph[i].meal_counter);
	printf("stop = %i\n", ph[i].stop);
	printf("\n\n");
	pthread_mutex_lock(&mutex->forks);
	ph[i].arr_forks[i] = 1;
	pthread_mutex_unlock(&mutex->forks);
	printf("arr_forks[%i] = %i\n", i, ph[i].arr_forks[i]);
	pthread_mutex_unlock(&mutex->print);
	i++;
	}
	destroy_mutex(mutex);
	destroy_philo(ph);
*/
	return(0);	
}
