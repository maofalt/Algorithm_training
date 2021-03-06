/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:47:09 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 14:47:15 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_node	*XOR(t_node *a, t_node *b)
{
	return (t_node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

t_node	*ft_node_create(t_data data, t_node *npx)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->npx = npx;
	new->mov = ft_mov_initiliaze();
	return (new);
}

void	ft_node_insert_start(t_list *list, t_data data)
{
	t_node	*new;

	new = ft_node_create(data, XOR(list->head, list->tail));
	if ((!list->head && !list->tail) || !list)
		ft_list_chge_nodes(list, new, new);
	else if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, new, list->head);
	else
	{
		if (list->size == 2)
		{
			list->head->npx = XOR(new, list->tail);
			list->tail->npx = XOR(new, list->head);
		}
		else
		{
			list->head->npx = XOR(new, XOR(list->head->npx, list->tail));
			list->tail->npx = XOR(new, XOR(list->tail->npx, list->head));
		}
		list->head = new;
	}
	list->size++;
	ft_list_new_index(list);
}

void	ft_node_insert_end(t_list *list, t_data data)
{
	t_node	*new;

	new = ft_node_create(data, XOR(list->head, list->tail));
	if ((!list->head && !list->tail) || !list)
		ft_list_chge_nodes(list, new, new);
	if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, list->head, new);
	else
		{
		if (list->size == 2)
		{
			list->head->npx = XOR(new, list->tail);
			list->tail->npx = XOR(new, list->head);
		}
		else
		{
			list->head->npx = XOR(new, XOR(list->head->npx, list->tail));
			list->tail->npx = XOR(new, XOR(list->tail->npx, list->head));
		}
		list->tail = new;
	}
	list->size++;
	ft_list_new_index(list);
}

//We remove a node from the top
t_node	*ft_node_remove(t_list *list)
{
	t_node *rem_node;

	if (list->size == 0)
		return (NULL);
	rem_node = list->head;
	if ((list->head == list->tail) || list->size == 1)
		list = ft_list_create(NULL, NULL, 0);
	else if (list->size == 2)
	{
		list = ft_list_create(list->tail, list->tail, 1);
		list->tail->npx = NULL;
	}
	else if (list->size == 3)
	{
		list = ft_list_create(XOR(rem_node->npx, list->tail), list->tail, 2);
		list->head->npx = NULL;
		list->tail->npx = NULL;
	}
	else
	{
		list = ft_list_create(XOR(rem_node->npx, list->tail), list->tail, list->size - 1);
		list->head->npx = XOR(XOR(list->head->npx, rem_node), list->tail);
		list->tail->npx = XOR(XOR(rem_node, list->tail->npx), list->head);
	}
	rem_node->npx = NULL;
	ft_list_new_index(list);
	return (rem_node);
}
