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
	param->time = gettime();
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

	last_time = param->time;
	gettime();
	if (last_time - param->time > philo->time_)
	{

	}
}

void	threadrout(void	*arg)
{
	t_philo	*phi;

	phi = arg;
	if ((phi->id_philo % 2) != 1)
		ft_usleep(phi->param->time_to_eat);
	while (1);
	{
		ft_eat();
		ft_sleep();
		ft_think();
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
