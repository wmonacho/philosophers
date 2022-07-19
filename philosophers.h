
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_grp
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosophers_must_eat;
}				t_grp;

void	init_variable(t_grp *philo);
int		ft_atoi(const char *str);
int		main(int argc, char **argv);
int		parsing(t_grp *philo, char **argv, int argc);
int		check(int argc);
void	ft_putstr_fd(char *s, int fd);
#endif