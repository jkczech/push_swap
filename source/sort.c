/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:39:01 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/18 16:36:57 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort(t_stacks *stacks)
{
	if (is_sorted(stacks->a) && !stacks->b.top)
		return (1);
	set_index(&stacks->a);
	if (stacks->a.size == 2)
		return (sa(stacks, PRINT));
	if (stacks->a.size <= 3)
		sort_three(stacks);
	else if (stacks->a.size <= 5)
		sort_few(stacks, 0);
	else
		radix_sort(stacks);
	return (is_sorted(stacks->a) && !stacks->b.top);
}

int	is_sorted(t_stack stack)
{
	t_slist	*curr;

	if (!stack.top)
		return (0);
	curr = stack.top;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	set_index(t_stack *stack)
{
	int		i;
	t_slist	*min;
	t_slist	*curr;

	i = 0;
	while (i < stack->size)
	{
		curr = stack->top;
		while (curr && curr->index != -1)
			curr = curr->next;
		min = curr;
		if (!min)
			return (1);
		while (curr)
		{
			if (curr->index == -1 && curr->content < min->content)
				min = curr;
			curr = curr->next;
		}
		min->index = i;
		i++;
	}
	return (1);
}

int	radix_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	size;

	size = stacks->a.size;
	i = 0;
	while ((size >> i) > 0)
	{
		j = 0;
		while (j < size)
		{
			if (stacks->a.top && (stacks->a.top->index & (1 << i)))
				ra(stacks, PRINT);
			else if (j != size)
				pb(stacks);
			j++;
		}
		while (stacks->b.top)
			pa(stacks);
		i++;
	}
	return (1);
}
