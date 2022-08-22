#include "philosophers.h"

int	parsing(t_param *param, char **argv, int argc)
{
	int	i;

	i = 0;
	if (check(argc, param) == 0)
		return (0);
	param_init(param, argv, argc);
	param->philo->fork = malloc(sizeof(int) * (param->nbr_philos));
	i = -1;
	while (++i < param->nbr_philos)
		param->philo->fork[i] = 1;
	i = -1;
	init_mutex(param);
	while (++i < param->nbr_philos)
	{
		philo_init(param, i);
	}
	param->dieded = 0;
	return (1);
}

int	param_init(t_param *param, char **argv, int argc)
{
	param->nbr_philos = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]) * 1000;
	param->time_to_eat = ft_atoi(argv[3]) * 1000;
	param->time_to_sleep = ft_atoi(argv[4]) * 1000;
	param->philo = malloc(sizeof(t_philo)
			* (param->nbr_philos + 1));
	param->all_ate = 0;
	if (param->philo == NULL)
		return (0);
	if (argc == 6)
		param->nbr_of_meal = ft_atoi(argv[5]);
	else
	{
		param->nbr_of_meal = -1;
	}
}

int	philo_init(t_param *param, int i)
{
	if (i == 0)
	{
		param->philo[i].lfork = &param->philo->fork[param->nbr_philos - 1];
		param->philo[i].rfork = &param->philo->fork[i];
	}
	else
	{
		param->philo[i].lfork = &param->philo->fork[i - 1];
		param->philo[i].rfork = &param->philo->fork[i];
	}
	param->philo[i].time_last_eat = gettime();
	param->philo[i].param = param;
	param->philo[i].id_philo = i + 1;
	param->philo[i].meal = 0;
	pthread_mutex_init(&param->philo[i].check_fork, NULL);
	pthread_mutex_init(&param->philo[i].check_last_eat, NULL);
	pthread_mutex_init(&param->philo[i].check_meal, NULL);
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
