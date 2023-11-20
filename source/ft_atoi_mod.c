/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:54:03 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 18:10:08 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long int	ft_atoi_mod(const char *nptr, long int *result)
{
	int	i;
	int	sign;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n' \
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	*result = 0;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			*result = (*result * 10) + nptr[i] - '0';
		else
			return (0);
		i++;
	}
	*result = sign * *result;
	return (1);
}
