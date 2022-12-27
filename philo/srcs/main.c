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

int     init_threads(t_all *all)
{
        int i;

        i = 0;
        while (i < all->ph->total)
        {
                if (pthread_create(&all->ph[i].th, NULL, &routine, (void *)all) != 0)
                {
                        printf("Failed to create thread");
                        return (-1);
                }
                printf("\nThread %d has started\n", i);
//		pthread_detach(all->ph[i].th);
                i++;
        }
        i = 0;
        while (i < all->ph->total)
        {
                if (pthread_join(all->ph[i].th, NULL) != 0)
                {
                        printf("Failed to join thread");
                        return (-1);
                }
                i++;
       }
       return (0);
}

void	*routine(void *all)
{
	t_all	*all2;

	all2 = (t_all *)all;
	if (all2->ph->id % 2 == 0)
		usleep(200);
	take_forks(all2);
	print(all, FORK);
	eating(all2);
	print(all, EAT);
	drop_forks(all2);
	print(all, SLEEP);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_all		*all;

//	if (all_checks(argc, argv) == -1)
//		return(-1);
	all = init_all(argc, argv);
	if (all == NULL)
		return(-1);
	
/*	int i = 0;

	while(i < all->ph[i].total)
	{
	printf("\n\n");
	printf("philo_id = %i\n", all->ph[i].id);
	printf("total = %i\n", all->ph[i].total);
	printf("time_to_die = %i\n", all->ph[i].time_to_die);
	printf("time_to_eat = %i\n", all->ph[i].time_to_eat);
	printf("time_to_sleep = %i\n", all->ph[i].time_to_sleep);
	printf("meals_to_make = %i\n", all->ph[i].meals_to_make);
	printf("meal_counter = %i\n", all->ph[i].meal_counter);
	printf("stop = %i\n", all->ph[i].stop);
	printf("\n\n");
	i++;
	}
	
*/	
	init_threads(all);

	int i = 0;
	while (i < all->ph[i].total)
	{
		printf("\n\nmutex_arr_forks[%i] = %i", i, all->mutex->arr_forks[i]);
		i++;
	}
	printf("\n000xxx000\n");
	//destroy_mutex((all)->ph->total, (all)->mutex);
	//destroy_philo((all)->ph);

	return(0);	
}
