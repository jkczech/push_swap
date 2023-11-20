/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:24 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 13:11:49 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stacks(t_stacks stacks)
{
	print_stack(stacks.a, "A");
	print_stack(stacks.b, "B");
}

void	print_stack(t_stack stack, char *name)
{
	t_slist	*curr;

	ft_printf("Stack %s with size %d: TOP ", name, stack.size);
	curr = stack.top;
	if (!curr)
		ft_printf("Empty ");
	while (curr)
	{
		ft_printf("(%d:%d) ", curr->content, curr->index);
		curr = curr->next;
	}
	ft_printf("\n");
}
