/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sorting_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:14:11 by motero            #+#    #+#             */
/*   Updated: 2022/08/25 16:49:19 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_pre_sorting_general(t_list *list)
{
	if (list->size == 1)
		return ;
	else if (list->size == 2)
	{
		if (list->head->data.nb > list->tail->data.nb)
		{
			list->head->data.final_index = 1;
			list->head->data.final_index = 0;
		}
	}
	else
		ft_pre_sorting_bigger_two(list);
}

void	ft_pre_sorting_bigger_two(t_list *list)
{
	size_t	i;

	i = 0;
	while (i < list->size)
	{
		ft_pre_sorting_big(list, i);
		i++;
	}
}

void	ft_pre_sorting_big(t_list *list, int i)
{
	size_t				size;
	t_node static		*c;
	t_node				*tmp;
	t_node static		*t;
	t_node static		*max;

	if (i == 0)
	{
		t = list->tail;
		c = list->head;
		max = c;
	}
	size = list->size;
	while (size)
	{
		if (max->data.final_index >= list->size - i)
			max = XOR(c->npx, t);
		else if (c->data.nb > max->data.nb && c->data.final_index < (list->size - i))
			max = c;
		tmp = XOR(c->npx, t);
		t = c;
		c = tmp;
		size--;
	}
	max->data.final_index = list->size - 1 - i;
}
