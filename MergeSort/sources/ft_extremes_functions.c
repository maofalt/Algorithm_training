/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extremes_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:17:45 by motero            #+#    #+#             */
/*   Updated: 2022/08/31 16:27:07 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

/*Fixe this, Max and min nb should be equal to list->head not 0 */
t_xtrm	ft_extremes_initializes(t_list *list)
{
	t_xtrm	xtrm;

	xtrm.max.i = 0;
	xtrm.max.nb = 0;
	xtrm.max.node = list->head;
	xtrm.min.i = 0;
	xtrm.min.nb = 0;
	xtrm.min.node = list->head;
	return (xtrm);
}

void	ft_extremes_parsing(t_list *list, t_data data)
{
	if (data.index == 0)
		ft_extremes_initialize_list(list, data);
	else
	{
		if (data.nb < list->xtrm.min.nb)
		{
			list->xtrm.min.nb = data.nb;
			list->xtrm.min.i = data.index;
			list->xtrm.min.tail = list->xtrm.min.node;
			list->xtrm.min.node = list->tail;
		}
		if (data.nb > list->xtrm.max.nb)
		{
			list->xtrm.max.nb = data.nb;
			list->xtrm.max.i = data.index;
			list->xtrm.min.node = list->tail;
		}
	}
}

/*Fix this, Max and min nb should be equal to list->head not 0 */
void	ft_extremes_find(t_list *list)
{
	size_t				i;
	t_node static		*c;
	t_node				*tmp;
	t_node static		*t;

	i = 0;
	c = list->head;
	t = list->tail;
	ft_extremes_initialize_list(list, list->head->data);
	while (i < list->size)
	{
		if (c->data.nb > list->xtrm.max.nb)
		{
			list->xtrm.max.nb = c->data.nb;
			list->xtrm.max.i = c->data.index;
			list->xtrm.max.node = c;
		}
		if (c->data.nb < list->xtrm.min.nb)
		{
			list->xtrm.min.nb = c->data.nb;
			list->xtrm.min.i = c->data.index;
			list->xtrm.min.tail = t;
			list->xtrm.min.node = c;
		}
		tmp = XOR(c->npx, t);
		t = c;
		c = tmp;
		i++;
	}
}


// void	ft_extremes_swap(t_list *list)
// {
// 	if (list->xtrm.min.i < 2)
// 		list->xtrm.min.i = list->xtrm.min.node->data.index;
// 	if (list->xtrm.max.i < 2)
// 		list->xtrm.max.i = list->xtrm.max.node->data.index;
// }

// void	ft_extremes_push(t_list *list_a, t_list *list_b)
// {
// 	if (list_a->xtrm.min.i == 0)
// 	{
// 		if (list_b->size == 0)
// 			ft_extremes_initialize_list(list_b, list_a->head->data);
// 		else
// 		{
// 			if (list_b->xtrm.min.nb > list_a->xtrm.min.nb)
// 				list_b->xtrm.min.nb = list_a->xtrm.min.nb;
// 			if (list_b->xtrm.max.nb < list_a->xtrm.max.nb)
// 				list_b->xtrm.max.nb= list_a->xtrm.max.nb;
// 			//pass next node info (node, index and) to min or max
// 			//After applying operation or applying all push apply find max and find min
// 		}

// 	}
// 	else
// 		list_a->xtrm.min.i = list_a->xtrm.min.node->data.index;
// 	if (list_a->xtrm.min.i == 0)
// 		;
// 	else
// 		list_a->xtrm.min.i = list_a->xtrm.min.node->data.index;
// }

// void	ft_extremes_rotate(t_list *list)
// {
// 	list->xtrm.min.i = list->xtrm.min.node->data.index;
// 	list->xtrm.max.i = list->xtrm.max.node->data.index;
// }

// void	ft_extremes_reverse_rotate(t_list *list)
// {
// 	list->xtrm.min.i = list->xtrm.min.node->data.index;
// 	list->xtrm.max.i = list->xtrm.max.node->data.index;
// }

void	ft_extremes_initialize_list(t_list *list, t_data data)
{
	list->xtrm.min.nb = data.nb;
	list->xtrm.min.i = data.index;
	list->xtrm.min.node = list->head;
	list->xtrm.min.tail = list->tail;
	list->xtrm.max.nb = data.nb;
	list->xtrm.max.i = data.index;
	list->xtrm.max.node = list->head;
}
