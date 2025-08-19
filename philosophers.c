/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student->42->fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:20:27 by flren             #+#    #+#             */
/*   Updated: 2025/08/07 17:42:11 by flren            ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->meals_required = ft_atol(av[5]);
	else 
		data->meals_required = -1;
	data->someone_died = 0;
	data->start_time = 0;

	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	ft_init_philo(t_philo **philo, t_data *data)
{
	int i;

	*philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (!(*philo))
		return (FAIL);
	i = 0;
	while (i < data->nb_philos)
	{
		(*philo)[i].id_philo = i + 1;
		(*philo)[i].nb_eat = 0;
		(*philo)[i].time_last_meal = 0;
		(*philo)[i].data = data;

		if (pthread_mutex_init(&(*philo)[i].left_fork, NULL) != 0)
			return (FAIL);
		
	}
	
	
}
int	main(int ac, char **av)
{
	t_data	data;
	t_philo *philo;

	if (ac != 5 && ac != 6)
		ft_error(MSG_AC, ERROR);
	if (ft_check_args(ac, av) == FAIL)
		ft_error(MSG_AV, ERROR);
	if (ft_init_data(&data, ac, av) == FAIL)
		ft_error(MSG_INIT_DATA, ERROR);
	if (ft_init_philo(&philo, &data) == FAIL)
		ft_error(MSG_INIT_PHILO, ERROR);
	return (SUCCESS);
}
