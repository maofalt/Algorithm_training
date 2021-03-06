/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:51:03 by motero            #+#    #+#             */
/*   Updated: 2022/07/20 17:55:00 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"
//Return a an array with the insructions or printf  at each action
//depedning size of stack
// if there are no moves we move first two to the stack b
void	ft_sorting_main(t_stacks *stack)
{
	if (stack->a->size == 1)
		stack->operations = NULL;
	else if (stack->a->size == 2)
	{
		if (ft_list_is_sorted(*stack->a))
			stack->operations = NULL;
		else
		{
			stack->mov.a.ra = 1;
			ft_sorting_apply_operations(stack);
		}
	}
	else if (stack->a->size == 3)
	{
		if (ft_list_is_sorted(*stack->a))
			stack->operations = NULL;
		else
		{
			ft_calculate_size_three(stack);
			ft_sorting_apply_operations(stack);
		}
	}
	else if (stack->a->size =<5)
	{
		if (ft_list_is_sorted(*stack->a))
			stack->operations = NULL;
		else
		{
			ft_calculate_sorting(stack);
			ft_sorting_apply_operations(stack);
		}
	}
	else if (stack->a->size > 5)
	{
		if (ft_list_is_sorted(*stack->a))
			stack->operations = NULL;
		else
		{
			stack->mov.a.ra = 1;
			ft_sorting_apply_operations(stack);
		}
	}
	stack->total_moves++;
}

int	ft_list_is_sorted(t_list list)
{
	size_t			i;
	int				max;
	t_node			*current;
	t_node			*next;
	t_node			*t;

	t = list.tail;
	current = list.head;
	if (list.size == 1)
		return (1);
	else if (list.size == 2)
		return (list.head->data.nb < list.tail->data.nb);
	else
	{
		i = 0;
		max = list.head->data.nb;
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
	ft_move_compound_rotation(*stack);
	ft_move_compound_swap(*stack);
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
			ft_stack_rotate(stack);
			if (i == 0)
				stack->operations = ft_strjoin(stack->operations, "ra\n");
			if (i == 1)
				stack->operations = ft_strjoin(stack->operations, "rr\n");
			if (i == 2)
				stack->operations = ft_strjoin(stack->operations, "rb\n");
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
				stack->operations = ft_strjoin(stack->operations, "rra\n");
			if (i == 1)
				stack->operations = ft_strjoin(stack->operations, "rrr\n");
			if (i == 2)
				stack->operations = ft_strjoin(stack->operations, "rrb\n");
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
				stack->operations = ft_strjoin(stack->operations, "sa\n");
			if (i == 1)
				stack->operations = ft_strjoin(stack->operations, "sb\n");
			if (i == 2)
				stack->operations = ft_strjoin(stack->operations, "ss\n");
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
				stack->operations = ft_strjoin(stack->operations, "pa\n");
			if (i == 1)
				stack->operations = ft_strjoin(stack->operations, "pb\n");
			movs[i]--;
		}
		i++;
	}
}
