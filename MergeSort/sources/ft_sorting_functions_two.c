/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_functions_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:51:03 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 21:28:01 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"
//Return a an array with the insructions or printf  at each action
//depedning size of stack
// if there are no moves we move first two to the stack b
void	ft_sorting_main(t_stacks *stack)
{
	if (stack->a->size == 1)
		return ;
	else if (stack->a->size == 2)
	{
		if (!ft_list_is_sorted(*stack->a))
			stack->mov.a.ra = 1;
	}
	else if (stack->a->size == 3)
	{
		if (!ft_list_is_sorted(*stack->a))
			ft_calculate_size_three(stack);
	}
	else if (stack->a->size > 3)
	{
		if (!ft_list_is_sorted(*stack->a))
			ft_calculate_sorting_size_five(stack);
	}
	ft_sorting_apply_operations(stack);
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
	else
	{
		i = 0;
		max = list.head->data.nb;
		while (i++ < list.size - 1)
		{
			next = xor(current->npx, t);
			if (max > next->data.nb)
				return (0);
			max = next->data.nb;
			t = current;
			current = next;
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
	t_mov	mov;

	mov = stack->mov;
	while (mov.a.ra)
	{
		ft_printf("ra\n");
		ft_list_rotate((stack->a));
		mov.a.ra--;
	}
	while (mov.a.rr)
	{
		ft_printf("rr\n");
		ft_list_rotate((stack->a));
		ft_list_rotate((stack->b));
		mov.a.rr--;
	}
	while (mov.b.rb)
	{
		ft_printf("rb\n");
		ft_list_rotate((stack->b));
		mov.b.rb--;
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
				ft_printf("rra\n");
			if (i == 1)
				ft_printf("rrr\n");
			if (i == 2)
				ft_printf("rrb\n");
			movs[i]--;
		}
		i++;
	}
}
