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
# include <sys/time.h>
# include <stdio.h>

typedef struct	s_philo
{
	int		philo_id;
	int		total_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_to_make;
	int		meal_counter;
	int		stop;
	int		*arr_forks;
	int		f_left;
	int		f_right;
	pthread_t	philo;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

}		t_philo;

/*
 stop = 0 - ta de boa
 stop = 1 - algum filosofo morreu
 stop = 2 - n times to eat atingido

*/

int	main(int argc, char **argv);
int	is_digit(int c);
int	ft_atoi(char *s);
int	all_checks(int argc, char **argv);
int	check_positive_number(char **argv);
int	check_bigger_than_zero(char **argv);
t_philo	*init_vars(int argc, char **argv);
t_philo	*init_parameters(int argc, char **argv, t_philo *philo, int total);

#endif
