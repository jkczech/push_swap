/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:21:39 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 18:25:35 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_few(t_stacks *stacks, int search)
{
	int		i;
	t_slist	*curr;

	i = 0;
	curr = stacks->a.top;
	while ((curr && curr->index != search))
	{
		i++;
		curr = curr->next;
	}
	if (i <= stacks->a.size / 2)
	{
		while (i-- > 0)
			ra(stacks, PRINT);
	}
	else
	{
		while (i++ < stacks->a.size)
			rra(stacks, PRINT);
	}
	pb(stacks);
	if (stacks->a.size == 4)
		return (sort_few(stacks, 1), pa(stacks));
	return (sort_three(stacks), pa(stacks));
}

int	sort_three(t_stacks *stacks)
{
	t_slist	*curr;
	t_slist	*max;

	curr = stacks->a.top;
	max = curr;
	while (curr)
	{
		if (curr->index > max->index)
			max = curr;
		curr = curr->next;
	}
	if (stacks->a.top == max)
		ra(stacks, PRINT);
	else if (max->next)
	{
		ra(stacks, PRINT);
		ra(stacks, PRINT);
	}
	if (is_sorted(stacks->a))
		return (1);
	return (sa(stacks, PRINT));
}
