/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:44:48 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 17:31:43 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.a.top = NULL;
	stacks.a.size = 0;
	stacks.b.top = NULL;
	stacks.b.size = 0;
	return (stacks);
}

t_slist	*pop(t_stack *stack)
{
	t_slist	*popped;

	if (!stack->top)
		return (NULL);
	popped = stack->top;
	stack->top = stack->top->next;
	popped->next = NULL;
	stack->size--;
	return (popped);
}

int	push(t_stack *stack, t_slist *new)
{
	new->next = stack->top;
	stack->top = new;
	stack->size++;
	return (1);
}

int	swap(t_stack *stack)
{
	t_slist	*popped1;
	t_slist	*popped2;

	if (!stack->top->next || !stack->top->next->next)
		return (1);
	popped1 = pop(stack);
	popped2 = pop(stack);
	push(stack, popped1);
	push(stack, popped2);
	return (1);
}

t_slist	*second_last(t_stack *stack)
{
	t_slist	*ret;

	ret = stack->top;
	while (ret->next && ret->next->next)
		ret = ret->next;
	return (ret);
}
