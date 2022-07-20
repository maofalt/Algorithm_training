/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:12:19 by motero            #+#    #+#             */
/*   Updated: 2022/07/20 18:09:09 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_instructions_parsing(t_stacks *stack)
{
	t_mov	mov;
	char	*str;
	size_t	total_moves;

	mov = stack->mov;
	total_moves = 0;
	total_moves += mov.swap.sa + mov.swap.sb + mov.swap.ss;
	total_moves += mov.a.ra + mov.a.rr + mov.b.rb;
	total_moves += mov.a.rra + mov.a.rrr + mov.b.rrb;
	total_moves += mov.swap.pa + mov.swap.pb;
	str = (char *)malloc(sizeof(char) * (stack->total_moves + 1));
	if (mov.swap.sa || mov.swap.sb || mov.swap.ss)
		ft_sorting_apply_swap(stack);
	if (mov.a.ra || mov.a.rr || mov.b.rb)
		ft_sorting_apply_rotation(stack);
	if (mov.a.rra || mov.a.rrr || mov.b.rrb)
		ft_sorting_apply_rev_rotation(stack);
	if (mov.swap.pa || mov.swap.pb)
		ft_sorting_apply_push(stack);
	stack->operations = (stack->operations, str);
	stack->total_moves += total_moves;
}

void	ft_instructions_print(t_stacks *stack, t_list list)
{
	t_node	*current;
	t_node	*tmp;
	t_node	*t;
	size_t	i;

	if (!list.size)
		return ;
	t = list.tail;
	current = list.head;
	i = 0;
	if (list.size < 3)
	{
		ft_printf("%i\n", current->data.index);
		ft_printf("%i\n", list.tail->data.index);
	}
	else
	{
		while (i++ < list.size)
		{
			ft_printf("I");
			tmp = XOR(current->npx, t);
			t = current;
			current = tmp;
		}
	}
}
