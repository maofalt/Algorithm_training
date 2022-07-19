/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:06:37 by motero            #+#    #+#             */
/*   Updated: 2022/07/19 14:47:45 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stack;
	t_list		*list_a;

	if (argc >= 2)
	{
		list_a = ft_parsing(argv, argc);
		stack = ft_stack_initilize(list_a);
		if (stack->a->head)
		{
			printf("=====Values before sorting=====\n");
			ft_list_print_data(*stack->a);
			ft_sorting_main(stack);
			if (ft_list_is_sorted(*stack->a))
			{
				printf("=====Values after sorting=====\n");
				ft_list_print_data(*stack->a);
			}
			else
				printf("**NOT SORTED CORRECTLY\n");
			ft_stack_free(stack);
		}
		else
		{
			printf("Error while Parsing\n");
			ft_stack_free(stack);
			return (1);
		}
	}
	else
	{
		printf("There are not numbers\n");
	}
	//ft_stack_free(stack);
	return (0);
}
