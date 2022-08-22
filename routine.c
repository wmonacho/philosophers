#include "philosophers.h"

int	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->check_fork);
	philo->fork = 0;
	pthread_mutex_unlock(&philo->check_fork);
	print_event(philo->param, "has taken a fork", philo->id_philo);
	while (1)
	{
		pthread_mutex_lock(&philo->param->check_die);
		if (philo->param->dieded == 1)
		{
			pthread_mutex_unlock(&philo->param->check_die);
			return (1);
		}
		pthread_mutex_unlock(&philo->param->check_die);
		if (philo->param->philo[philo->id_philo - 2].fork == 1)
		{
			print_event(philo->param, "has taken a fork", philo->id_philo);
			pthread_mutex_lock(&philo->check_fork);
			philo->param->philo[philo->id_philo - 2].fork = 0;
			pthread_mutex_unlock(&philo->check_fork);
			break;
		}
	}
	pthread_mutex_lock(&philo->check_last_eat);
	philo[philo->id_philo].time_last_eat = gettime();
	pthread_mutex_unlock(&philo->check_last_eat);
	print_event(philo->param, "is eating", philo->id_philo);
	ft_usleep(philo->param->time_to_eat);
	pthread_mutex_lock(&philo->check_meal);
	philo->meal++;
	pthread_mutex_unlock(&philo->check_meal);
	pthread_mutex_lock(&philo->check_fork);
	philo->fork = 1;
	pthread_mutex_unlock(&philo->check_fork);
	pthread_mutex_lock(&philo->check_fork);
	philo->param->philo[philo->id_philo - 1].fork = 1;
	pthread_mutex_unlock(&philo->check_fork);
	return (1);
}

void	ft_think(t_philo *philo)
{
	print_event(philo->param, "is thinking", philo->id_philo);
}

void	ft_sleep(t_philo *philo)
{
	print_event(philo->param, "is sleeping", philo->id_philo);
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
