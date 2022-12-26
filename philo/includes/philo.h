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

typedef	struct	s_mutex
{
	pthread_mutex_t	print;
	pthread_mutex_t	forks;
}		t_mutex;

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
	pthread_t	philo;
	long int	start;
	long int	actual_time;
	long int	last_meal;
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
t_philo	*init_philo(int argc, char **argv);
t_philo	*init_parameters(int argc, char **argv, t_philo *philo, int total);
t_mutex	*init_mutex(void);
void	destroy_mutex(t_mutex *mutex);
void	destroy_philo(t_philo *ph);
long int	get_time(void);

#endif
