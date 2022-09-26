/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_functions_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:47:09 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 20:51:15 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_node	*xor(t_node *a, t_node *b)
{
	return ((t_node *)((uintptr_t)(a) ^ (uintptr_t)(b)));
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
	new->nb_optn = 0;
	return (new);
}

void	ft_node_insert_start(t_list *list, t_data data)
{
	t_node	*new;

	new = ft_node_create(data, xor(list->head, list->tail));
	if ((!list->head && !list->tail) || !list)
		ft_list_chge_nodes(list, new, new);
	else if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, new, list->head);
	else
	{
		if (list->size == 2)
		{
			list->head->npx = xor(new, list->tail);
			list->tail->npx = xor(new, list->head);
		}
		else
		{
			list->head->npx = xor(new, xor(list->head->npx, list->tail));
			list->tail->npx = xor(new, xor(list->tail->npx, list->head));
		}
		list->head = new;
	}
	list->size++;
	ft_list_new_index(list);
}

void	ft_node_insert_start_node(t_list *list, t_node *node)
{
	node->npx = xor(list->head, list->tail);
	if ((!list->head && !list->tail) || !list)
		ft_list_chge_nodes(list, node, node);
	else if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, node, list->head);
	else
	{
		if (list->size == 2)
		{
			list->head->npx = xor(node, list->tail);
			list->tail->npx = xor(node, list->head);
		}
		else
		{
			list->head->npx = xor(node, xor(list->head->npx, list->tail));
			list->tail->npx = xor(node, xor(list->tail->npx, list->head));
		}
		list->head = node;
	}
	list->size++;
	ft_list_new_index(list);
}

void	ft_node_insert_end(t_list *list, t_data data)
{
	t_node	*new;

	new = ft_node_create(data, xor(list->head, list->tail));
	if ((!list->head && !list->tail) || !list)
		ft_list_chge_nodes(list, new, new);
	if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, list->head, new);
	else
	{
		if (list->size == 2)
		{
			list->head->npx = xor(new, list->tail);
			list->tail->npx = xor(new, list->head);
		}
		else
		{
			list->head->npx = xor(new, xor(list->head->npx, list->tail));
			list->tail->npx = xor(new, xor(list->tail->npx, list->head));
		}
		list->tail = new;
	}
	list->size++;
	ft_list_new_index(list);
}
