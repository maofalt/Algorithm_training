/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/07/27 19:22:01 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_calculate_size_three(t_stacks *stack)
{
	int		index[3];
	t_list	list;

	list = *stack->a;
	index[0] = ft_find_index_min(list);
	index[1] = ft_find_index_mid(list);
	index[2] = ft_find_index_max(list);
	if (index[0] == 1 && index[1] == 0)
		stack->mov.swap.sa = 1;
	else if (index[2] == 0 && index[1] == 1)
	{
		stack->mov.swap.sa = 1;
		stack->mov.a.rra = 1;
	}
	else if (index[2] == 0 && index[0] == 1)
		stack->mov.a.ra = 1;
	else if (index[0] == 0 && index[2] == 1)
	{
		stack->mov.swap.sa = 1;
		stack->mov.a.ra = 1;
	}
	else
		stack->mov.a.rra = 1;
}

void	ft_calculate_sorting_size_five(t_stacks *stack)
{
	t_list	list;

	stack->mov.swap.pa = stack->a->size - 3;
	ft_sorting_apply_operations(stack);
	ft_calculate_size_three(stack);
	ft_sorting_apply_operations(stack);
	ft_calculate_sorting_b_to_a(stack);
}

void	ft_calculate_sorting_b_to_a(t_stacks *stack)
{
	t_node	*current[2];
	int		times_to_rotate_a;
	int		times_to_rotate_b;

	times_to_rotate_b = 0;
	current[1] = ft_node_next_b(*stack->b, 1);
	while (i < stack->b->size)
	{
		current[0] = stack->a->head;
		times_to_rotate-a = 0;
		rev_times_to_rotate = 0;
		while (current[1]->data.nb > current[0]->data.nb
			&& times_to_rotate <= stack->a->size)
		{
			times_to_rotate++;
			current[0] = ft_node_next_a(*stack->a, 0);
		}
		if (times_to_rotate >= stack->a->size / 2)
		{
			rev_times_to_rotate = (stack->a->size / 2) - times_to_rotate;
			times_to_rotate = 0;
		}
		times_to_rotate_b++;
		current[1] = ft_node_next_b(stack->b, 1);
	}
}

t_node	*ft_node_next_a(t_list list, size_t i)
{
	static t_node	*current[10];
	static t_node	*tail[10];
	static t_node	*tmp[10];

	if (current[i] == list.head)
		current[i] = list.head;
	tmp[i] = XOR(current[i]->npx, tail);
	tail[i] = current;
	current[i] = tmp;
	return (current[i]);
}


// int	main(int argc, char **argv)
// {
// 	t_list	list;

// 	int		index_max, index_min;

// 	list = ft_parsing(argv, argc);
// 	index_max = ft_find_max(list);
// 	index_min = ft_find_min(list);
// 	printf("CEci est l'index du max |%i|\n", index_max);
// 	printf("CEci est l'index du min |%i|\n", index_min);
// }
