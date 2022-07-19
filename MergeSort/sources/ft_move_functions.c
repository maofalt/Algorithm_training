/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 14:47:00 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_mov	ft_mov_initiliaze(void)
{
	t_mov	new_mov;

	new_mov.swap.sa = 0;
	new_mov.swap.sb = 0;
	new_mov.swap.ss = 0;
	new_mov.swap.pa = 0;
	new_mov.swap.pb = 0;
	new_mov.a.ra = 0;
	new_mov.b.rb = 0;
	new_mov.a.rra = 0;
	new_mov.b.rrb = 0;
	new_mov.a.rr = 0;
	new_mov.a.rrr = 0;
	return (new_mov);
}

void	ft_move_compound_rotation(t_stacks stack)
{
	size_t	min;

	if (stack.mov.a.ra && stack.mov.b.rb)
	{
		if (stack.mov.a.ra > stack.mov.b.rb)
			min = stack.mov.b.rb;
		else
			min = stack.mov.a.ra;
		stack.mov.a.rr = min;
		stack.mov.a.ra -= min;
		stack.mov.b.rb -= min;
	}
	if (stack.mov.a.rra && stack.mov.b.rrb)
	{
		if (stack.mov.a.rra > stack.mov.b.rrb)
			min = stack.mov.b.rrb;
		else
			min = stack.mov.a.rra;
		stack.mov.a.rrr = min;
		stack.mov.a.rra -= min;
		stack.mov.b.rrb -= min;
	}
}

void	ft_move_compound_swap(t_stacks stack)
{
	size_t	min;

	if (stack.mov.swap.sa && stack.mov.swap.sb)
	{
		if (stack.mov.swap.sa > stack.mov.swap.sb)
			min = stack.mov.swap.sb;
		else
			min = stack.mov.swap.sa;
		stack.mov.swap.ss = min;
		stack.mov.swap.sa -= min;
		stack.mov.swap.sb -= min;
	}
}
