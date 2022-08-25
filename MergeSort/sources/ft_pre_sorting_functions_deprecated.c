/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_sorting_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:14:11 by motero            #+#    #+#             */
/*   Updated: 2022/08/24 21:16:15 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_pre_sorting_general(t_list *list)
{
	size_t	size;
	size_t	i;
	t_node	*current;
	t_node	*tmp;
	t_node	*t;
	t_node	*max;

	t = list->tail;
	current = list->head;
	max = current;
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
	{
		i = 0;
		while (i < list->size)
		{
			size = list->size;
			while (size)
			{
				if (current->data.nb > max->data.nb && current->data.final_index < list->size - i)
					max = current;
				tmp = XOR(current->npx, t);
				t = current;
				current = tmp;
				size--;
			}
			max->data.final_index = list->size - 1 - i;
			max = XOR(current->npx, t);
			i++;
		}
	}
}
