#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "limits.h"
# include "pthread.h"
# include "sys/time.h"
# include "libft.h"

# define SUCCESS 0
# define FAIL 1

# define ERROR 1
# define ERR_ATOL -1

# define MSG_AC "Error !\n4 arguments required\n"
# define MSG_AV "Error !\nInvalid Arguments !\n"
# define MSG_0_PHILO "Error !\nYou need at least one Philosopher !\n"
# define MSG_INIT_PRINT "Error !\nFail init print mutex !\n"

typedef struct s_data
{
	int	nb_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int meals_required;

	int	someone_died;
	unsigned long start_time;

	pthread_mutex_t print_mutex;
}	t_data;

typedef struct s_philo 
{
	int	id_philo;
	int	nb_eat;
	unsigned long time_last_meal;
	pthread_t thread;
	pthread_mutex_t left_fork;
	pthread_mutex_t *right_fork;
	t_data *data;
}	t_philo;

void	ft_error(char *err_msg, int err_nb);
int	ft_check_args(int ac, char **av);
long	ft_atol(const char *str);

#endif