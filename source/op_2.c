/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:32:08 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:08:00 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pushing an element to the bottom of stack
int	push_back(t_stack *stack, t_slist *new)
{
	t_slist	*last;

	if (!new || !stack)
		return (0);
	last = stack->top;
	if (!last)
	{
		stack->top = new;
		stack->size++;
		return (1);
	}
	while (last->next)
		last = last->next;
	last->next = new;
	stack->size++;
	return (1);
}

//rotate stack a, the first element becomes the last
int	ra(t_stacks *stacks, int print)
{
	t_slist	*popped;

	if (!stacks->a.top->next)
		return (1);
	popped = pop(&stacks->a);
	push_back(&stacks->a, popped);
	if (print == PRINT)
		ft_printf("ra\n");
	return (1);
}

//rotate stack b, the first element becomes the last
int	rb(t_stacks *stacks, int print)
{
	t_slist	*popped;

	if (!stacks->b.top->next)
		return (1);
	popped = pop(&stacks->a);
	push_back(&stacks->a, popped);
	if (print == PRINT)
		ft_printf("rb\n");
	return (1);
}

//rotate stacks a and b, the first elements become the last
int	rr(t_stacks *stacks)
{
	ft_printf("rr\n");
	return (ra(stacks, 0), rb(stacks, 0));
}
