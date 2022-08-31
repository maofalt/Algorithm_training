/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:51:03 by motero            #+#    #+#             */
/*   Updated: 2022/08/31 22:47:56 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"
//Return a an array with the insructions or printf  at each action
//depedning size of stack
// if there are no moves we move first two to the stack b
void	ft_sorting_main(t_stacks *stack)
{
	size_t	sorted;

	sorted = ft_list_is_sorted(*stack->a);
	if (stack->a->size == 1)
		stack->operations = NULL;
	else if (stack->a->size == 2)
	{
		if (sorted)
			stack->operations = NULL;
		else
		{
			stack->mov.a.ra = 1;
			ft_sorting_apply_operations(stack);
		}
	}
	else if (stack->a->size == 3)
	{
		if (sorted)
			stack->operations = NULL;
		else
		{
			ft_calculate_size_three(stack);
			ft_sorting_apply_operations(stack);
		}
	}
	else if (stack->a->size > 3)
	{
		if (sorted && stack->a->xtrm.min.i == 0)
			return ;
		else if (sorted && stack->a->xtrm.min.i != 0)
		{
			stack->mov.a.ra += stack->a->xtrm.min.i;
			if (stack->mov.a.ra > stack->a->size / 2)
			{
				stack->mov.a.rra = stack->a->size - stack->mov.a.ra ;
				stack->mov.a.ra = 0 ;
			}
			ft_sorting_apply_operations(stack);
		}
		else
		{
			ft_calculate_sorting_size_five(stack);
			ft_sorting_apply_operations(stack);
		}
	}
	stack->total_moves++;
}

// int	ft_list_is_sorted(t_list list)
// {
// 	size_t			i;
// 	int				max;
// 	t_node			*current;
// 	t_node			*next;
// 	t_node			*t;

// 	t = list.tail;
// 	current = list.head;
// 	if (list.size == 1)
// 		return (1);
// 	else if (list.size == 2)
// 		return (list.head->data.nb < list.tail->data.nb);
// 	else
// 	{
// 		i = 0;
// 		max = list.head->data.nb;
// 		while (i < list.size - 1)
// 		{
// 			next = XOR(current->npx, t);
// 			if (max > next->data.nb)
// 				return (0);
// 			max = next->data.nb;
// 			t = current;
// 			current = next;
// 			i++;
// 		}
// 		return (1);
// 	}
// }

int	ft_list_is_sorted(t_list list)
{
	size_t			i;
	int				max;
	t_node			*current;
	t_node			*next;
	t_node			*t;

	t = list.xtrm.min.tail;
	current = list.xtrm.min.node;
	if (list.size == 1)
		return (1);
	else if (list.size == 2)
		return (1);
	else
	{
		i = 0;
		max = list.xtrm.min.nb;
		while (i < list.size - 1)
		{
			next = XOR(current->npx, t);
			if (max > next->data.nb)
				return (0);
			max = next->data.nb;
			t = current;
			current = next;
			i++;
		}
		return (1);
	}
}

void	ft_sorting_apply_operations(t_stacks *stack)
{
	t_mov	mov;

	mov = stack->mov;
	ft_move_compound_rotation(stack);
	ft_move_compound_swap(stack);
	stack->total_moves += ft_instructions_parsing(stack);
	if (mov.swap.sa || mov.swap.sb || mov.swap.ss)
		ft_sorting_apply_swap(stack);
	if (mov.a.ra || mov.a.rr || mov.b.rb)
		ft_sorting_apply_rotation(stack);
	if (mov.a.rra || mov.a.rrr || mov.b.rrb)
		ft_sorting_apply_rev_rotation(stack);
	if (mov.swap.pa || mov.swap.pb)
		ft_sorting_apply_push(stack);
	stack->mov = ft_mov_initiliaze();
}

void	ft_sorting_apply_rotation(t_stacks *stack)
{
	int		movs[3];
	t_mov	mov;
	int		i;

	mov = stack->mov;
	movs[0] = mov.a.ra;
	movs[1] = mov.a.rr;
	movs[2] = mov.b.rb;
	i = 0;
	while (i < 3)
	{
		while (movs[i])
		{
			//ft_stack_rotate(stack);
			if (i == 0)
			{
				//stack->operations = ft_strjoin_w_free(stack->operations, "ra\n");
				ft_printf("ra\n");
				ft_list_rotate((stack->a));
			}
			if (i == 1)
			{
				//stack->operations = ft_strjoin_w_free(stack->operations, "rr\n");
				ft_printf("rr\n");
				ft_list_rotate((stack->a));
				ft_list_rotate((stack->b));
			}
			if (i == 2)
			{
				//stack->operations = ft_strjoin_w_free(stack->operations, "rb\n");
				ft_printf("rb\n");
				ft_list_rotate((stack->b));
			}
			movs[i]--;
		}
		i++;
	}
}

void	ft_sorting_apply_rev_rotation(t_stacks *stack)
{
	int		movs[3];
	t_mov	mov;
	int		i;

	mov = stack->mov;
	movs[0] = mov.a.rra;
	movs[1] = mov.a.rrr;
	movs[2] = mov.b.rrb;
	i = 0;
	while (i < 3)
	{
		while (movs[i])
		{
			ft_stack_reverse_rotate(stack);
			if (i == 0)
				//stack->operations = ft_strjoin_w_free(stack->operations, "rra\n");
				ft_printf("rra\n");
			if (i == 1)
				//stack->operations = ft_strjoin_w_free(stack->operations, "rrr\n");
				ft_printf("rrr\n");
			if (i == 2)
				//stack->operations = ft_strjoin_w_free(stack->operations, "rrb\n");
				ft_printf("rrb\n");
			movs[i]--;
		}
		i++;
	}
}

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
				//stack->operations = ft_strjoin_w_free(stack->operations, "sa\n");
				ft_printf("sa\n");
			if (i == 1)
				//stack->operations = ft_strjoin_w_free(stack->operations, "sb\n");
				ft_printf("sb\n");
			if (i == 2)
				//stack->operations = ft_strjoin_w_free(stack->operations, "ss\n");
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
				//stack->operations = ft_strjoin_w_free(stack->operations, "pa\n");
				ft_printf("pa\n");
			if (i == 1)
				//stack->operations = ft_strjoin_w_free(stack->operations, "pb\n");
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
	t_node	*seq;
	size_t	size;

	list = stack->a;
	current = stack->a->head;
	tail = stack->a->tail;
	size = 0;
	seq = current;
	ft_extremes_find(stack->a);
	ft_pre_sorting_find_big_seq(stack, seq, &size);
	if (list->xtrm.min.i - list->xtrm.max.i == 1)
		size = 2;
	else
		size += 2;
	//printf("numbrs to keep %zu\n", size);
	while (list->size > size)
	{
		if (current == list->xtrm.min.node || current == list->xtrm.max.node || current->to_keep == 1)
		{
		//	printf("Number to keep %d\n", current->data.nb);
			stack->mov.a.ra = 1;
			current->to_keep = 0;
			ft_node_next(&current, &tail);
		}
		else
		{
			stack->mov.swap.pb = 1;
			current = XOR(current->npx, tail);
		}
		ft_sorting_apply_operations(stack);
	}
	// printf("\nStack A\n");
	// ft_list_print_data(*stack->a);
	// printf("\nStack B\n");
	// ft_list_print_data(*stack->b);
	ft_extremes_find(stack->a);
}

void	ft_pre_sorting_find_big_seq(t_stacks *stack, t_node *seq, size_t *size)
{
	size_t			i;
	t_node			*current;
	t_node			*next;
	t_node			*t;
	t_node			*t_seq;
	t_node			*max;
	t_node			*t_max;

	t = stack->a->xtrm.min.tail;
	current = stack->a->xtrm.min.node;
	i = 1;
	*size = 1;
	next = XOR(current->npx, t);
	seq = stack->a->xtrm.min.node;
	t_seq = stack->a->xtrm.min.tail;
	max = stack->a->xtrm.min.node;
	t_max = stack->a->xtrm.min.tail;
	while (next != stack->a->xtrm.max.node)
	{
		//printf("--------------\nIs %d > %d ?\n", next->data.nb, current->data.nb);
		if (next->data.nb > current->data.nb)
		{
			i++;
			if (i > *size)
			{
				*size = i;
				seq = max;
				t_seq = t_max;
			}
			//printf("New max %d find for seq starting at %d, with length %zu\n", next->data.nb , max->data.nb, i);
		}
		else
		{
			//printf("No new max\n");
			if (i > *size)
				*size = i;
			i = 1;
			t_max = current;
			max = XOR(current->npx, t);
		}
		ft_node_next(&current, &t);
		next = XOR(current->npx, t);
	}
	if (seq == stack->a->xtrm.min.node)
		*size = *size - 1;
	if (seq == stack->a->xtrm.max.node)
		*size = *size - 1;
//	printf("Best big seq starting at %d, with length %zu\n", seq->data.nb, *size);
	i = 0;
	while (i < *size)
	{
		seq->to_keep = 1;
		//printf("nb to keep %d\n", seq->data.nb);
		ft_node_next (&seq, &t_seq);
		i++;
	}
}

// void	ft_pre_sorting_push_except_min_max(t_stacks *stack)
// {
// 	t_list	*list;
// 	t_node	*current;
// 	t_node	*tail;
// 	t_node	*tmp;

// 	list = stack->a;
// 	current = stack->a->head;
// 	tail = stack->a->tail;
// 	while (list->size > 3)
// 	{
// 		if (current->data.final_index == 0 || current->data.nb == list->xtrm.max.nb)
// 		{
// 			stack->mov.a.ra = 1;
// 			tmp = XOR(current->npx, tail);
// 			tail = current;
// 			current = tmp;
// 		}
// 		else
// 		{
// 			stack->mov.swap.pb = 1;
// 			current = XOR(current->npx, tail);
// 		}
// 		ft_sorting_apply_operations(stack);
// 	}
// 	ft_extremes_find(stack->a);
// }
