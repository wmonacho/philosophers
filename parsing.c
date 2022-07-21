#include "philosophers.h"

int	parsing(t_grp *philo, char **argv, int argc)
{
	if (check(argc, philo) == 0)
		return (0);
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]) * 1000;
	philo->time_to_eat = ft_atoi(argv[3]) * 1000;
	philo->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		philo->number_of_times_each_philosophers_must_eat = ft_atoi(argv[5]);
	return (1);
}

int	check(int argc, t_grp *philo)
{
	init_variable(philo);
	if (argc != 5 && argc != 6)
		return (exit_strerror(philo, "Wrong amount of arguments\n"));
	return (1);
}
