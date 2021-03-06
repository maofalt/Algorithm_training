/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:09:20 by motero            #+#    #+#             */
/*   Updated: 2022/07/20 16:24:55 by motero           ###   ########.fr       */
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
	return (new_list);
}

void	ft_list_new_index(t_list *list)
{
	t_node		*current;
	t_node		*tmp;
	t_node		*t;
	size_t		i;

	if (!list->size)
		return ;
	t = list->tail;
	current = list->head;
	i = 0;
	if (list->size < 3)
	{
		list->head->data.index = 0;
		list->tail->data.index = 1;
	}
	else
	{
		while (i < list->size)
		{
			current->data.index = i++;
			tmp = XOR(current->npx, t);
			t = current;
			current = tmp;
		}
	}
}

//Print all the list, We compare the index inside each node and compare it
//to the size of the list
void	ft_list_print_data(t_list list)
{
	t_node	*current;
	t_node	*tmp;
	t_node	*t;
	size_t	i;

	if (!list.size)
		return ;
	t = list.tail;
	current = list.head;
	i = 0;
	if (list.size < 3)
	{
		printf("Index:[%zu]= %d\n", current->data.index, list.head->data.nb);
		printf("Index:[%zu]= %d\n", list.tail->data.index, list.tail->data.nb);
	}
	else
	{
		while (i < list.size)
		{
			printf("Index:[%zu]= %d\n", current->data.index, current->data.nb);
			tmp = XOR(current->npx, t);
			t = current;
			current = tmp;
			i++;
		}
	}
}

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
	else if (list->size == 2)
	{
		free(list->head);
		free(list->tail);
	}
	else
	{
		while (list->size--)
		{
			tmp = XOR(current->npx, t);
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
	list->head = XOR(list->tail->npx, tmp);
	ft_list_new_index(list);
}

void	ft_list_reverse_rotate(t_list *list)
{
	t_node	*tmp;

	tmp = list->tail;
	list->tail = XOR(list->tail->npx, list->head);
	list->head = tmp;
	ft_list_new_index(list);
}

void	ft_list_swap_first_nodes(t_list *list)
{
	t_data	tmp;
	t_node	*second;

	if (!list || list->size < 1)
		return ;
	else
	{
		if (list->size == 2)
			list = ft_list_create(list->tail, list->head, list->size);
		else
		{
			tmp = list->head->data;
			second = XOR(list->head->npx, list->tail);
			list->head->data = second->data;
			second->data = tmp;
		}
		ft_list_new_index(list);
	}
}

//move first node from a to b
void	ft_list_cut_past(t_list	*a, t_list *b)
{
	t_node *node;
	t_data	tmp;

	if (a->size == 0)
		return ;
	node = ft_node_remove(a);
	tmp = node->data;
	free(node);
	ft_node_insert_start(b, tmp);
}

void	ft_list_reset_mov(t_list *list)
{
	t_node			*current;
	t_node			*tmp;
	t_node			*t;
	size_t			i;

	if (!list->head || !list->tail)
		return ;
	t = list->tail;
	current = list->head;
	if (list->size == 1)
		list->head->mov = ft_mov_initiliaze();
	else if (list->size == 2)
	{
		list->head->mov = ft_mov_initiliaze();
		list->tail->mov = ft_mov_initiliaze();
	}
	else
	{
		i = 0;
		while (i++ < list->size)
		{

			tmp = XOR(current->npx, t);
			current->mov = ft_mov_initiliaze();
			t = current;
			current = tmp;
		}
	}
}

void	ft_list_chge_nodes(t_list *list, t_node *new_h, t_node *new_t)
{
	list->head = new_h;
	list->tail = new_t;
}
// int	main()
// {
// 	t_data data;
// 	t_node	*head = NULL, *tail = NULL;
// 	t_list	list;
// 	int	nbrs[]={1,-96,589,584,2,0};
// 	int i = 0;

// 	list = ft_list_create(head, tail, 0);
// 	while (i < 6)
// 	{
// 		data = ft_data_create(nbrs[i], i);
// 		ft_node_insert_end(&list,data);
// 		i++;
// 	}
// 	ft_list_print_data(list);
// 	printf("Swapped \n");
// 	ft_list_swap_first_nodes(&list);
// 	ft_list_print_data(list);
// 	// int		i = 0;
// 	// printf("After rotation \n");
// 	// while (i++ < 4)
// 	// {
// 	// 	printf("Rotation [%d]\n", i);
// 	// 	list = ft_list_rotate(list);
// 	// 	ft_list_print_data(list);
// 	// }
// 	// t_node	*rem_node;
// 	// 	while (list.size)
// 	// {
// 	// 	printf("Removed node\n");
// 	// 	rem_node = ft_node_remove(&list);
// 	// 	printf("List size |%zu|\n", list.size);
// 	// 	ft_list_print_data(list);
// 	// 	printf("removed data\n index[%zu]=%d\n", rem_node->data.index, rem_node->data.nb);
// 	// 	free(rem_node);
// 	// }
// 	// ft_list_print_data(list);
// 	ft_list_free(&list);
// }
