#include "philosophers.h"

int	check_diff(unsigned long long last_eat)
{
	return (gettime() - last_eat);
}

int	check_if_philo_dieded(t_param *param)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < param->nbr_philos)
		{
			if (check_diff(param->philo[i].time_last_eat) > param->time_to_die)
			{
				print_event(param, "died", param->philo[i].id_philo);
				pthread_mutex_lock(&param->check_die);
				param->dieded = 1;
				pthread_mutex_unlock(&param->check_die);
				return (1);
			}
			pthread_mutex_lock(&param->philo->check_meal);
			if (param->philo[i].meal == param->nbr_of_meal)
				param->all_ate++;
			pthread_mutex_unlock(&param->philo->check_meal);
			if (param->all_ate == param->nbr_philos)
			{
				pthread_mutex_lock(&param->check_die);
				param->dieded = 1;
				pthread_mutex_unlock(&param->check_die);
				return (1);
			}
		}
		usleep(500);
	}
}
