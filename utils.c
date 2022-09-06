/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:03:21 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/06 19:02:01 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int time)
{
	int					i;
	unsigned long long	start_time;

	i = 1;
	start_time = gettime();
	usleep(time / 100 * 95);
	while (i)
	{
		if (check_diff(start_time) > time)
			break ;
	}
}

void	print_event(t_param *param, char *message, int id)
{
	pthread_mutex_lock(&param->check_die);
	if (param->dieded == 0)
		printf("%lli %i %s\n", ((gettime() - param->start_time) / 1000),
			id, message);
	pthread_mutex_unlock(&param->check_die);
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000000) + (time.tv_usec);
	return (ms);
}
