/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:51:03 by motero            #+#    #+#             */
/*   Updated: 2022/07/08 20:10:58 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"

t_stacks    ft_sorting_main(t_stacks  stack)
{


    //Return a an array with the insructions or printf  at each action
    //depedning size of stack

    //*****Protype***//
    //---------Cases-------
    //Size 1
    if (stack.a->size == 1)
    {
       stack.operations = ft_instructions_empty();
    }
    //Size 2
    else if (stack.a->size == 2)
    {
        if (ft_list_is_sorted(*stack.a))
            stack.operations = ft_instructions_empty();
        else
        {
            stack.mov.ra = 1;
            ft_sorting_apply_operations(stack);
        }
    }
    //Size 3
    else if (stack.a->size == 3)
    {
        if  (ft_list_is_sorted(*stack.a))
            stack.operations = ft_instructions_empty();
        else
        {
            stack.mov.ra = 1;
            ft_sorting_apply_operations(stack);
        }
    }
    else if (stack.a->size > 3 && stack.a->size <= 5)
    {
        if  (ft_list_is_sorted(*stack.a))
            stack.operations = ft_instructions_empty();
        else
        {
            stack.mov.ra = 1;
            ft_sorting_apply_operations(stack);
        }
    }
    else if (stack.a->size > 5)
    {
        if  (ft_list_is_sorted(*stack.a))
            stack.operations = ft_instructions_empty();
        else
        {
            stack.mov.ra = 1;
            ft_sorting_apply_operations(stack);
        }
    }
    return (stacks);
}

char    *ft_instructions_empty(void)
{
    char    *str;
    
    str = (char *)malloc(sizeof(char) * 2);
    if (!str)
        return (NULL);
    str[0] = '\n';
    str[1] = '\0';
    return (str);
}

int ft_list_is_sorted(t_list list)
{
    int             i;
    int             max;
    t_node			*current;
	t_node			*next;
	t_node			*t;

    t = list.tail;
	current = list.head;
    if (list.size == 1)
		return (1);
	else if (list.size == 2)
		return(list.head->data.nb < list.tail->data.nb);
	else
	{	
		i = 0;
        max = list.head->data.nb;
		while (i++ < list.size)
		{
			next = XOR(current->npx, t);
            if (max > next->data.nb)
                return (0);
			max = next->data.nb;
            t = current;
			current = next;
		}
        return (1);
	}
}

t_list    ft_sorting_apply_operations(t_list list)
{
    
    ft_stack_swap(stack);
    ft_stack_push(t_stacks stack)
    ft_stack_rotate(t_stacks stack)
    ft_stack_reverse_rotate(t_stacks stack)
    mov = ft_mov_initiliaze();
}