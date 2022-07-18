/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:39:46 by motero            #+#    #+#             */
/*   Updated: 2022/07/18 18:41:08 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"

int	ft_find_mean(int a, int b, int c)
{
	return ((a + b + c) / 3);
}

int	ft_find_index_max(t_list list)
{
	t_node	*current;
	t_node	*tail;
	t_node	*next;
	int		i[2];
	int		max;

	current = list.head;
	tail = list.tail;
	i[0] = 0;
	i[1] = 0;
	max = current->data.nb;
	while (i[0] < list.size)
	{
		next = XOR(current->npx, tail);
		if (max < next->data.nb)
		{
			max = next->data.nb;
			i[1] = i[0] + 1;
		}
		i[0]++;
		tail = current;
		current = next;
	}
	return (i[1] % list.size);
}

int	ft_find_index_min(t_list list)
{
	t_node	*current;
	t_node	*tail;
	t_node	*next;
	int		i[2];
	int		min;

	current = list.head;
	tail = list.tail;
	i[0] = 0;
	i[1] = 0;
	min = current->data.nb;
	while (i[0] < list.size)
	{
		next = XOR(current->npx, tail);
		if (min > next->data.nb)
		{
			min = next->data.nb;
			i[1] = i[0] + 1;
		}
		i[0]++;
		tail = current;
		current = next;
	}
	return (i[1] % list.size);
}
