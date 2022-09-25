/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:06:37 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 01:18:27 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stack;
	t_list		*list_a;

	if (argc == 1)
	{
		ft_printerror("Error\n");
		return (0);
	}	
	if (argc >= 2)
	{
		// if (argc == 2 && ft_nbr_words(argv[1], ' ') > 1)
		// 	list_a = ft_split_argument(argv[1]);
		// else
		list_a = ft_parsing(argv, argc);
		//ft_list_print_data(*list_a);
		if (!list_a)
			return (1);
		stack = ft_stack_initilize(list_a);
		if (!stack)
			return (1);
		if (stack->a->head)
		{
			ft_pre_sorting_general(list_a);
			//ft_printf("=====Values before sorting=====\n");
			//ft_list_print_data(*stack->a);
			ft_sorting_main(stack);
			//ft_list_print_data(*stack->a);
			// ft_list_print_data(*stack->a);
			// ft_list_print_data(*stack->b);
			// printf("=====Values after sorting=====\n");
			// ft_list_print_data(*stack->a);
			// ft_printf("%s", stack->operations);
			///ft_list_print_data(*stack->a);
			if (ft_list_is_sorted(*stack->a))
			{
				//ft_list_print_data(*stack->a);
				// if (stack->operations != NULL)
				// 	ft_printf("%s", stack->operations);
			}
			else
				ft_printerror("Error\n");
			ft_stack_free(stack);
		}
		else
		{
			ft_printerror("Error\n");
			ft_stack_free(stack);
			return (1);
		}
	}
	return (0);
}