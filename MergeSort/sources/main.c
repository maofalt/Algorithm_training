/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:06:37 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 06:19:09 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_main_sorting(t_stacks *stack)
{
	ft_pre_sorting_general(stack->a);
	ft_sorting_main(stack);
	ft_stack_free(stack);
}

void	ft_main_error(t_stacks *stack)
{
	ft_printerror("Error\n");
	ft_stack_free(stack);
}

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
		list_a = ft_parsing(argv, argc);
		if (!list_a)
			return (1);
		stack = ft_stack_initilize(list_a);
		if (!stack)
			return (1);
		if (stack->a->head)
			ft_main_sorting(stack);
		else
		{
			ft_main_error(stack);
			return (1);
		}
	}
	return (0);
}
