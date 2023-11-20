/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:16:43 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/18 17:09:59 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../library/printf/include/ft_printf.h"
# include "../library/libft/include/libft.h"

# define PRINT	666
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "structures.h"

//stack.c
t_stacks	init_stacks(void);
t_slist		*pop(t_stack *stack);
int			push(t_stack *stack, t_slist *new);
int			swap(t_stack *stack);
t_slist		*second_last(t_stack *stack);

//operations1.c
int			sa(t_stacks *stacks, int print);
int			sb(t_stacks *stacks, int print);
int			ss(t_stacks *stacks);
int			pa(t_stacks *stacks);
int			pb(t_stacks *stacks);

//operations2.c
int			push_back(t_stack *stack, t_slist *new);
int			ra(t_stacks *stacks, int print);
int			rb(t_stacks *stacks, int print);
int			rr(t_stacks *stacks);

//operations3.c
t_slist		*pop_back(t_stack *stack);
int			rra(t_stacks *stacks, int print);
int			rrb(t_stacks *stacks, int print);
int			rrr(t_stacks *stacks);

//print.c
void		print_stacks(t_stacks stacks);
void		print_stack(t_stack stack, char *name);

//sort.c
int			sort(t_stacks *stacks);
int			is_sorted(t_stack stack);
int			set_index(t_stack *stack);
int			radix_sort(t_stacks *stacks);

//sort_few.c
int			sort_few(t_stacks *stacks, int search);
int			sort_three(t_stacks *stacks);

//main.c
int			load_input(int argc, char **argv, t_stack *stack, int i);
int			check_input(t_stack stack);
t_slist		*new_slist(long long content);

//free.c
int			free_stacks(t_stacks *stacks);
int			free_stack(t_stack *stack);
int			free_array(char **array);

//ft_atoi.c
long int	ft_atoi_mod(const char *nptr, long int *result);
#endif