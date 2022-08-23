/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:29 by wmonacho          #+#    #+#             */
/*   Updated: 2022/08/23 14:03:29 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_diff(unsigned long long last_eat)
{
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
			if (check_last_eat(param, i) == 0)
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
		pthread_mutex_lock(&param->check_die);
		param->dieded = 1;
		pthread_mutex_unlock(&param->check_die);
		return (0);
	}
	pthread_mutex_lock(&param->philo->check_meal);
	if (param->philo[i].meal == param->nbr_of_meal)
		param->all_ate++;
	pthread_mutex_unlock(&param->philo->check_meal);
	if (param->all_ate == param->nbr_philos)
	{
		pthread_mutex_lock(&param->check_die);
		param->dieded = 1;
		pthread_mutex_unlock(&param->check_die);
		return (0);
	}
	return (1);
}

int	check_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_event(philo->param, "has taken a fork", philo->id_philo);
	pthread_mutex_lock(philo->rfork);
	print_event(philo->param, "has taken a fork", philo->id_philo);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (1);
}

int	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->check_die);
	if (philo->param->dieded == 1)
	{
		pthread_mutex_unlock(&philo->param->check_die);
		return (0);
	}
	pthread_mutex_unlock(&philo->param->check_die);
	return (1);
}
