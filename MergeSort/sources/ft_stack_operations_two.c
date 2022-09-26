/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:37:05 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 03:14:28 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_stack_free(t_stacks *stack)
{
	ft_list_free(stack->a);
	if (stack->b->head)
		ft_list_free(stack->b);
	free(stack->a);
	free(stack->b);
	free(stack);
}

char	*ft_strjoin_w_free(char *s1, char const *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
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
