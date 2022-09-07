/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:29 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/07 12:08:35 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_philo_dieded(t_param *param)
{
	int	i;

	while (1)
	{
		i = -1;
		param->all_ate = 1;
		while (++i < param->nbr_philos)
		{
			if (check_last_eat(param, i) == 0)
				return (0);
		}
		if (param->all_ate == 1)
		{
			pthread_mutex_lock(&param->print_message);
			param->dieded = 1;
			pthread_mutex_unlock(&param->print_message);
			return (0);
		}
		usleep(500);
	}
	return (1);
}

int	check_last_eat(t_param *param, int i)
{
	if (check_diff(param->philo[i].time_last_eat) > param->time_to_die)
	{
		print_event(param, "died", param->philo[i].id_philo);
		return (0);
	}
	pthread_mutex_lock(&param->philo->check_meal);
	if (param->philo[i].meal < param->nbr_of_meal || param->nbr_of_meal == -1)
		param->all_ate = 0;
	pthread_mutex_unlock(&param->philo->check_meal);
	return (1);
}

int	check_rfork(t_philo *philo)
{
	if (philo->id_philo != 1)
	{
		pthread_mutex_lock(&philo->param
			->philo[philo->id_philo - 1].check_forks);
		if (philo->param->philo[philo->id_philo - 2].fork == 1)
		{
			philo->param->philo[philo->id_philo - 2].fork = 0;
			pthread_mutex_unlock(&philo->param
				->philo[philo->id_philo - 1].check_forks);
			print_event(philo->param, "has token a fork", philo->id_philo);
			return (1);
		}
		pthread_mutex_unlock(&philo->param
			->philo[philo->id_philo - 1].check_forks);
	}
	else
	{
		if (check_rfork_first(philo) == 1)
			return (1);
	}
	return (0);
}

int	check_lfork(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_forks);
	if (philo->fork == 1)
	{
		philo->fork = 0;
		pthread_mutex_unlock(&philo->check_forks);
		print_event(philo->param, "has token a fork", philo->id_philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->check_forks);
	return (0);
}

int	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->print_message);
	if (philo->param->dieded == 1)
	{
		pthread_mutex_unlock(&philo->param->print_message);
		return (0);
	}
	pthread_mutex_unlock(&philo->param->print_message);
	return (1);
}
