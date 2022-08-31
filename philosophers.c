/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:13 by wmonacho          #+#    #+#             */
/*   Updated: 2022/08/31 14:13:05 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (param == NULL)
		return (1);
	param->start_time = gettime();
	param->time = gettime();
	parsing(param, argv, argc);
	simulation(param);
	join_and_destroy_thread(param);
	exit_strerror(param, "END\n");
	return (0);
}

int	join_and_destroy_thread(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->nbr_philos)
	{
		pthread_join((param->philo[i].id), NULL);
	}
	i = -1;
	while (++i < param->nbr_philos)
	{
		destroy_mutex(param, &param->philo[i].check_last_eat);
		destroy_mutex(param, &param->philo[i].check_meal);
		destroy_mutex(param, &param->philo->forks[i]);
	}
	destroy_mutex(param, &param->check_die);
	destroy_mutex(param, &param->mutex_check);
	destroy_mutex(param, &param->print_message);
	return (1);
}

int	destroy_mutex(t_param *param, pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
		exit_strerror(param, "destroy_mutex");
	return (1);
}

void	simulation(t_param *param)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = param->philo;
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
faire attention s'il n'y a que 1 philo 4/4 OK
normer les fonctions 4/4 OK
changer les forks comme leonard pour eviter que les philos communiquent 4/4 OK
faire attention au premier philo 4/4 OK
destroy les mutex 4/4 OK
faire les fonctions free (basic) 4/4 OK

finir le programme sans erreurs 4/4 OK
regarder les petits cas a part (si un seul philo etc) 4/4 OK
corriger et debugger les segfault 4/4 OK

faire des fonctions de destroy specifique de mutex 1/4
*/
