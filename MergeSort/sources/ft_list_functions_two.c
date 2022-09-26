/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:09:20 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 06:36:29 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_list_swap_first_nodes(t_list *list)
{
	t_data	tmp;
	t_node	*second;

	if (!list || list->size < 1)
		return ;
	else
	{
		if (list->size == 2)
			ft_list_chge_nodes(list, list->tail, list->head);
		else
		{
			tmp = list->head->data;
			second = xor(list->head->npx, list->tail);
			list->head->data = second->data;
			second->data = tmp;
		}
		ft_list_new_index(list);
	}
}

//move first node from a to b
void	ft_list_cut_past(t_list	*a, t_list *b)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = ft_node_remove(a);
	ft_node_insert_start_node(b, node);
}

void	ft_list_reset_mov(t_list *list)
{
	t_node			*current;
	t_node			*t;
	size_t			i;

	if (!list->head || !list->tail)
		return ;
	t = list->tail;
	current = list->head;
	if (list->size <= 2)
	{
		list->head->nb_optn = 0;
		list->head->mov = ft_mov_initiliaze();
		list->tail->nb_optn = 0;
		list->tail->mov = ft_mov_initiliaze();
	}
	else
	{
		i = 0;
		while (i++ < list->size)
		{
			current->nb_optn = 0;
			ft_node_next(&current, &t);
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
// 	// 	printf("List size |%zu|\n", list.size);
// 	// 	ft_list_print_data(list);
// 	// 	printf("removed data\n index[%zu]=%d\n", \addindex
//->data.index, rem_node->data.nb);
// 	// 	free(rem_node);
// 	// }
// 	// ft_list_print_data(list);
// 	ft_list_free(&list);
// }
