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

t_philo	*init_philo(int argc, char **argv)
{
	int	i;
	int	total;
	t_philo	*ph;

	total = ft_atoi(argv[1]);
	ph = (t_philo *)malloc(sizeof(t_philo) * total);
	if (!ph)
		return (NULL);
	i = 0;
	while (i < total)
	{
		init_parameters(argc, argv, i, &ph[i]);
		i++;
	}
	return(ph);
}

void	init_parameters(int argc, char **argv, int id, t_philo *ph)
{
	int i;

	ph->philo_id = id;
	ph->total_philos = ft_atoi(argv[1]);
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	ph->meals_to_make = -1;
	if(argc == 6)
		ph->meals_to_make = ft_atoi(argv[5]);
	ph->meal_counter = 0;
	ph->stop = 0;
	ph->arr_forks = (int *)malloc(sizeof(int) * ph->total_philos);

	i = 0;
	while(i < ph->total_philos)
		ph->arr_forks[i++] = 0;
	ph->f_left = 0;
	ph->f_right = 0;
}

int	main(int argc, char **argv)
{
	t_philo		*ph;

	if (all_checks(argc, argv) == -1)
		return(-1);
	ph = init_philo(argc, argv);
	if (ph == NULL)
		return(-1);
	printf("philo_id = %i\n", ph->philo_id);
	printf("total_philos = %i\n", ph->total_philos);
	printf("time_to_die = %i\n", ph->time_to_die);
	printf("time_to_eat = %i\n", ph->time_to_eat);
	printf("time_to_sleep = %i\n", ph->time_to_sleep);
	printf("meals_to_make = %i\n", ph->meals_to_make);
	printf("meal_counter = %i\n", ph->meal_counter);
	printf("time_to_sleep = %i\n", ph->time_to_sleep);
	printf("stop = %i\n", ph->stop);
	printf("f_left = %i\n", ph->f_left);
	printf("f_right = %i\n", ph->f_right);
	int i = 0;
	printf("\n\n");
	while (i < ph->total_philos)
	{
		printf("arr_forks[%i] = %i\n", i, ph->arr_forks[i]);
		i++;
	}
	return(0);	
}
