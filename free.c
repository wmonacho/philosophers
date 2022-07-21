#include "philosophers.h"

int	exit_strerror(t_param *param, char *str)
{
	ft_putstr_fd(str, 0);
	free(param);
	exit(0);
	return (0);
}
