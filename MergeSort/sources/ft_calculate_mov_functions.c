/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 19:32:59 by motero           ###   ########.fr       */
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
	size_t	times_to_rotate;
	t_node	*current;

	stack->mov.swap.pa = 5 - stack->a->size;
	ft_calculate_size_three(stack);
	while (stack->b->size)
	{
		times_to_rotate = 0
		while (times_to_rotate < stack->a->size)
		{
			if (stack->b->head > current->data->nb)
				times_to_rotate
			else
				break ; 
		}
		while (times_to_rotate--)
	}
}

void	ft_calculate_sorting(t_stacks *stack)
{
	stack = NULL;
	(void)stack;
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
