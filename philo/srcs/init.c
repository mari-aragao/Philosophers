#include "philo.h"

t_philo	*init_all(int argc, char **argv)
{
	int	total;
	t_philo	*ph;

	total = ft_atoi(argv[1]); 
	ph = (t_philo *)malloc(sizeof(t_philo) * total);
	if (!ph)
		return (NULL);
	ph = init_parameters(argc, argv, ph, total);
	if (!ph)
		return (NULL);
	return (ph);
}

t_vars *init_vars(int argc, char **argv, int total)
{
	int	i;
        t_vars *vars;

        vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->meals_to_make = -1;
	if (argc == 6)
		vars->meals_to_make = ft_atoi(argv[5]);
	vars->forks = malloc(sizeof(pthread_mutex_t) * total);
	if (!vars->forks)
		return (NULL);
	vars->arr_fk = malloc(sizeof(int) * total);
	if (!vars->arr_fk)
		return (NULL);
        pthread_mutex_init(&vars->print, NULL);
        pthread_mutex_init(&vars->m_checker, NULL);
	i = -1;
	while(++i < total)
	{
        	pthread_mutex_init(&vars->forks[i], NULL);
		vars->arr_fk[i] = 0;
	}
        return (vars);
}

t_philo *init_parameters(int argc, char **argv, t_philo *ph, int total)
{
        int i;
	t_vars	*va;

	va = init_vars(argc, argv, total);
	if (!va)
		return (NULL);
	va->total = ft_atoi(argv[1]); 
	va->time_to_die = ft_atoi(argv[2]); 
	va->time_to_eat = ft_atoi(argv[3]); 
	va->time_to_sleep = ft_atoi(argv[4]);
	va->checker = 0;
        i = 0;
        while (i < total)
        {
                ph[i].id = i + 1;
                ph[i].meal_cntr = 0;
                ph[i].die = 0;
		ph[i].st_time = get_time();
		ph[i].last_meal = get_time();
		ph[i].vars = va;
                i++;
        }
        return (ph);
}

int     init_threads(t_philo *ph)
{
        int i;

        i = -1;
	if (ph->vars->total == 1)
	{
                if (pthread_create(&ph[0].th, NULL, &routine_for_one, (void *)&ph[0]) != 0)
                        return (-1);
                if (pthread_join(ph[0].th, NULL) != 0)
                        return (-1);
		return (0);
	}
	while (++i < ph->vars->total)
	{
   		if (pthread_create(&ph[i].th, NULL, &routine, (void *)&ph[i]) != 0)
			return (-1);
	}
        i = -1;
        while (++i < ph->vars->total)
        {
                if (pthread_join(ph[i].th, NULL) != 0)
			return (-1);
	}
	return (0);
}
