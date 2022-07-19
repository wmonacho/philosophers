#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_grp	*philo;

	philo = malloc(sizeof(t_grp));
	if (philo == NULL)
		return (1);
	init_variable(philo);
	parsing(philo, argv, argc);
	argc += 0;
	argv += 0;
	philo += 0;
	return (0);
}
