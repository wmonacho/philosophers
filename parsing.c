/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:33 by wmonacho          #+#    #+#             */
/*   Updated: 2022/08/24 11:22:34 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(t_param *param, char **argv, int argc)
{
	int	i;

	if (check(argc, param) == 0)
		exit_parse(param, "malloc");
	param_init(param, argv, argc);
	init_mutex(param);
	param->philo->forks = malloc(sizeof(pthread_mutex_t) * (param->nbr_philos));
	if (param->philo->forks == NULL)
		exit_strerror(param, "malloc");
	i = -1;
	while (++i < param->nbr_philos)
		if (pthread_mutex_init(&param->philo->forks[i], NULL) != 0)
			exit_destroy_forks(param, "mutex forks", i);
	i = -1;
	while (++i < param->nbr_philos)
		philo_init(param, i);
	param->dieded = 0;
	return (1);
}

int	param_init(t_param *param, char **argv, int argc)
{
	param->nbr_philos = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]) * 1000;
	param->time_to_eat = ft_atoi(argv[3]) * 1000;
	param->time_to_sleep = ft_atoi(argv[4]) * 1000;
	param->philo = malloc(sizeof(t_philo)
			* (param->nbr_philos + 1));
	param->all_ate = 0;
	if (param->philo == NULL)
		exit_strerror(param, "malloc");
	if (argc == 6)
		param->nbr_of_meal = ft_atoi(argv[5]);
	else
	{
		param->nbr_of_meal = -1;
	}
	return (1);
}

int	philo_init(t_param *param, int i)
{
	if (i == 0)
	{
		param->philo[i].lfork = &param->philo->forks[param->nbr_philos - 1];
		param->philo[i].rfork = &param->philo->forks[0];
	}
	else
	{
		param->philo[i].lfork = &param->philo->forks[i - 1];
		param->philo[i].rfork = &param->philo->forks[i];
	}
	param->philo[i].time_last_eat = gettime();
	param->philo[i].param = param;
	param->philo[i].id_philo = i + 1;
	param->philo[i].meal = 0;
	if (pthread_mutex_init(&param->philo[i].check_last_eat, NULL) != 0)
		exit_destroy_last_eat(param, "mutex forks", i);
	if (pthread_mutex_init(&param->philo[i].check_meal, NULL) != 0)
		exit_destroy_meal(param, "mutex forks", i);
	return (1);
}

int	init_mutex(t_param *param)
{
	pthread_mutex_init(&param->check_die, NULL);
	pthread_mutex_init(&param->mutex_check, NULL);
	pthread_mutex_init(&param->print_message, NULL);
	return (1);
}

int	check(int argc, t_param *param)
{
	init_variable(param);
	if (argc != 5 && argc != 6)
		return (exit_parse(param, "Wrong amount of arguments\n"));
	return (1);
}
