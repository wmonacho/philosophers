
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_grp
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	unsigned long long	all_ate;
	unsigned long long	dieded;
	unsigned long long	number_of_times_each_philosophers_must_eat;
	unsigned long long	time;
}				t_grp;

void				init_variable(t_grp *philo);
int					ft_atoi(const char *str);
int					main(int argc, char **argv);
int					parsing(t_grp *philo, char **argv, int argc);
int					check(int argc, t_grp *philo);
void				ft_putstr_fd(char *s, int fd);
unsigned long long	ft_gettime(void);
int					exit_strerror(t_grp *philo, char *str);
void				simulation(t_grp *philo);
#endif