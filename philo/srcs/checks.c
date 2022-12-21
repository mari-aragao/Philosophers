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
	if (argc <= 4 || argc >= 7)
		return (-1);
	if (check_positive_number(argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	check_positive_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(is_digit(argv[i][j])) && argv[i][j] != '+')
				return (-1);
			if (j != 0 && (argv[i][j] == '+'))
				return (-1);
			if (j == 0 && argv[i][j] == '+' && (!(is_digit(argv[i][1]))))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
