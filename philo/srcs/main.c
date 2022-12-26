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

t_mutex	*init_mutex(void)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->forks, NULL);
	return (mutex);
}

void	destroy_mutex(t_mutex *mutex)
{
	pthread_mutex_destroy(&mutex->print);
	pthread_mutex_destroy(&mutex->forks);
	free(mutex);
}

void	destroy_philo(t_philo *ph)
{
	int i;

	i = 0;
	while (i < ph[i].total_philos)
	{
		free(ph[i].arr_forks);
		i++;
	}
	free(ph);
}

t_philo	*init_philo(int argc, char **argv)
{
	int	total;
	t_philo	*ph;

	total = ft_atoi(argv[1]);
//	(void)argc;
//	(void)argv;
//	total = 5;
	ph = (t_philo *)malloc(sizeof(t_philo) * total);
	if (!ph)
		return (NULL);
	init_parameters(argc, argv, ph, total);
	return(ph);
}

t_philo	*init_parameters(int argc, char **argv, t_philo *ph, int total)
{
	int i;
	int j;
	
	i = 0;
	while (i < total)
	{
		ph[i].philo_id = i + 1;
		ph[i].total_philos = ft_atoi(argv[1]);
		ph[i].time_to_die = ft_atoi(argv[2]);
		ph[i].time_to_eat = ft_atoi(argv[3]);
		ph[i].time_to_sleep = ft_atoi(argv[4]);
		ph[i].meals_to_make = -1;
		if(argc == 6)
			ph[i].meals_to_make = ft_atoi(argv[5]);
		ph[i].meal_counter = 0;
		ph[i].stop = 0;
		ph[i].arr_forks = (int *)malloc(sizeof(int) * ph[i].total_philos);
		j = 0;
		while(j < ph[i].total_philos)
			ph[i].arr_forks[j++] = 0;
		i++;
	}
	return (ph);
}

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
	return(0);	
}
