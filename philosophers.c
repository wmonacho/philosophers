#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_param	*param;
	int		i;

	param = malloc(sizeof(t_param));
	if (param == NULL)
		return (1);
	param->start_time = gettime();
	param->time = gettime();
	parsing(param, argv, argc);
	simulation(param);
	i = 0;
	while (i < param->nbr_philos)
	{
		pthread_join((param->philo[i].id), NULL);
		i++;
	}
	return (0);
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000000) + (time.tv_usec);
	// printf("time = %lld microsecond\n", ms);
	return (ms);
}

int	check_diff(unsigned long long last_eat)
{
	// printf("test_getdif\n");
	return (gettime() - last_eat);
}

int	check_if_philo_dieded(t_param *param)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < param->nbr_philos)
		{
			// printf("timelasteat=%lli\n", param->philo[i].time_last_eat);
			if (check_diff(param->philo[i].time_last_eat) > param->time_to_die)
			{
				print_event(param, "died", param->philo[i].id_philo);
				pthread_mutex_lock(&param->check_die);
				param->dieded = 1;
				pthread_mutex_unlock(&param->check_die);
				return (1);
			}
		}

		// printf("test_die\n");
		usleep(500);
	}
}

void	ft_usleep(int time)
{
	int	i;
	unsigned long long	start_time;

	i = 0;
	start_time = gettime();
	usleep((time / 100) * 95);
	while (i)
	{
		if (check_diff(start_time) > time)
			break;
	}
}

void	simulation(t_param *param)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = param->philo;
	phi += 0;
	while (++i < param->nbr_philos)
		pthread_create(&(phi[i].id), NULL, &threadrout, &(phi[i]));
	check_if_philo_dieded(param);
}

void	print_event(t_param *param, char *message, int id)
{
	pthread_mutex_lock(&param->check_die);
	if (param->dieded == 0)
		printf("%lli %i %s\n", ((gettime() - param->start_time) / 1000), id, message);
	pthread_mutex_unlock(&param->check_die);
}

/*
voir pour print les messages (dans les mp de raph) 4/4 OK
faire la fontions de check if dieded 4/4 OK
normer pour tester 4/4 OK
corriger et debugger les segfault 3/4 NOT OK
trouver un bon resultat 0.5/4
faire les fontions de free 1/4
regarder les petits cas a part (si un seul philo etc)  
*/
