/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:34:29 by flren             #+#    #+#             */
/*   Updated: 2025/06/25 20:10:57 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *err_msg, int err_nb)
{
	ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(err_nb);
}

static int	ft_valid_av(char *str)
{
	int	i;
	long size;

	i = 0;
	if (str[0] == '-' || !str[i])
		return (FAIL);
	while (str[i])
	{
		if (i > 10)
			return (FAIL);
		if (!ft_isdigit(str[i]))
			return (FAIL);
	}
	size = ft_atol(str);
	if (size > INT_MAX)
		return (FAIL);
	return (SUCCESS);
}
int	ft_check_args(int ac, char **av)
{
	int i;

	i = 1;
	if (ft_atoi(av[i]) > MAX_PHILO)
	{
		ft_error(MSG_MAX_PHILO, STDERR_FILENO);
		return (FAIL);
	}
	while (i < ac)
	{
		if (ft_valid_av(av[i]) == FAIL)
		{
			ft_error("Error !\nInvalid Arguments !\n", STDERR_FILENO);
		}
	}
}
