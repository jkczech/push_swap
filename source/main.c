/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:14:43 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/18 17:11:11 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (1);
	stacks = init_stacks();
	if (!load_input(argc, argv, &stacks.a, 1))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!check_input(stacks.a))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!sort(&stacks))
		return (ft_putstr_fd("Error\n", 2), 1);
	free_stacks(&stacks);
	return (0);
}

int	load_input(int argc, char **argv, t_stack *stack, int i)
{
	long int	num;
	char		**split;
	int			res;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		res = load_input(-1, split, stack, 0);
		free(split);
		return (res);
	}
	while ((argc == -1 && argv[i]) || i < argc)
	{
		res = ft_atoi_mod(argv[i], &num);
		if (!res || res < INT_MIN || res > INT_MAX
			|| ft_strlen(argv[i]) > 11 || !push_back(stack, new_slist(num)))
			return (0);
		i++;
	}
	if (argc == -1)
		free_array(argv);
	return (1);
}

int	check_input(t_stack stack)
{
	t_slist	*curr;
	t_slist	*checked;

	curr = stack.top;
	while (curr)
	{
		if (curr->content > INT_MAX || curr->content < INT_MIN)
			return (0);
		curr = curr->next;
	}
	checked = stack.top;
	while (checked)
	{
		curr = checked->next;
		while (curr)
		{
			if (checked->content == curr->content)
				return (0);
			curr = curr->next;
		}
		checked = checked->next;
	}
	return (1);
}

t_slist	*new_slist(long long content)
{
	t_slist	*list;

	list = (t_slist *)malloc(sizeof(t_slist));
	if (!list)
		return (0);
	list->content = content;
	list->index = -1;
	list->next = NULL;
	return (list);
}
