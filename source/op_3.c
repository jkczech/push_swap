/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:32:05 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:07:53 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pop an element from the bottom of stack
t_slist	*pop_back(t_stack *stack)
{
	t_slist	*popped;
	t_slist	*sec_last;

	sec_last = second_last(stack);
	popped = sec_last->next;
	sec_last->next = NULL;
	stack->size--;
	return (popped);
}

//rotate stack a, the last element becomes the first
int	rra(t_stacks *stacks, int print)
{
	t_slist	*last;

	if (!stacks->a.top->next)
		return (1);
	last = pop_back(&stacks->a);
	push(&stacks->a, last);
	if (print == PRINT)
		ft_printf("rra\n");
	return (1);
}

//rotate stack b, the last element becomes the first
int	rrb(t_stacks *stacks, int print)
{
	t_slist	*last;

	if (!stacks->b.top->next)
		return (1);
	last = pop_back(&stacks->b);
	push(&stacks->b, last);
	if (print == PRINT)
		ft_printf("rrb\n");
	return (1);
}

//rotate stacks a and b, the last elements becomes the first
int	rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	return (rra(stacks, 0), rrb(stacks, 0));
}
