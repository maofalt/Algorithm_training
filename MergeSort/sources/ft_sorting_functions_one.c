/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_functions_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:51:03 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 04:09:04 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_sorting_apply_swap(t_stacks *stack)
{
	int		movs[3];
	t_mov	mov;
	int		i;

	mov = stack->mov;
	movs[0] = mov.swap.sa;
	movs[1] = mov.swap.sb;
	movs[2] = mov.swap.ss;
	i = 0;
	while (i < 3)
	{
		while (movs[i])
		{
			ft_stack_swap(stack);
			if (i == 0)
				ft_printf("sa\n");
			if (i == 1)
				ft_printf("sb\n");
			if (i == 2)
				ft_printf("ss\n");
			movs[i]--;
		}
		i++;
	}
}

void	ft_sorting_apply_push(t_stacks *stack)
{
	int		movs[2];
	t_mov	mov;
	int		i;

	mov = stack->mov;
	movs[0] = mov.swap.pa;
	movs[1] = mov.swap.pb;
	i = 0;
	while (i < 2)
	{
		while (movs[i])
		{
			ft_stack_push(stack);
			if (i == 0)
				ft_printf("pa\n");
			if (i == 1)
				ft_printf("pb\n");
			movs[i]--;
		}
		i++;
	}
}

void	ft_pre_sorting_push_except_min_max(t_stacks *stack)
{
	t_list	*list;
	t_node	*current;
	t_node	*tail;

	list = stack->a;
	current = stack->a->head;
	tail = stack->a->tail;
	while (list->size > 3)
	{
		if (current->data.final_index == 0
			|| current->data.nb == list->xtrm.max.nb)
		{
			stack->mov.a.ra = 1;
			ft_node_next(&current, &tail);
		}
		else
		{
			stack->mov.swap.pb = 1;
			current = xor(current->npx, tail);
		}
		ft_sorting_apply_operations(stack);
	}
	ft_extremes_find(stack->a);
}
