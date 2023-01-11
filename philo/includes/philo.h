/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:13:01 by maragao           #+#    #+#             */
/*   Updated: 2023/01/10 18:22:17 by maragao          ###   ########.rio      */
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
	int		prt;
	pthread_t	monitoring;
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
	int		stop;
	int		die;
	long int	st_time;
	long int	last_meal;
	t_vars		*vars;

}		t_philo;

//main.c
int	main(int argc, char **argv);
void	*one_philo(void *ph);
void	*philo(void *ph);

//utils.c
int	ft_atoi(char *s);
int	print(t_philo *ph, int action);
int	check_meals(t_philo *ph);
void	destroy_all(int total, t_philo *vars);

//checks.c
int	all_checks(int argc, char **argv);
int	check_number(char **argv);
int	check_bigger_than_zero(char **argv);

//init.c
t_philo	*init_all(int argc, char **argv);
t_vars	*init_vars(int argc, char **argv, int total);
t_philo	*init_parameters(int argc, char **argv, t_philo *philo, int total);
int	init_threads(t_philo *ph);

//
long int	get_time(void);
void	count_time(long int tm);

void	take_one(t_philo *ph, int for_one);
void	take_two(t_philo *ph, int fork_two);
void	take_forks(t_philo *ph);
void	eating(t_philo *ph);
void	thinking(t_philo *ph);
void	sleeping(t_philo *ph);
int	is_dead(t_philo *ph);
void	drop_forks(t_philo *ph);
int	checker(t_philo *ph);
int		check_permission(t_philo *ph);
void	*monitoring(void *ph2);

#endif
