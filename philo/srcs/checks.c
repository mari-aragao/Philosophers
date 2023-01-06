/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:11:32 by maragao           #+#    #+#             */
/*   Updated: 2022/12/21 12:56:11 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	all_checks(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{	
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (check_number(argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (check_bigger_than_zero(argv) == -1)
	{
		write(2, "Error\n", 11);
		return (-1);
	}
	return (0);
}

int	check_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_bigger_than_zero(char **argv)
{
	int	i;
	int	temp;

	i = 1;
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (temp < 1)
			return (-1);
		i++;
	}
	return (0);
}
