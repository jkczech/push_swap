/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:06:50 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/17 16:06:55 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_slist
{
	long long		content;
	int				index;
	struct s_slist	*next;
}	t_slist;

typedef struct s_stack
{
	t_slist	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;
