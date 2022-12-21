/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:09:49 by maragao           #+#    #+#             */
/*   Updated: 2022/12/21 12:54:53 by maragao          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (all_checks(argc, argv) == -1)
		return(-1);
	init_vars(argc, argv, &vars);

	printf("n_philo = %d\n", vars.n_philo);
	printf("die = %d\n", vars.die);
	printf("eat = %d\n", vars.eat);
	printf("sleep = %d\n", vars.sleep);
	printf("times_to_eat = %d\n", vars.times_to_eat);
	return(0);	
}
