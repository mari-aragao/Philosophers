#include "philo.h"

t_mutex *init_mutex(void)
{
        t_mutex *mutex;

        mutex = (t_mutex *)malloc(sizeof(t_mutex));
        pthread_mutex_init(&mutex->print, NULL);
        pthread_mutex_init(&mutex->forks, NULL);
        return (mutex);
}

t_philo *init_philo(int argc, char **argv)
{
        int     total;
        t_philo *ph;

        total = ft_atoi(argv[1]);
//      (void)argc;
//      (void)argv;
//      total = 5;
        ph = (t_philo *)malloc(sizeof(t_philo) * total);
        if (!ph)
                return (NULL);
        init_parameters(argc, argv, ph, total);
        return(ph);
}

t_philo *init_parameters(int argc, char **argv, t_philo *ph, int total)
{
        int i;
        int j;

        i = 0;
        while (i < total)
        {
                ph[i].philo_id = i + 1;
                ph[i].total_philos = ft_atoi(argv[1]);
                ph[i].time_to_die = ft_atoi(argv[2]);
                ph[i].time_to_eat = ft_atoi(argv[3]);
                ph[i].time_to_sleep = ft_atoi(argv[4]);
                ph[i].meals_to_make = -1;
                if(argc == 6)
                        ph[i].meals_to_make = ft_atoi(argv[5]);
                ph[i].meal_counter = 0;
                ph[i].stop = 0;
                ph[i].arr_forks = (int *)malloc(sizeof(int) * ph[i].total_philos);
                j = 0;
                while(j < ph[i].total_philos)
                        ph[i].arr_forks[j++] = 0;
                i++;
        }
        return (ph);
}
