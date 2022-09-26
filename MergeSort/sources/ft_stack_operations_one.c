/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:05 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 03:15:40 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_stack_swap(t_stacks *stack)
{
	if ((stack->mov.swap.sa || stack->mov.swap.ss) && stack->a->size > 1)
		ft_list_swap_first_nodes(stack->a);
	if ((stack->mov.swap.sb || stack->mov.swap.ss) && stack->b->size > 1)
		ft_list_swap_first_nodes(stack->b);
}

void	ft_stack_push(t_stacks *stack)
{
	if (stack->mov.swap.pa && stack->b->size > 0)
		ft_list_cut_past(stack->b, stack->a);
	if (stack->mov.swap.pb && stack->a->size > 0)
		ft_list_cut_past(stack->a, stack->b);
}

void	ft_stack_rotate(t_stacks *stack)
{
	if ((stack->mov.a.ra || stack->mov.a.rr) && stack->a->size > 1)
		ft_list_rotate((stack->a));
	if ((stack->mov.b.rb || stack->mov.a.rr) && stack->b->size > 1)
		ft_list_rotate((stack->b));
}

void	ft_stack_reverse_rotate(t_stacks *stack)
{
	if ((stack->mov.a.rra || stack->mov.a.rrr) && stack->a->size > 1)
		ft_list_reverse_rotate(stack->a);
	if ((stack->mov.b.rrb || stack->mov.a.rrr) && stack->b->size > 1)
		ft_list_reverse_rotate(stack->b);
}

t_stacks	*ft_stack_initilize(t_list *list_a)
{
	t_stacks	*stack;
	t_list		*list_b;

	stack = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stack)
	{
		ft_list_free(list_a);
		free(list_a);
		return (NULL);
	}
	stack->a = list_a;
	list_b = ft_list_create(NULL, NULL, 0);
	if (!list_b)
	{
		ft_list_free(list_a);
		free(list_a);
		free(stack);
		return (NULL);
	}
	stack->b = list_b;
	stack->mov = ft_mov_initiliaze();
	stack->total_moves = 0;
	return (stack);
}
