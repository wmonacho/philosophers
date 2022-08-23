/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:05 by wmonacho          #+#    #+#             */
/*   Updated: 2022/08/23 14:03:05 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exit_strerror(t_param *param, char *str)
{
	ft_putstr_fd(str, 0);
	free(param->philo->forks);
	free(param->philo);
	free(param);
	exit(0);
	return (0);
}
