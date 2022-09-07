/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:10 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/07 12:58:35 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_variable(t_param *param)
{
	param->philo = NULL;
}

unsigned long long	check_diff(unsigned long long last_eat)
{
	return (gettime() - last_eat);
}

int	check_rfork_first(t_philo *philo)
{
	pthread_mutex_lock(&philo->param
		->philo[philo->param->nbr_philos - 1].check_forks);
	if (philo->param->philo[philo->param->nbr_philos - 1].fork == 1)
	{
		philo->param->philo[philo->param->nbr_philos - 1].fork = 0;
		pthread_mutex_unlock(&philo->param
			->philo[philo->param->nbr_philos - 1].check_forks);
		print_event(philo->param, "he token a fork", philo->id_philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->param
		->philo[philo->param->nbr_philos - 1].check_forks);
	return (0);
}

void	ft_think(t_philo *philo)
{
	print_event(philo->param, "is thinking", philo->id_philo);
}
