#include "philosophers.h"

int	parsing(t_param *param, char **argv, int argc)
{
	if (check(argc, param) == 0)
		return (0);
	param->number_of_philosophers = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]) * 1000;
	param->time_to_eat = ft_atoi(argv[3]) * 1000;
	param->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		param->number_of_times_each_philosophers_must_eat = ft_atoi(argv[5]);
	return (1);
}

int	check(int argc, t_param *param)
{
	init_variable(param);
	if (argc != 5 && argc != 6)
		return (exit_strerror(param, "Wrong amount of arguments\n"));
	return (1);
}
