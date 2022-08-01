/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/08/01 19:10:46 by motero           ###   ########.fr       */
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
	stack->mov.swap.pb = stack->a->size - 3;
	ft_sorting_apply_operations(stack);
	ft_printf("For size 5, these three are sorted in b\n");
	ft_list_print_data(*stack->b);
	ft_calculate_size_three(stack);
	ft_sorting_apply_operations(stack);
	ft_calculate_sorting_b_to_a(stack);
	ft_sorting_apply_operations(stack);
}

void	ft_calculate_sorting_b_to_a(t_stacks *stack)
{
	t_node	*current[2];
	t_node	*past;
	int		times_to_rotate_a;
	int		times_to_rotate_b;

	times_to_rotate_b = 0;
	current[1] = ft_node_next(*stack->b, 1, 0);
	past = current[1];
	while (times_to_rotate_b < (int)stack->b->size)
	{
		current[0] = ft_node_next(*stack->a, 0, 0);
		times_to_rotate_a = 0;
		while (current[1]->data.nb > current[0]->data.nb
			&& times_to_rotate_a < (int)stack->a->size)
		{
			times_to_rotate_a++;
			current[0] = ft_node_next(*stack->a, 0, -1);
		}
		if (times_to_rotate_a >= (int)(stack->a->size / 2))
			times_to_rotate_a = (int)(stack->a->size / 2) - times_to_rotate_a;
		if (times_to_rotate_a > 0)
		{
			while (times_to_rotate_a--)
			{
				current[1]->operations = ft_strjoin(current[1]->operations, "ra\n");
				current[1]->nb_optn++;
			}
		}
		else
		{
			while (times_to_rotate_a++)
			{
				current[1]->operations = ft_strjoin(current[1]->operations, "rra\n");
				current[1]->nb_optn++;
			}
		}
		if (stack->b->size > 1)
		{
			current[1]->operations = ft_strjoin(current[1]->operations, "rb\n");
			current[1]->nb_optn++;
			times_to_rotate_b++;
		}
		past = current[1];
		if (stack->b->size == 1)
			stack->operations = past->operations;
		current[1] = ft_node_next(*stack->b, 1, -1);
		else if (current[1]->nb_optn > past->nb_optn)
			stack->operations = past->operations;
	}
}

t_node	*ft_node_next(t_list list, size_t i, size_t init)
{
	static t_node	*current[10];
	static t_node	*tail[10];
	static t_node	*tmp[10];

	if (current[i] == list.head || init == 0)
	{
			current[i] = list.head;
			tail[i] = list.tail;
	}
	tmp[i] = XOR(current[i]->npx, tail[i]);
	tail[i] = current[i];
	current[i] = tmp[i];
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
