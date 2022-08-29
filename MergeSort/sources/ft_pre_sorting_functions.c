/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sorting_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:14:11 by motero            #+#    #+#             */
/*   Updated: 2022/08/29 19:19:27 by motero           ###   ########.fr       */
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

void	ft_pre_sorting_big(t_list *list, size_t i)
{
	t_node static		*c;
	t_node static		*t;
	t_node static		*max;
	size_t				size;

	if (i == 0)
	{
		c = list->head;
		t = list->tail;
	}
	size = list->size - i;
	max = c;
	//printf("\nITERATION %zu\ncurrent |%d|max |%d|\n ", i, c->data.nb, max->data.nb);
	while (size)
	{
		if (c->data.nb > max->data.nb)
			max = c;
		ft_node_next(&c, &t);
		while (c->data.final_index != 0)
			ft_node_next(&c, &t);
		size--;
	}
	max->data.final_index = list->size - i - 1;
	//printf("MAX nb %d |FI %zu\n", max->data.nb, max->data.final_index);
	while (c->data.final_index != 0)
		ft_node_next(&c, &t);
	//ft_list_print_data(*list);
	//printf("end sortin big \n\n");
}
