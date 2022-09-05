/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:10 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:00 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_variable(t_param *param)
{
	param->philo = NULL;
}

int	check_diff(unsigned long long last_eat)
{
	return (gettime() - last_eat);
}
