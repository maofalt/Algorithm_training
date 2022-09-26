/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions_one.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 06:38:12 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_calculate_size_three(t_stacks *stack)
{
	int		index[3];
	t_list	*list;

	list = stack->a;
	index[0] = list->xtrm.min.i;
	index[2] = list->xtrm.max.i;
	index[1] = 3 - index[0] - index[2];
	if (index[0] == 1 && index[1] == 0)
		stack->mov.swap.sa = 1;
	else if (index[2] == 0 && index[1] == 1)
	{
		stack->mov.swap.sa = 1;
		stack->mov.a.rra = 1;
	}
	else if (index[2] == 0 && index[0] == 1)
		stack->mov.a.ra = 1;
	else if (index[0] == 0 && index[2] == 1)
	{
		stack->mov.swap.sa = 1;
		stack->mov.a.ra = 1;
	}
	else
		stack->mov.a.rra = 1;
}

void	ft_calculate_size_three_wo_rot(t_stacks *stack)
{
	int		index[3];
	t_list	*list;

	list = stack->a;
	index[0] = list->xtrm.min.i;
	index[2] = list->xtrm.max.i;
	index[1] = 3 - index[0] - index[2];
	if (index[0] == 1 && index[1] == 0)
		stack->mov.swap.sa = 1;
	else if (index[2] == 0 && index[1] == 1)
		stack->mov.swap.sa = 1;
	else if (index[2] == 0 && index[0] == 1)
		return ;
	else if (index[0] == 0 && index[2] == 1)
		stack->mov.swap.sa = 1;
	else
		return ;
}

void	ft_calculate_sorting_size_five(t_stacks *stack)
{
	ft_extremes_find(stack->a);
	ft_pre_sorting_push_except_min_max(stack);
	ft_calculate_size_three_wo_rot(stack);
	ft_sorting_apply_operations(stack);
	while (stack->b->size)
	{
		ft_calculate_sorting_b_to_a(stack);
		ft_sorting_apply_operations(stack);
	}
	if (stack->a->head->data.final_index != 0)
	{
		ft_extremes_find(stack->a);
		stack->mov.a.ra += stack->a->xtrm.min.i;
		if (stack->mov.a.ra > stack->a->size / 2)
		{
			stack->mov.a.rra = stack->a->size - stack->mov.a.ra ;
			stack->mov.a.ra = 0 ;
		}
	}
	ft_sorting_apply_operations(stack);
}

// Calculate for each nbr is B stack the number of moves needed
// to be inserted in A Stack. We chose the one with the less
// amount of moves and we insert it
void	ft_calculate_sorting_b_to_a(t_stacks *stack)
{
	t_node	*c_b;
	t_node	*t_b;
	t_node	*min;
	size_t	i;

	c_b = stack->b->head;
	t_b = stack->b->tail;
	min = c_b;
	i = 0;
	while (i < stack->b->size)
	{
		ft_calculate_rot_to_fit(stack, c_b);
		ft_calculate_fix_rot_size(stack, c_b);
		c_b->mov.b.rb += i;
		c_b->nb_optn += i;
		if (min->nb_optn > c_b->nb_optn)
			min = c_b;
		if (min->mov.a.ra == 0 && min->mov.a.rra == 0)
			break ;
		ft_node_next(&c_b, &t_b);
		i++;
	}
	stack->mov = min->mov;
	stack->mov.swap.pa += 1;
}

// void	ft_cal_init_nodes(size_t (*f_b_fit)[2], t_node *c_b)
// {
// 	if (f_b_fit[0])
// 		c_b->mov.a.ra += c_b->nb_optn;
// 	else
// 		c_b->mov.a.rra += c_b->nb_optn;
// }
