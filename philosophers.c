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

void	*threadrout(void *arg)
{
	t_philo	*phi;
	t_param	*param;

	phi = (t_philo *)arg;
	param = phi->param;
	return (NULL);
}

void	check_if_philo_dieded(t_param *param)
{
	unsigned long long	last_time;
	int	i;

	i = -1;
	param->time = gettime();
	while (++i < param->nbr_philos)
	{
	last_time = param->time;
	gettime();
}

void	ft_eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->check_fork);
	philo->fork = 0;
	pthread_mutex_unlock(&philo->check_fork);
	pthread_mutex_lock(&philo->print_message);
	printf("%lli %lli has token a fork\n", get_time(), philo->philo_id);
	pthread_mutex_unlock(&philo->print_message);
	while (1)
	{
		if (philo->param->philo[philo_id -1].fork == 1)
		{
			pthread_mutex_lock(&philo->print_message);
			printf("%lli %lli has token a fork\n", get_time(), philo->philo_id);
			pthread_mutex_unlock(&philo->print_message);
			pthread_mutex_lock(&philo->check_fork);
			philo->param->philo[philo_id - 1].fork == 0;
			pthread_mutex_unlock(&philo->check_fork);
			break();
		}
	}
	
}

void	ft_think()
{
	pthread_mutex_lock(philo->print_message);
	printf("%lli %lli he is thinking\n", get_time(), philo->philo_id);
	pthread_mutex_lock(philo->print_message);
}

void	ft_sleep()
{
	pthread_mutex_lock(philo->print_message);
	printf("%lli %lli he is sleeping\n", get_time(), philo->philo_id);
	pthread_mutex_lock(philo->print_message);
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
		check_if_philo_dieded(phi->param);
	}
}

void	simulation(t_param *param)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = param->philo;
	while (++i < param->number_of_philosophers)
		pthread_create(&(phi[i].id), NULL, &threadrout, &(phi[i]));
	check_if_philo_dieded(param);
}
