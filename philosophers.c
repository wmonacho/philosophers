#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (param == NULL)
		return (1);
	param->time = gettime();
	parsing(param, argv, argc);
	simulation(param);
	return (0);
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000000) + (time.tv_usec);
	printf("time = %lld microsecond\n", ms);
	return (ms);
}

void	check_if_philo_dieded(t_param *param)
{
	int	i;

	i = -1;
	while (1)
	{
		while (++i < param->nbr_philos)
		{
			if (check_diff(param->philo[i].time_last_eat) > param->time_to_die)
			{
				print_event(param->philo, "died");
				pthread_mutex_lock(&param->philo->check_die);
				param->philo->dieded = 1;
				pthread_mutex_unlock(&param->philo->check_die);

			}
		}
		usleep(500);
	}
}

void	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->check_fork);
	philo->fork = 0;
	pthread_mutex_unlock(&philo->check_fork);
	print_event(philo, "he token a fork");
	while (1)
	{
		if (philo->param->philo[philo->id_philo -1].fork == 1)
		{
			print_event(philo, "he token a fork");
			pthread_mutex_lock(&philo->check_fork);
			philo->param->philo[philo->id_philo - 1].fork == 0;
			pthread_mutex_unlock(&philo->check_fork);
			break();
		}
	}
	
}

void	ft_think(t_philo *philo)
{
	print_event(philo, "he is thinking");
}

void	ft_sleep(t_philo *philo)
{
	print_event(philo, "he is sleeping");
	usleep(philo->param->time_to_sleep);
}

void	threadrout(void	*arg)
{
	t_philo	*phi;

	phi = arg;
	if ((phi->id_philo % 2) != 1)
		ft_usleep(phi->param->time_to_eat);
	while (1);
	{
		ft_eat(phi);
		ft_sleep(phi);
		ft_think(phi);
		pthread_mutex_lock(&phi->check_die);
		if (phi->dieded == 1)
		{
			pthread_mutex_unlock(&phi->check_die);
			break (0);
		}
	}
}

void	simulation(t_param *param)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = param->philo;
	while (++i < param->nbr_philos)
		pthread_create(&(phi[i].id), NULL, &threadrout, &(phi[i]));
	check_if_philo_dieded(param);
}

void	print_event(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->check_die);
	if (philo->dieded == 0)
		printf("%lli %lli %s\n", get_time(), philo->id_philo, message);
	pthread_mutex_unlock(&philo->check_die);
	return (1);
}

/*
voir pour print les messages (dans les mp de raph) 4/4 OK
faire la fontions de check if dieded 4/4 OK
normer pour tester
faire les fontions de free
regarder les petits cas a part (si un seul philo etc) 
*/