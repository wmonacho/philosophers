#include "philosophers.h"

int	parsing(t_param *param, char **argv, int argc)
{
	int	i;

	i = 0;
	if (check(argc, param) == 0)
		return (0);
	printf("test1\n");
	param->nbr_philos = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]) * 1000;
	param->time_to_eat = ft_atoi(argv[3]) * 1000;
	param->time_to_sleep = ft_atoi(argv[4]) * 1000;
	param->philo = malloc(sizeof(t_philo)
			* (param->nbr_philos + 1));
	if (param->philo == NULL)
		return (0);
	while (++i < param->nbr_philos)
		param->philo[i].time_last_eat = param->time;
	if (argc == 6)
		param->nbr_of_times_each_philos_must_eat = ft_atoi(argv[5]);
	else 
	{
		param->nbr_of_times_each_philos_must_eat = 1000000000;
	}
	i = 0;
	// param->philo[param->nbr_philos] = NULL;
	init_mutex(param);
	while (i < param->nbr_philos)
	{
		param->philo[i].param = param;
		param->philo[i].id_philo = i + 1;
		param->philo[i].fork = 1;
		pthread_mutex_init(&param->philo[i].check_fork, NULL);
		i++;
	}
	param->dieded = 0;
	return (1);
}

int	init_mutex(t_param *param)
{
	pthread_mutex_init(&param->check_die, NULL);
	pthread_mutex_init(&param->mutex_check, NULL);
	pthread_mutex_init(&param->print_message, NULL);
	return (1);
}

int	check(int argc, t_param *param)
{
	init_variable(param);
	if (argc != 5 && argc != 6)
		return (exit_strerror(param, "Wrong amount of arguments\n"));
	return (1);
}
