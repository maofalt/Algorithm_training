/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_functions_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:47:09 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 06:36:09 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_node_insert_end_node(t_list *list, t_node *node)
{
	node->npx = xor(list->head, list->tail);
	if ((!list->head && !list->tail) || !list)
		ft_list_chge_nodes(list, node, node);
	if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, list->head, node);
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
		list->tail = node;
	}
	list->size++;
	ft_list_new_index(list);
}

void	ft_node_rem_two(t_list *list)
{
	ft_list_chge_nodes(list, list->tail, list->tail);
	list->tail->npx = NULL;
}

void	ft_node_rem_three(t_list *list)
{
	t_node	*rem_node;

	rem_node = list->head;
	ft_list_chge_nodes(list, xor(rem_node->npx, list->tail), list->tail);
	list->head->npx = NULL;
	list->tail->npx = NULL;
}

//We remove a node from the top
t_node	*ft_node_remove(t_list *list)
{
	t_node	*rem_node;

	if (list->size == 0)
		return (NULL);
	rem_node = list->head;
	if ((list->head == list->tail) || list->size == 1)
		ft_list_chge_nodes(list, NULL, NULL);
	else if (list->size == 2)
		ft_node_rem_two(list);
	else if (list->size == 3)
		ft_node_rem_three(list);
	else
	{
		ft_list_chge_nodes(list, xor(rem_node->npx, list->tail), list->tail);
		list->head->npx = xor(xor(list->head->npx, rem_node), list->tail);
		list->tail->npx = xor(xor(rem_node, list->tail->npx), list->head);
	}
	rem_node->npx = NULL;
	list->size--;
	ft_list_new_index(list);
	return (rem_node);
}
