/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:13:01 by maragao           #+#    #+#             */
/*   Updated: 2022/12/21 12:54:01 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct	s_vars
{
	int	n_philo;
	int	die;
	int	eat;
	int	sleep;
	int	times_to_eat;

}		t_vars;

typedef struct	s_philo
{
	int	philo;
	t_vars	vars;
	
}		t_philo;

int	main(int argc, char **argv);
int	is_digit(int c);
int	ft_atoi(char *s);
int	all_checks(int argc, char **argv);
int	check_positive_number(char **argv);

#endif
