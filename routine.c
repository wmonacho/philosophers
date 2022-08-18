#include "philosophers.h"

void	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->check_fork);
	philo->fork = 0;
	pthread_mutex_unlock(&philo->check_fork);
	print_event(philo->param, "he token a fork");
	while (1)
	{
		pthread_mutex_lock(&philo->param->check_die);
		if (philo->param->dieded == 1)
		{
			pthread_mutex_unlock(&philo->param->check_die);
			break;
		}
		pthread_mutex_unlock(&philo->param->check_die);
		if (philo->param->philo[philo->id_philo - 1].fork == 1)
		{
			print_event(philo->param, "he token a fork");
			pthread_mutex_lock(&philo->check_fork);
			philo->param->philo[philo->id_philo - 1].fork = 0;
			pthread_mutex_unlock(&philo->check_fork);
			break;
		}
	}
}

void	ft_think(t_philo *philo)
{
	print_event(philo->param, "he is thinking");
}

void	ft_sleep(t_philo *philo)
{
	print_event(philo->param, "he is sleeping");
	usleep(philo->param->time_to_sleep);
}

void	*threadrout(void	*arg)
{
	t_philo	*phi;

	phi = arg;
	if ((phi->id_philo % 2) != 1)
		ft_usleep(phi->param->time_to_eat);
	while (1)
	{
		ft_eat(phi);
		ft_sleep(phi);
		ft_think(phi);
		pthread_mutex_lock(&phi->param->check_die);
		if (phi->param->dieded == 1)
		{
			pthread_mutex_unlock(&phi->param->check_die);
			break;
		}
		pthread_mutex_unlock(&phi->param->check_die);
	}
	return (NULL);
}
