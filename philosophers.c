#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_grp	*philo;

	philo = malloc(sizeof(t_grp));
	if (philo == NULL)
		return (1);
	parsing(philo, argv, argc);
	simulation(philo);
	philo->time = ft_gettime();
	return (0);
}

unsigned long long	ft_gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000000) + (time.tv_usec);
	printf("time = %lld microsecond\n", ms);
	return (ms);
}

void	simulation(t_grp *philo)
{
}