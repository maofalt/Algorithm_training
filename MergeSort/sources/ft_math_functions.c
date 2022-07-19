/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:39:46 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 15:00:37 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int	ft_find_mean(int a, int b, int c)
{
	return ((a + b + c) / 3);
}

int	ft_find_index_max(t_list list)
{
	t_node	*current;
	t_node	*tail;
	t_node	*next;
	size_t		i[2];
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
	size_t		i[2];
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

int	ft_find_index_mid(t_list list)
{
	int				min_mid_max[3];
	const int		sum_index = 3;

	min_mid_max[2] = ft_find_index_max(list);
	min_mid_max[0] = ft_find_index_min(list);
	min_mid_max[1] = sum_index - min_mid_max[2] - min_mid_max[0];
	return (min_mid_max[1]);
}

// int	main(int argc, char **argv)
// {
// 	t_list	list;
// 	int		index[3];

// 	list = ft_parsing(argv, argc);
// 	index[0] = ft_find_index_min(list);
// 	index[1] = ft_find_index_mid(list);
// 	index[2] = ft_find_index_max(list);
// 	printf("CEci est l'index du min |%i|\n", index[0]);
// 	printf("CEci est l'index du mid |%i|\n", index[1]);
// 	printf("CEci est l'index du max |%i|\n", index[2]);
// }
