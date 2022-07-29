
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
	unsigned long long	time_last_eat;
	struct s_param		*param;

}				t_philo;
typedef struct s_param
{
	int					nbr_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					all_ate;
	int					dieded;
	int					number_of_times_each_philosophers_must_eat;
	unsigned long long	time;
	pthread_mutex_t		mutex_check;
	t_philo				philo[400];
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
#endif