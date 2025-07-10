#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "limits.h"
# include "libft.h"
# include "pthread.h"
# include "sys/time.h"

# define SUCCESS 0
# define FAIL 1

# define MAX_PHILO 200
# define ERR_AC 1

# define MSG_AC "Error !\n4 arguments required\n"
# define MSG_MAX_PHILO "Error !\nExceed Max Number of Philosophers !\n"

typedef struct s_philo t_philo;

typedef struct s_data
{
	int	nb_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int meals_required;

	int	someone_died;
	unsigned long start_time;

	pthread_mutex_t *fork;
	pthread_mutex_t print_mutex;
}	t_data;

void	ft_error(char *err_msg, int err_nb);
int	ft_atol(char *str);

#endif