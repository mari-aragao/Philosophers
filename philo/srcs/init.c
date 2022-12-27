#include "philo.h"

t_all	*init_all(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->ph = init_philo(argc, argv);
	if (!all->ph)
		return (NULL);
	all->mutex = init_mutex(ft_atoi("5"));////////
	if (!all->mutex)
		return (NULL);
	return (all);
}

t_mutex *init_mutex(int total)
{
	int	i;
        t_mutex *mutex;

        mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
		return (NULL);
	mutex->forks = malloc(sizeof(pthread_mutex_t) * total);
	if (!mutex->forks)
		return (NULL);
	mutex->arr_forks = malloc(sizeof(int) * total);
	if (!mutex->arr_forks)
		return (NULL);
        pthread_mutex_init(&mutex->print, NULL);
	i = 0;
	while(i < total)
	{
        	pthread_mutex_init(&mutex->forks[i], NULL);
		mutex->arr_forks[i] = 0;
		i++;
	}
        return (mutex);
}

t_philo *init_philo(int argc, char **argv)
{
        int     total;
        t_philo *ph;

        total = ft_atoi("5"); //////
        ph = (t_philo *)malloc(sizeof(t_philo) * total);
        if (!ph)
                return (NULL);
        init_parameters(argc, argv, ph, total);
        return(ph);
}
/*
t_philo *init_parameters(int argc, char **argv, t_philo *ph, int total)
{
        int i;
	int j;

        i = 0;
        while (i < total)
        {
                ph[i].id = i + 1;
                ph[i].total = ft_atoi(argv[1]);
                ph[i].time_to_die = ft_atoi(argv[2]);
                ph[i].time_to_eat = ft_atoi(argv[3]);
                ph[i].time_to_sleep = ft_atoi(argv[4]);
                ph[i].meals_to_make = -1;
                if(argc == 6)
                        ph[i].meals_to_make = ft_atoi(argv[5]);
                ph[i].meal_counter = 0;
                ph[i].stop = 0;
		ph[i].start = get_time();
		j = 0;
		while (j < ph[i].total)
		{
			ph[i].arr_forks[j] = 0;
			j++;
		}
                i++;
        }
        return (ph);
}*/
