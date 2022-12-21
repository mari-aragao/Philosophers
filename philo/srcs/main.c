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

void	init_vars(int argc, char **argv, t_vars *vars)
{
	vars->n_philo = ft_atoi(argv[1]);
	vars->die = ft_atoi(argv[2]);
	vars->eat = ft_atoi(argv[3]);
	vars->sleep = ft_atoi(argv[4]);

	if (argc == 5)
		vars->times_to_eat = -1;
	else if(argc == 6)
		vars->times_to_eat = ft_atoi(argv[5]);
}

void	*start(void *i)
{
	int philo;

	philo = *(int *)i;
	printf("Philosopher %i says hello!\n", philo);
	free (i);
	return ((void *) NULL);
}

int	main(int argc, char **argv)
{
	int		i;
	t_vars		vars;
	pthread_t	philo[5];

	if (all_checks(argc, argv) == -1)
		return(-1);
	init_vars(argc, argv, &vars);
	i = 0;
	while (i < vars.n_philo)
	{
		int *temp = malloc(sizeof(int));
		if (!temp)
			return (0);
		*temp = i;
		pthread_create(&philo[i], NULL, &start, temp);
		i++;
	}
/*	printf("n_philo = %d\n", vars.n_philo);
	printf("die = %d\n", vars.die);
	printf("eat = %d\n", vars.eat);
	printf("sleep = %d\n", vars.sleep);
	printf("times_to_eat = %d\n", vars.times_to_eat);
*/	return(0);	
}
