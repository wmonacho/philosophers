/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:02:59 by wmonacho          #+#    #+#             */
/*   Updated: 2022/08/23 14:54:14 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philo
{
	int					ate;
	pthread_t			id;
	int					id_philo;
	unsigned long long	time_last_eat;
	pthread_mutex_t		check_last_eat;
	pthread_mutex_t		check_meal;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	int					meal;
	struct s_param		*param;
}				t_philo;

typedef struct s_param
{
	int					nbr_philos;
	int					dieded;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					all_ate;
	int					nbr_of_meal;
	unsigned long long	time;
	unsigned long long	start_time;
	pthread_mutex_t		mutex_check;
	pthread_mutex_t		check_die;
	pthread_mutex_t		print_message;
	t_philo				*philo;
}				t_param;

void				init_variable(t_param *param);
int					ft_atoi(const char *str);
int					main(int argc, char **argv);
int					parsing(t_param *param, char **argv, int argc);
int					check(int argc, t_param *param);
void				ft_putstr_fd(char *s, int fd);
unsigned long long	gettime(void);
int					exit_strerror(t_param *param, char *str);
void				simulation(t_param *param);
void				*threadrout(void *arg);
void				print_event(t_param *param, char *message, int id);
void				ft_usleep(int time);
int					init_mutex(t_param *param);
int					ft_eat(t_philo	*philo);
int					param_init(t_param *param, char **argv, int argc);
int					philo_init(t_param *param, int i);
void				take_a_meal(t_philo *philo);
int					check_die(t_philo *philo);
int					check_if_philo_dieded(t_param *param);
int					check_last_eat(t_param *param, int i);
int					check_fork(t_philo *philo);
int					check_diff(unsigned long long last_eat);
int					join_and_destroy_thread(t_param *param);
int					destroy_mutex(t_param *param, pthread_mutex_t *mutex);
#endif