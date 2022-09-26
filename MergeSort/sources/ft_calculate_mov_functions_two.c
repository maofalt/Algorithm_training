/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions_two.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 06:32:16 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_cal_init_fit(size_t *f_b_fit, t_node **c_b)
{
	f_b_fit[0] = 0;
	f_b_fit[1] = 0;
	(*c_b)->nb_optn = 0;
	(*c_b)->mov = ft_mov_initiliaze();
}

void	ft_cal_init_node(t_node **fnode, t_node **bnode, t_stacks *stack)
{
	fnode[0] = stack->a->head;
	fnode[1] = stack->a->tail;
	bnode[0] = stack->a->tail;
	bnode[1] = stack->a->head;
}

void	ft_calculate_rot_to_fit(t_stacks *stack, t_node *c_b)
{
	t_node		*fnode[2];
	t_node		*bnode[2];
	size_t		f_b_fit[2];

	ft_cal_init_node(fnode, bnode, stack);
	ft_cal_init_fit(f_b_fit, &c_b);
	while (f_b_fit[0] == 0 && f_b_fit[1] == 0)
	{
		if (c_b->data.nb < fnode[0]->data.nb
			&& c_b->data.nb > fnode[1]->data.nb)
			f_b_fit[0] = 1;
		else if (c_b->data.nb > bnode[0]->data.nb
			&& c_b->data.nb < bnode[1]->data.nb)
			f_b_fit[1] = 1;
		else
		{
			c_b->nb_optn++;
			ft_node_next(&fnode[0], &fnode[1]);
			ft_node_next(&bnode[0], &bnode[1]);
		}
	}
	if (f_b_fit[0])
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

	tmp = xor((*c)->npx, (*t));
	(*t) = (*c);
	(*c) = tmp;
}
