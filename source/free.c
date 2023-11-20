/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:27:09 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/18 16:44:19 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	free_stacks(t_stacks *stacks)
{
	free_stack(&stacks->a);
	free_stack(&stacks->b);
	return (1);
}

int	free_stack(t_stack *stack)
{
	t_slist	*curr;

	while (stack->top)
	{
		curr = pop(stack);
		free(curr);
	}
	return (1);
}

int	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	return (1);
}
