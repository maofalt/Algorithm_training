/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extremes_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:17:45 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 04:20:49 by motero           ###   ########.fr       */
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
			list->xtrm.min.node = c;
		}
		ft_node_next(&c, &t);
		i++;
	}
}

void	ft_extremes_initialize_list(t_list *list, t_data data)
{
	list->xtrm.min.nb = data.nb;
	list->xtrm.min.i = data.index;
	list->xtrm.min.node = list->head;
	list->xtrm.max.nb = data.nb;
	list->xtrm.max.i = data.index;
	list->xtrm.max.node = list->head;
}
