
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
	int					fork;
	unsigned long long	time_last_eat;
	pthread_mutex_t		check_fork;
	pthread_mutex_t		check_meal;
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
	int					nbr_of_times_each_philos_must_eat;
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
#endif