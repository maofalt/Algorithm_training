/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mov_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:44:10 by motero            #+#    #+#             */
/*   Updated: 2022/08/25 19:02:53 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_calculate_size_three(t_stacks *stack)
{
	int		index[3];
	t_list	*list;

	list = stack->a;
	index[0] = list->xtrm.min.i;
	index[2] = list->xtrm.max.i;
	index[1] = 3 - index[0] - index[2];
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
	ft_extremes_find(stack->a);
	ft_calculate_size_three(stack);
	ft_sorting_apply_operations(stack);
	printf("\n3-stack A ordered\n");
	ft_list_print_data(*stack->a);
	printf("\n");
	while (stack->b->size)
	{
		ft_calculate_sorting_b_to_a(stack);
		ft_sorting_apply_and_reset(stack);
	}
	if (stack->a->head->data.nb > stack->a->tail->data.nb)
		stack->mov.a.ra++;
	ft_sorting_apply_operations(stack);
	printf("\nFinql Results\n");
	ft_list_print_data(*stack->a);
}

/* Calculate for each nbr is B stack the number of moves needed to be inserted in A Stack. We chose the one with the less amount of moves and we insert it.*/
void	ft_calculate_sorting_b_to_a(t_stacks *stack)
{
	t_node	*current[2];
	t_node	*min;
	size_t	i;

	current[1] = ft_node_next(*stack->b, 1, 0);
	min = current[1];
	i = 0;
	while (i < stack->b->size)
	{
		current[0] = ft_node_next(*stack->a, 0, 0);
		current[1]->nb_optn = 0;
		current[1]->mov = ft_mov_initiliaze();
		printf("mov=%zu\n", current[1]->mov.b.rb);
		//this loop do : find how many rotations A, to insert 1st nb from stack B, B is the smallest number or we rotated the whole  Stack A
		while (/*current[1]->data.nb > current[0]->data.nb
			&&*/ current[1]->mov.a.ra < stack->a->size)
		{
			current[1]->mov.a.ra += 1;
			current[1]->nb_optn++;
			printf("\tStack\tA\t||\tStack\tB\n\t\t%d\t||\t\t%d\n", current[0]->data.nb, current[1]->data.nb);
			current[0] = ft_node_next(*stack->a, 0, -1);
		}
		//If StacB number is bigger than all numbers in STack A,  nbr of rotation fo Stack A will be equal to its size. We reset them to 0 in order to not waste 3 actions.
		if (current[1]->mov.a.ra <= stack->a->size)
		{
			current[1]->nb_optn -= (current[1]->mov.a.ra - 1);
			current[1]->mov.a.ra = 0;
		}
		//this do we move to next nbr in B stack.
		current[1]->mov.b.rb += i;
		current[1]->nb_optn += i;
		//We compare the number of oeprations done agaisnt the minimum, and copy it if necessary
		if (min->nb_optn > current[1]->nb_optn)
			min = current[1];
		printf("\nmin %zu\n", min->nb_optn);
		current[1] = ft_node_next(*stack->b, 1, -1);
		i++;
	}
	//this do
	stack->mov = min->mov;
	stack->mov.swap.pa += 1;
}

t_node	*ft_node_next(t_list list, size_t i, size_t init)
{
	static t_node	*current[10];
	static t_node	*tail[10];
	static t_node	*tmp[10];

	if (init == 0)
	{
			current[i] = list.head;
			tail[i] = list.tail;
	}
	else
	{
		tmp[i] = XOR(current[i]->npx, tail[i]);
		tail[i] = current[i];
		current[i] = tmp[i];
	}
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
