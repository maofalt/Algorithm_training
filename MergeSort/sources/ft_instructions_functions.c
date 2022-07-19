/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:12:19 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 14:59:15 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_instructions_parsing(t_stacks *stack)
{
	t_mov	mov;

	mov = stack->mov;
	stack->total_moves += mov.swap.sa + mov.swap.sb + mov.swap.ss;
	stack->total_moves += mov.a.ra + mov.a.rr + mov.b.rb;
	stack->total_moves += mov.a.rra + mov.a.rrr + mov.b.rrb;
	stack->total_moves += mov.swap.pa + mov.swap.pb;
	stack->operations = (char *)malloc(sizeof(char) * (stack->total_moves + 1));
	if (mov.swap.sa || mov.swap.sb || mov.swap.ss)
		ft_sorting_apply_swap(stack);
	if (mov.a.ra || mov.a.rr || mov.b.rb)
		ft_sorting_apply_rotation(stack);
	if (mov.a.rra || mov.a.rrr || mov.b.rrb)
		ft_sorting_apply_rev_rotation(stack);
	if (mov.swap.pa || mov.swap.pb)
		ft_sorting_apply_push(stack);
}
