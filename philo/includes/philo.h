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

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK 	3
# define DIE 	4

typedef	struct	s_vars
{
	int		total;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_to_make;
	int		checker;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_checker;
	int		*arr_fk;
}		t_vars;

typedef struct	s_philo
{
	pthread_t	th;
	int		id;
	int		meal_cntr;
	int		died;
	long int	st_time; //start time
	long int	last_meal;
	t_vars		*vars;

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
t_philo	*init_all(int argc, char **argv);
t_philo	*init_philo(int argc, char **argv);
t_philo	*init_parameters(int argc, char **argv, t_philo *philo, int total);
t_vars	*init_vars(int argc, char **argv, int total);
t_vars	*init_mutex(int total);
int	init_threads(t_philo *ph);
void	destroy_all(int total, t_philo *vars);
long int	get_time(void);
int	print(t_philo *ph, int action);
void	*routine(void *ph);
int	take_forks(t_philo *ph);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);
int	is_dead(t_philo *ph);
void	drop_forks(t_philo *ph);
void	count_time(long int tm);
int	checker(t_philo *ph);
int	check_meals(t_philo *ph);

#endif
