/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:05 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 15:06:33 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_stack_swap(t_stacks *stack)
{
	if ((stack->mov.swap.sa || stack->mov.swap.ss) && stack->a->size > 1)
		ft_list_swap_first_nodes(stack->a);
	if ((stack->mov.swap.sb || stack->mov.swap.ss) && stack->b->size > 1)
		ft_list_swap_first_nodes(stack->b);
}

void	ft_stack_push(t_stacks *stack)
{
	if (stack->mov.swap.pa && stack->b->size > 0)
		ft_list_cut_past(stack->b, stack->a);
	if (stack->mov.swap.pb && stack->a->size > 0)
		ft_list_cut_past(stack->a, stack->b);
}

void	ft_stack_rotate(t_stacks *stack)
{
	if ((stack->mov.a.ra || stack->mov.a.rr) && stack->a->size > 1)
		ft_list_rotate((stack->a));
	if ((stack->mov.b.rb || stack->mov.a.rr) && stack->b->size > 1)
		ft_list_rotate((stack->b));
}

void	ft_stack_reverse_rotate(t_stacks *stack)
{
	if ((stack->mov.a.rra || stack->mov.a.rrr) && stack->a->size > 1)
		ft_list_reverse_rotate(stack->a);
	if ((stack->mov.b.rrb || stack->mov.a.rrr) && stack->b->size > 1)
		ft_list_reverse_rotate(stack->b);
}

t_stacks	*ft_stack_initilize(t_list *list_a)
{
	t_stacks	*stack;
	t_list		*list_b;

	stack = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stack)
		return (NULL);
	stack->a = list_a;
	list_b = ft_list_create(NULL, NULL, 0);
	stack->b = list_b;
	stack->mov = ft_mov_initiliaze();
	stack->total_moves = 0;
	stack->operations = NULL;
	return (stack);
}

void	ft_stack_free(t_stacks *stack)
{
	ft_list_free(stack->a);
	if (stack->b->head)
		ft_list_free(stack->b);
	free(stack->a);
	free(stack->b);
	free(stack->operations);
	free(stack);
}

// int	main()
// {
// 	t_data data;
// 	t_node	*head = NULL, *tail = NULL;
// 	t_list	list_a, list_b;
//     t_stacks    stack;
// 	int	nbrs[]={1,-96,589,0};
// 	size_t i = 0;
//     size_t n = sizeof(nbrs)/sizeof(nbrs[0]);
// 	list_a = ft_list_create(head, tail, 0);
//     list_b = ft_list_create(head, tail, 0);
//     stack = ft_stack_create(&list_a, &list_b);
// 	//Filling up list a
//     while (i < n)
// 	{
// 		data = ft_data_create(nbrs[i], i);
// 		ft_node_insert_end(&list_a, data);
// 		i++;
// 	}
// 	ft_list_print_data(list_a);
//     i = 0;
//     printf("size A: %zu\n", stack->a->size);
// 	ft_list_print_data(*(stack->a));
//     printf("\nswap Rotation\n");
//     stack->mov.pa = 0;
//     stack->mov.pb = 1;
//     while(i++ < n)
//     {
//         printf("Iteration %zu\n", i);
//         ft_stack_push(stack);
//         printf("Stack A\n");
//         ft_list_print_data(*(stack->a));
//         printf("Stack B\n");
//         ft_list_print_data(*(stack->b));
//     }
//     ft_stack_push(stack);
//     ft_list_print_data(*(stack->b));
// 	// printf("After rotation \n");
//     // i = 0;
// 	// while (i < n)
// 	// {
// 	// 	printf("Rotation [%zu]\n", i);
// 	// 	list_a = ft_list_rotate(list_a);
// 	// 	ft_list_print_data(list_a);
//     //     i++;
// 	// }
// 	// t_node	*rem_node;
// 	// 	while (list.size)
// 	// {
// 	// 	printf("Removed node\n");
// 	// 	rem_node = ft_node_remove(&list);
// 	// 	printf("List size |%zu|\n", list.size);
// 	// 	ft_list_print_data(list);
// 	// 	printf("removed data\n index[%zu]=%d\n",
//rem_node->data.index, rem_node->data.nb);
// 	// 	free(rem_node);
// 	// }
// 	// ft_list_print_data(list);
// 	ft_list_free(&list_a);
//     ft_list_free(&list_b);
// }
