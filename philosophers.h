/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:02:59 by wmonacho          #+#    #+#             */
/*   Updated: 2022/09/07 13:00:52 by wmonacho         ###   ########lyon.fr   */
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
	pthread_mutex_t		check_forks;
	int					fork;
	int					meal;
	struct s_param		*param;
}				t_philo;

typedef struct s_param
{
	int					nbr_philos;
	int					dieded;
	unsigned long long	time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					all_ate;
	int					nbr_of_meal;
	unsigned long long	time;
	unsigned long long	start_time;
	pthread_mutex_t		print_message;
	t_philo				*philo;
}				t_param;

/*UTILS*/
unsigned long long	ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);

/*PARSING*/
int					init_mutex(t_param *param);
int					param_init(t_param *param, char **argv, int argc);
int					philo_init(t_param *param, int i);
int					parsing(t_param *param, char **argv, int argc);
int					check(int argc, t_param *param);
void				init_variable(t_param *param);

/*MAIN*/
int					main(int argc, char **argv);
void				simulation(t_param *param);
unsigned long long	gettime(void);

/*ROUTINE*/
int					ft_eat(t_philo	*philo);
void				take_a_meal(t_philo *philo);
void				ft_usleep(unsigned long long time);
void				*threadrout(void *arg);
void				print_event(t_param *param, char *message, int id);
void				reset_fork(t_philo *philo);
void				ft_think(t_philo *philo);

/*FREE*/
int					exit_parse(t_param *param, char *str);
void				ft_delone(void	*str);
int					exit_all_destroy(t_param *param, char *str);
int					exit_strerror(t_param *param, char *str);
int					join_and_destroy_thread(t_param *param);
int					destroy_mutex(t_param *param, pthread_mutex_t *mutex);

/*CHECK*/
int					check_die(t_philo *philo);
int					check_if_philo_dieded(t_param *param);
int					check_last_eat(t_param *param, int i);
int					check_rfork(t_philo *philo);
int					check_lfork(t_philo *philo);
unsigned long long	check_diff(unsigned long long last_eat);
int					exit_destroy_meal(t_param *param, char *str, int i);
int					exit_destroy_last_eat(t_param *param, char *str, int i);
int					exit_destroy_forks(t_param *param, char *str, int i);
int					check_rfork_first(t_philo *philo);

#endif