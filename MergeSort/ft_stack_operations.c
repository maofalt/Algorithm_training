/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:05 by motero            #+#    #+#             */
/*   Updated: 2022/07/18 15:01:21 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"


void    ft_stack_swap(t_stacks stack)
{
    if ((stack.mov.swap.sa || stack.mov.swap.ss) && stack.a->size > 1)
        ft_list_swap_first_nodes(stack.a);
    if ((stack.mov.swap.sb || stack.mov.swap.ss) && stack.b->size > 1)
        ft_list_swap_first_nodes(stack.b);
}

void    ft_stack_push(t_stacks stack)
{
    if (stack.mov.swap.pa && stack.b->size > 0)
        ft_list_cut_past(stack.b, stack.a);
    if (stack.mov.swap.pb && stack.a->size > 0)
        ft_list_cut_past(stack.a, stack.b);
}

void    ft_stack_rotate(t_stacks stack)
{
    if ((stack.mov.a.ra || stack.mov.a.rr) && stack.a->size > 1)
        *(stack.a) = ft_list_rotate(*(stack.a));
    if ((stack.mov.b.rb || stack.mov.a.rr) && stack.b->size > 1)
        *(stack.b) = ft_list_rotate(*(stack.b));
}

void    ft_stack_reverse_rotate(t_stacks stack)
{
    if ((stack.mov.a.rra || stack.mov.a.rrr) && stack.a->size > 1)
        *(stack.a) = ft_list_reverse_rotate(*stack.a);
    if ((stack.mov.b.rrb || stack.mov.a.rrr) && stack.b->size > 1)
        *(stack.b) = ft_list_reverse_rotate(*stack.b);
}

t_mov   ft_mov_initiliaze(void)
{
    t_mov   new_mov;

    new_mov.swap.sa = 0;
	new_mov.swap.sb = 0;
	new_mov.swap.ss = 0;
	new_mov.swap.pa = 0;
	new_mov.swap.pb = 0;
	new_mov.a.ra = 0;
	new_mov.b.rb = 0;
	new_mov.a.rra = 0;
	new_mov.b.rrb = 0;
	new_mov.a.rr = 0;
	new_mov.a.rrr = 0;

    return (new_mov);
}

t_stacks    ft_stack_create(t_list *list_a, t_list *list_b)
{
    t_stacks    new_stack;

    new_stack.a = list_a;
    new_stack.b = list_b;
    new_stack.mov = ft_mov_initiliaze();
    new_stack.total_moves = 0;
    return (new_stack);
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
//     printf("size A: %zu\n", stack.a->size);
// 	ft_list_print_data(*(stack.a));
//     printf("\nswap Rotation\n");
//     stack.mov.pa = 0;
//     stack.mov.pb = 1;
//     while(i++ < n)
//     {
//         printf("Iteration %zu\n", i);
//         ft_stack_push(stack);
//         printf("Stack A\n");
//         ft_list_print_data(*(stack.a));
//         printf("Stack B\n");
//         ft_list_print_data(*(stack.b));
//     }
//     ft_stack_push(stack);
//     ft_list_print_data(*(stack.b));
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
// 	// 	printf("removed data\n index[%zu]=%d\n", rem_node->data.index, rem_node->data.nb);
// 	// 	free(rem_node);
// 	// }
// 	// ft_list_print_data(list);
// 	ft_list_free(&list_a);
//     ft_list_free(&list_b);
// }
