/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:20:27 by flren             #+#    #+#             */
/*   Updated: 2025/08/05 17:55:01 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		ft_error(MSG_AC, ERROR);
	if (ft_check_args(ac, av) == FAIL)
		ft_error(MSG_AV, ERROR);
	(void)data;
	return (SUCCESS);
}
