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

/*
voir pour print les messages (dans les mp de raph) 4/4 OK
faire la fontions de check if dieded 4/4 OK
normer pour tester 4/4 OK
mettre la variable incrementer du nombre de repas pour chaque philo 4/4 OK
faire attention si il n'y a pas de limite de repas 4/4 OK
changer les noms des messages 4/4 OK

changer les forks comme leonard pour eviter que les philos communiquent 1/4
destroy les mutex 0/4
faire attention au premier philo 2/4
faire attention s'il n'y a que 1 philo 0/4
normer les fonctions 2/4


faire les fonctions free (basic)
corriger et debugger les segfault 3/4 NOT OK
trouver un bon resultat 1.5/4
faire les fontions de free 2/4
regarder les petits cas a part (si un seul philo etc) 2/4
*/
