/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:39 by maragao           #+#    #+#             */
/*   Updated: 2023/01/11 16:42:22 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *ph)
{
	if (checker(ph) == 1)
		return ;
	print(ph, EAT);
	ph->last_meal = get_time();
	usleep(ph->vars->time_to_eat * 1000);
	ph->meal_cntr += 1;
}

void	sleeping(t_philo *ph)
{
	if (checker(ph) == 1)
		return ;
	print(ph, SLEEP);
	usleep(ph->vars->time_to_sleep * 1000);
}

void	thinking(t_philo *ph)
{
	if (checker(ph) == 1)
		return ;
	print(ph, THINK);
}
