#include "philo.h"

t_philo	*init_all(int argc, char **argv)
{
	int	total;
	t_philo	*ph;

	total = ft_atoi("5"); ///////
	ph = (t_philo *)malloc(sizeof(t_philo) * total);
	if (!ph)
		return (NULL);
	ph = init_parameters(argc, argv, ph, total);
	return (ph);
}

t_vars *init_vars(int argc, char **argv, int total)
{
	int	i;
        t_vars *vars;

        vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->total = ft_atoi("5"); //////
	vars->time_to_die = ft_atoi("200"); /////
	vars->time_to_eat = ft_atoi("200"); //////
	vars->time_to_sleep = ft_atoi("20"); /////
	vars->meals_to_make = 3; ///
	vars->checker = 0;
	if (argc == 6)
		vars->meals_to_make = ft_atoi(argv[5]);
	vars->forks = malloc(sizeof(pthread_mutex_t) * total);
	if (!vars->forks)
		return (NULL);
	vars->arr_fk = malloc(sizeof(int) * total);
	if (!vars->arr_fk)
		return (NULL);
        pthread_mutex_init(&vars->print, NULL);
        pthread_mutex_init(&vars->vulture, NULL);
	i = 0;
	while(i < total)
	{
        	pthread_mutex_init(&vars->forks[i], NULL);
		vars->arr_fk[i] = 0;
		i++;
	}
        return (vars);
}

t_philo *init_parameters(int argc, char **argv, t_philo *ph, int total)
{
        int i;
	t_vars	*va;

	va = init_vars(argc, argv, total);
        i = 0;
        while (i < total)
        {
                ph[i].id = i + 1;
                ph[i].meal_cntr = 0;
                ph[i].died = 0;
		ph[i].st_time = get_time();
		ph[i].last_meal = get_time();
		ph[i].vars = va;
                i++;
        }
        return (ph);
}

void	*check_dead(void *ph)
{
	t_philo *ph2;
	int i;

	ph2 = (t_philo *)ph;
	while (1)
	{
		i = 0;
		while (i < ph2[0].vars->total)
		{
			printf("\nto vendo\n");
			if (ph2[i].died == 1)
			{
				pthread_mutex_lock(&ph2[i].vars->vulture);	
				ph2[i].vars->checker = 1;
				pthread_mutex_unlock(&ph2[i].vars->vulture);
				exit (EXIT_FAILURE);
			}
			i++;
		}
	}
	return (NULL);
}
int     init_threads(t_philo *ph)
{
        int i;

        i = 0;

//	if (pthread_create(&ph[i].vars->vt, NULL, &check_dead, (void *)&ph) != 0)
//		return (-1);
        while (i < ph->vars->total)
        {
                if (pthread_create(&ph[i].th, NULL, &routine, (void *)&ph[i]) != 0)
                        return (-1);
                i++;
        }
        i = 0;
        while (i < ph->vars->total)
        {
                if (pthread_join(ph[i].th, NULL) != 0)
                        return (-1);
                i++;
     	}
//	if (pthread_join(ph[i].vars->vt, NULL) != 0)
//		return (-1);
       return (0);
}
