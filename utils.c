/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:21 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/07 13:05:40 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(unsigned long long time)
{
	unsigned long long	start_time;

	start_time = gettime();
	usleep(time * 0.95);
	while (check_diff(start_time) < time)
		usleep(100);
}

void	print_event(t_param *param, char *message, int id)
{
	pthread_mutex_lock(&param->print_message);
	if (param->dieded == 0)
		printf("%lli %i %s\n", ((gettime() - param->start_time) / 1000),
			id, message);
	pthread_mutex_unlock(&param->print_message);
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000000) + (time.tv_usec);
	return (ms);
}
