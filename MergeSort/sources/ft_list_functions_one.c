/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:09:20 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 06:35:51 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_list	*ft_list_create(t_node *head, t_node *tail, size_t size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->head = head;
	new_list->tail = tail;
	new_list->size = size;
	new_list->index_node = 0;
	new_list->xtrm = ft_extremes_initializes(new_list);
	return (new_list);
}

void	ft_list_new_index(t_list *list)
{
	t_node		*current;
	t_node		*t;
	size_t		i;

	if (list->size == 0)
		return ;
	t = list->tail;
	current = list->head;
	i = 0;
	if (list->size == 1)
		list->head->data.index = 0;
	else if (list->size < 3)
	{
		list->head->data.index = 0;
		list->tail->data.index = 1;
	}
	else
	{
		while (i < list->size)
		{
			current->data.index = i++;
			ft_node_next(&current, &t);
		}
	}
}

//Print all the list, We compare the index inside each node and compare it
//to the size of the list
// void	ft_list_print_data(t_list list)
// {
// 	t_node	*current;
// 	t_node	*tmp;
// 	t_node	*t;
// 	size_t	i;

// 	if (!list.size)
// 		return ;
// 	t = list.tail;
// 	current = list.head;
// 	i = 0;
// 	if (list.size < 3)
// 	{
// 		printf("INDEX:\t%zu\t|:NB\t%d\t|FINAL INDEX\t%zu
//|\tMOVES %zu\n", current->data.index, list.head->data.nb,
// list.head->data.final_index, list.head->nb_optn);
// 		printf("INDEX:\t%zu\t|:NB\t%d\t|FINAL INDEX\t%
//zu|\tMOVES %zu\n", list.tail->data.index,
// list.tail->data.nb, list.tail->data.final_index, list.tail->nb_optn);
// 	}
// 	else
// 	{
// 		while (i < list.size)
// 		{
// 			printf("INDEX:\t%zu\t|:NB\t%d\t|FINAL 
//INDEX\t%zu|\t|MOVES %zu\n", current->data.index, 
//current->data.nb, current->data.final_index, current->nb_optn);
// 			tmp = xor(current->npx, t);
// 			t = current;
// 			current = tmp;
// 			i++;
// 		}
// 	}
// }

void	ft_list_free(t_list *list)
{
	t_node			*current;
	t_node			*tmp;
	t_node			*t;

	if (!list->head || !list->tail)
		return ;
	t = list->tail;
	current = list->head;
	if (list->size == 1)
		free(list->head);
	else if (list->size > 1)
	{
		while (list->size--)
		{
			tmp = xor(current->npx, t);
			t = current;
			free(current);
			current = tmp;
		}
	}
	ft_list_chge_nodes(list, NULL, NULL);
}

void	ft_list_rotate(t_list *list)
{
	t_node	*tmp;

	tmp = list->tail;
	list->tail = list->head;
	list->head = xor(list->tail->npx, tmp);
	ft_list_new_index(list);
}

void	ft_list_reverse_rotate(t_list *list)
{
	t_node	*tmp;

	tmp = list->tail;
	list->tail = xor(list->tail->npx, list->head);
	list->head = tmp;
	ft_list_new_index(list);
}
