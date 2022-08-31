/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:17 by wmonacho          #+#    #+#             */
/*   Updated: 2022/08/31 16:34:13 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_eat(t_philo	*philo)
{
	while (1)
	{
		if (check_die(philo) == 0)
			return (0);
		if (check_fork(philo) == 1)
			break ;
		else
			return (0);
	}
	take_a_meal(philo);
	return (1);
}

void	take_a_meal(t_philo *philo)
{
	print_event(philo->param, "is eating", philo->id_philo);
	ft_usleep(philo->param->time_to_eat);
	pthread_mutex_lock(&philo->check_last_eat);
	philo->time_last_eat = gettime();
	pthread_mutex_unlock(&philo->check_last_eat);
	pthread_mutex_lock(&philo->check_meal);;
	philo->meal++;
	pthread_mutex_unlock(&philo->check_meal);
}

void	ft_think(t_philo *philo)
{
	print_event(philo->param, "is thinking", philo->id_philo);
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
