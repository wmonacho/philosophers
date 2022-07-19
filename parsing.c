#include "philosophers.h"

int	parsing(t_grp *philo, char **argv, int argc)
{
	if (check(argc) == 0)
		return (0);
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->number_of_times_each_philosophers_must_eat = ft_atoi(argv[5]);
	return (1);
}

int	check(int argc)
{
	if (argc != 6)
	{
		ft_putstr_fd("wrong number of argument\n", 0);
		return (0);
	}
	return (1);
}
