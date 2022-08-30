/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:12:19 by motero            #+#    #+#             */
/*   Updated: 2022/08/30 14:18:37 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

size_t	ft_instructions_parsing(t_stacks *stack)
{
	t_mov	mov;
	size_t	total_moves;

	mov = stack->mov;
	total_moves = 0;
	total_moves += mov.swap.sa + mov.swap.sb + mov.swap.ss;
	total_moves += mov.a.ra + mov.a.rr + mov.b.rb;
	total_moves += mov.a.rra + mov.a.rrr + mov.b.rrb;
	total_moves += mov.swap.pa + mov.swap.pb;
	return (total_moves);
}
