/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:41:44 by flren             #+#    #+#             */
/*   Updated: 2025/08/07 16:21:56 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_valid_av(char *str)
{
	int	i;
	long value;

	i = 0;
	if (!str[i] || str[0] == '-')
		return (FAIL);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
		i++;
	}
	value = ft_atol(str);
	if (value == ERR_ATOL || value > INT_MAX)
		return (FAIL);
	return (SUCCESS);
}
int	ft_check_args(int ac, char **av)
{
	long value;
	int i;

	i = 1;
	value = ft_atol(av[i]);
	if (value == ERR_ATOL || value == 0)
	{
		if (value == 0 || value == ERR_ATOL)
			ft_error(MSG_0_PHILO, STDERR_FILENO);
		return (FAIL);
	}
	i++;
	while (i < ac)
	{
		if (ft_valid_av(av[i]) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}