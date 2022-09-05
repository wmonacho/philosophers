/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:27:53 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/05 18:03:24 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exit_destroy_last_eat(t_param *param, char *str, int i)
{
	ft_putstr_fd(str, 0);
	while (++i < param->nbr_philos)
		destroy_mutex(param, &param->philo[i].check_last_eat);
	i = -1;
	destroy_mutex(param, &param->check_die);
	destroy_mutex(param, &param->mutex_check);
	destroy_mutex(param, &param->print_message);
	ft_delone((void *)(param));
	ft_delone((void *)(param->philo));
	exit(0);
	return (0);
}

int	exit_all_destroy(t_param *param, char *str)
{
	int	i;

	ft_putstr_fd(str, 0);
	i = -1;
	while (++i < param->nbr_philos)
	{
		destroy_mutex(param, &param->philo[i].check_last_eat);
		destroy_mutex(param, &param->philo[i].check_meal);
		destroy_mutex(param, &param->philo[i].check_forks);
	}
	destroy_mutex(param, &param->check_die);
	destroy_mutex(param, &param->mutex_check);
	destroy_mutex(param, &param->print_message);
	ft_delone((void *)(param));
	ft_delone((void *)(param->philo));
	exit(0);
	return (0);
}

int	exit_destroy_meal(t_param *param, char *str, int i)
{
	ft_putstr_fd(str, 0);
	while (++i < param->nbr_philos)
		destroy_mutex(param, &param->philo[i].check_meal);
	i = -1;
	while (++i < param->nbr_philos)
	{
		destroy_mutex(param, &param->philo[i].check_last_eat);
		destroy_mutex(param, &param->philo[i].check_forks);
	}
	destroy_mutex(param, &param->check_die);
	destroy_mutex(param, &param->mutex_check);
	destroy_mutex(param, &param->print_message);
	ft_delone((void *)(param));
	ft_delone((void *)(param->philo));
	exit(0);
	return (0);
}

int	exit_destroy_forks(t_param *param, char *str, int i)
{
	ft_putstr_fd(str, 0);
	while (++i < param->nbr_philos)
		destroy_mutex(param, &param->philo[i].check_meal);
	destroy_mutex(param, &param->check_die);
	destroy_mutex(param, &param->mutex_check);
	destroy_mutex(param, &param->print_message);
	ft_delone((void *)(param));
	ft_delone((void *)(param->philo));
	exit(0);
	return (0);
}
