/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:24:47 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 19:06:15 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//swap top two in stack a
int	sa(t_stacks *stacks, int print)
{
	if (print == PRINT)
		ft_printf("sa\n");
	return (swap(&stacks->a));
}

//swap top two in stack b
int	sb(t_stacks *stacks, int print)
{
	if (print == PRINT)
		ft_printf("sb\n");
	return (swap(&stacks->b));
}

//swap top two in stack a and b
int	ss(t_stacks *stacks)
{
	ft_printf("ss\n");
	return (sa(stacks, 0), sb(stacks, 0));
}

//push from b to a
int	pa(t_stacks *stacks)
{
	t_slist	*popped;

	popped = pop(&stacks->b);
	push(&stacks->a, popped);
	ft_printf("pa\n");
	return (1);
}

//push from a to b
int	pb(t_stacks *stacks)
{
	t_slist	*popped;

	popped = pop(&stacks->a);
	if (!popped)
		return (0);
	push(&stacks->b, popped);
	ft_printf("pb\n");
	return (1);
}
