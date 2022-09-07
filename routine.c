/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/07 18:01:58 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_eat(t_philo	*philo)
{
	while (1)
	{
		if (check_die(philo) == 0)
			return (0);
		if (check_lfork(philo) == 1)
			break ;
		usleep(500);
	}
	while (1)
	{
		if (check_die(philo) == 0)
			return (0);
		if (check_rfork(philo) == 1)
			break ;
		usleep(500);
	}
	take_a_meal(philo);
	return (1);
}

void	take_a_meal(t_philo *philo)
{
	print_event(philo->param, "is eating", philo->id_philo);
	pthread_mutex_lock(&philo->check_last_eat);
	philo->time_last_eat = gettime();
	pthread_mutex_unlock(&philo->check_last_eat);
	ft_usleep(philo->param->time_to_eat);
	pthread_mutex_lock(&philo->check_meal);
	philo->meal++;
	pthread_mutex_unlock(&philo->check_meal);
	reset_fork(philo);
}

void	reset_fork(t_philo *philo)
{
	if (philo->id_philo != 1)
	{
		pthread_mutex_lock(&philo->param
			->philo[philo->id_philo - 1].check_forks);
		philo->param->philo[philo->id_philo - 2].fork = 1;
		pthread_mutex_unlock(&philo->param
			->philo[philo->id_philo - 1].check_forks);
	}
	else
	{
		pthread_mutex_lock(&philo->param
			->philo[philo->param->nbr_philos - 1].check_forks);
		philo->param->philo[philo->param->nbr_philos - 1].fork = 1;
		pthread_mutex_unlock(&philo->param
			->philo[philo->param->nbr_philos - 1].check_forks);
	}
	pthread_mutex_lock(&philo->check_forks);
	philo->fork = 1;
	pthread_mutex_unlock(&philo->check_forks);
}

void	ft_sleep(t_philo *philo)
{
	print_event(philo->param, "is sleeping", philo->id_philo);
	usleep(philo->param->time_to_sleep);
}

void	*threadrout(void	*arg)
{
	t_philo	*phi;

	phi = arg;
	if ((phi->id_philo % 2) != 1)
		ft_usleep(phi->param->time_to_eat);
	while (1)
	{
		if (check_die(phi) == 0)
			return (NULL);
		if (ft_eat(phi) == 0)
			return (NULL);
		ft_sleep(phi);
		if (check_die(phi) == 0)
			return (NULL);
		ft_think(phi);
	}
	return (NULL);
}
