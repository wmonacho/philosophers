#include "philosophers.h"

int	exit_strerror(t_grp *philo, char *str)
{
	ft_pustr_fd(str, 0);
	free(philo);
	exit(0);
	return (0);
}