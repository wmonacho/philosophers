#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_param	*param;
	int		i;

	param = malloc(sizeof(t_param));
	if (param == NULL)
		return (1);
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
	printf("time = %lld microsecond\n", ms);
	return (ms);
}

int	check_diff(unsigned long long last_eat)
{
	return (gettime() - last_eat);
}

void	check_if_philo_dieded(t_param *param)
{
	int	i;

	i = -1;
	while (1)
	{
		while (++i < param->nbr_philos)
		{
			if (check_diff(param->philo[i].time_last_eat) > param->time_to_die)
			{
				print_event(param, "died");
				pthread_mutex_lock(&param->check_die);
				param->dieded = 1;
				pthread_mutex_unlock(&param->check_die);
				break;

			}
		}
		usleep(500);
	}
}

void	ft_usleep(int time)
{
	int	i;
	unsigned long long	start_time;

	i = 0;
	start_time = gettime();
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

void	print_event(t_param *param, char *message)
{
	pthread_mutex_lock(&param->check_die);
	if (param->dieded == 0)
		printf("%lli %i %s\n", gettime() / 1000, param->philo->id_philo, message);
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
