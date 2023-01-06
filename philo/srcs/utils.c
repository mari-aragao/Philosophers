/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:31:20 by maragao           #+#    #+#             */
/*   Updated: 2023/01/06 17:22:20 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != 0 && (s[i] >= 48 && s[i] <= 57))
		res = (res * 10) + (s[i++] - 48);
	if (s[0] == '-')
		res = -res;
	return (res);
}

int	print(t_philo *ph, int action)
{
	long int	actual_time;

	actual_time = get_time() - ph->st_time;
	pthread_mutex_lock(&ph->vars->print);
		if (action == FORK)
			printf("%ld %i has taken a fork\n", actual_time, ph->id);
		if (action == EAT)
			printf("%ld %d is eating\n", actual_time, ph->id);
		if (action == SLEEP)
			printf("%ld %d is sleeping\n", actual_time, ph->id);
		if (action == THINK)
			printf("%ld %d is thinking\n", actual_time, ph->id);
		if (action == DIE)
			printf("%ld %d died\n", actual_time, ph->id);
	pthread_mutex_unlock(&ph->vars->print);
	return (0);
}

int	check_meals(t_philo *ph)
{
	pthread_mutex_lock(&ph->vars->m_checker);
	if (ph->meal_cntr < ph->vars->meals_to_make && ph->vars->checker == 0)
	{
		pthread_mutex_unlock(&ph->vars->m_checker);
		return (0);
	}
	if (ph->vars->meals_to_make == -1 && ph->vars->checker == 0)
	{
		pthread_mutex_unlock(&ph->vars->m_checker);
		return (0);
	}
	pthread_mutex_unlock(&ph->vars->m_checker);
	return (-1);
}

void	destroy_all(int total, t_philo *ph)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&ph->vars->print);
	pthread_mutex_destroy(&ph->vars->m_checker);
	while (i < total)
	{
		pthread_mutex_destroy(&ph->vars->forks[i]);
		i++;
	}
	free(ph->vars->arr_fk);
	free(ph->vars->forks);
	free(ph->vars);
	free(ph);
}
