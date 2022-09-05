/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:05 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/05 18:00:04 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exit_strerror(t_param *param, char *str)
{
	ft_putstr_fd(str, 0);
	ft_delone((void *)(param));
	ft_delone((void *)(param->philo));
	exit(0);
	return (0);
}

int	exit_parse(t_param *param, char *str)
{
	ft_putstr_fd(str, 0);
	ft_delone((void *)(param));
	ft_delone((void *)(param->philo));
	exit(0);
	return (0);
}

void	ft_delone(void	*str)
{
	if (str != NULL)
		free(str);
}
