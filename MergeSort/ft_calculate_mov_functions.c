/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/07/18 18:33:51 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"

// void	ft_calculate_size_three(t_list list)
// {
// 	t_node	*mid;
// 	int		min_mid_max[3];

// 	mid = XOR(list.head->npx, list.tail);
// 	ft_find_min_max_mid(list.head->data.nb, mid->data.nb, list.tail->data.nb);
// }

int	ft_find_mean(int a, int b, int c)
{
	return ((a + b + c) / 3);
}

int	ft_find_max(t_list list)
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
		printf("here\n");
		next = XOR(current->npx, tail);
		if (max > next->data.nb)
			i[1] = i[1];
		else
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

int	main(int argc, char **argv)
{
	t_list	list;
	int		index_max;

	list = ft_parsing(argv, argc);
	index_max = ft_find_max(list);
	printf("CEci est l'index du max |%i|\n", index_max);
}
