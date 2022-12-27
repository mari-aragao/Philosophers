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

void	*routine(void *all)
{
	printf("\nRoutine\n");
	take_forks((t_all *) all);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_all		*all;

	if (all_checks(argc, argv) == -1)
		return(-1);
	all = init_all(argc, argv);
	if (all == NULL)
		return(-1);
/*int i = 0;

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
	destroy_mutex((all)->ph->total, (all)->mutex);
	destroy_philo((all)->ph);

*/	return(0);	
}
