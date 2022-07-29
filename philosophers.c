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

	}
	

}

void	simulation(t_param *param)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = param->philo;
	while (++i < param->number_of_philosophers)
	{
		pthread_mutex_lock(&(param->mutex_check));
		pthread_create(&(phi[i].id), NULL, &threadrout, &(phi[i]));
		pthread_mutex_unlock(&(param->mutex_check));
	}
	check_if_philo_dieded(param);
}
