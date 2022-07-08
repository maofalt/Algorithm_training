/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:05 by motero            #+#    #+#             */
/*   Updated: 2022/07/08 18:48:52 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"


void    ft_stack_swap(t_stacks stack)
{
    if (stack.mov.sa && stack.mov.sb )
    {
        stack.mov.sa = 0;
        stack.mov.sb = 0;
        stack.mov.ss = 1;
    }
    if ((stack.mov.sa || stack.mov.ss) && stack.a->size > 1)
        ft_list_swap_first_nodes(stack.a);
    if ((stack.mov.sb || stack.mov.ss) && stack.b->size > 1)
        ft_list_swap_first_nodes(stack.b);
}

void    ft_stack_push(t_stacks stack)
{
    if (stack.mov.pa && stack.b->size > 0)
        ft_list_cut_past(stack.b, stack.a);
    if (stack.mov.pb && stack.a->size > 0)
        ft_list_cut_past(stack.a, stack.b);
}

void    ft_stack_rotate(t_stacks stack)
{
    if (stack.mov.ra && stack.mov.rb)
    {
        stack.mov.ra = 0;
        stack.mov.rb = 0;
        stack.mov.rr = 1;
    }
    if ((stack.mov.ra || stack.mov.rr) && stack.a->size > 1)
        *(stack.a) = ft_list_rotate(*(stack.a));
    if ((stack.mov.rb || stack.mov.rr) && stack.b->size > 1)
        *(stack.b) = ft_list_rotate(*(stack.b));
}

void    ft_stack_reverse_rotate(t_stacks stack)
{
    if (stack.mov.rra && stack.mov.rrb )
    {
        stack.mov.rra = 0;
        stack.mov.rrb = 0;
        stack.mov.rrr = 1;
    }
    if ((stack.mov.rra || stack.mov.rrr) && stack.a->size > 1)
        *(stack.a) = ft_list_reverse_rotate(*stack.a);
    if ((stack.mov.rrb || stack.mov.rrr) && stack.b->size > 1)
        *(stack.b) = ft_list_reverse_rotate(*stack.b);
}

t_mov   ft_mov_initiliaze(void)
{
    t_mov   new_mov;

    new_mov.sa = 0;
	new_mov.sb = 0;
	new_mov.ss = 0;
	new_mov.pa = 0;
	new_mov.pb = 0;
	new_mov.ra = 0;
	new_mov.rb = 0;
	new_mov.rr = 0;
	new_mov.rr = 0;
	new_mov.rr = 0;
	new_mov.rr = 0;

    return (new_mov);
}

t_stacks    ft_stack_create(t_list *list_a, t_list *list_b)
{
    t_stacks    new_stack;

    new_stack.a = list_a;
    new_stack.b = list_b;
    new_stack.mov = ft_mov_initiliaze();
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
