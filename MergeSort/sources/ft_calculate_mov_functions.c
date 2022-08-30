/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/08/30 19:57:03 by motero           ###   ########.fr       */
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
	//printf("Min %d Max %d \n", stack->a->xtrm.min.nb, stack->a->xtrm.max.nb);
	ft_pre_sorting_push_except_min_max(stack);
	//ft_list_print_data(*stack->a);
	ft_calculate_size_three_wo_rot(stack);
	ft_sorting_apply_operations(stack);
	//ft_list_print_data(*stack->a);
	while (stack->b->size)
	{
		ft_calculate_sorting_b_to_a(stack);
		ft_sorting_apply_operations(stack);
		//ft_printf("%s", stack->operations);
		// printf("\nSTACK A\n");
		// ft_list_print_data(*stack->a);
		// printf("\nSTACK B\n");
		// ft_list_print_data(*stack->b);
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

/* Calculate for each nbr is B stack the number of moves needed to be inserted in A Stack. We chose the one with the less amount of moves and we insert it.*/
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

// void	ft_calculate_rot_to_fit(t_stacks *stack, t_node *c_b)
// {
// 	t_node	*c_a;
// 	t_node	*t_a;

// 	c_a = stack->a->head;
// 	t_a = stack->a->tail;
// 	c_b->nb_optn = 0;
// 	c_b->mov = ft_mov_initiliaze();
// 	while (c_b->mov.a.ra < stack->a->size)
// 	{
// 		if (c_b->data.nb < c_a->data.nb && c_b->data.nb > t_a->data.nb)
// 			break ;
// 		c_b->mov.a.ra += 1;
// 		c_b->nb_optn++;
// 		ft_node_next(&c_a, &t_a);
// 	}
// }

void	ft_calculate_rot_to_fit(t_stacks *stack, t_node *c_b)
{
	t_node	*fc_a;
	t_node	*ft_a;
	t_node	*bc_a;
	t_node	*bt_a;
	size_t	forward_fit;
	size_t	backward_fit;

	fc_a = stack->a->head;
	ft_a = stack->a->tail;
	bc_a = stack->a->tail;
	bt_a = stack->a->head;
	forward_fit = 0;
	backward_fit = 0;
	c_b->nb_optn = 0;
	c_b->mov = ft_mov_initiliaze();
	while (forward_fit == 0 && backward_fit == 0)
	{
		if (c_b->data.nb < fc_a->data.nb && c_b->data.nb > ft_a->data.nb)
			forward_fit = 1;
		else if (c_b->data.nb > bc_a->data.nb && c_b->data.nb < bt_a->data.nb)
			backward_fit = 1;
		else
		{
			c_b->nb_optn++;
			ft_node_next(&fc_a, &ft_a);
			ft_node_next(&bc_a, &bt_a);
		}
	}
	if (forward_fit)
		c_b->mov.a.ra += c_b->nb_optn;
	else
		c_b->mov.a.rra += c_b->nb_optn;
}

void	ft_calculate_fix_rot_size(t_stacks *stack, t_node *c_b)
{
	if (c_b->mov.a.ra >= stack->a->size)
	{
		c_b->nb_optn -= (c_b->mov.a.ra - 1);
		c_b->mov.a.ra = 0;
	}
	if (c_b->mov.a.ra > stack->a->size / 2)
	{
		c_b->mov.a.rra = stack->a->size - c_b->mov.a.ra ;
		c_b->nb_optn -= (c_b->mov.a.ra - c_b->mov.a.rra);
		c_b->mov.a.ra = 0 ;
	}
}

void	ft_node_next(t_node **c, t_node **t)
{
	t_node	*tmp;

	tmp = XOR((*c)->npx, (*t));
	(*t) = (*c);
	(*c) = tmp;
}
