/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:51:03 by motero            #+#    #+#             */
/*   Updated: 2022/07/18 14:35:37 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"

t_stacks    ft_sorting_main(t_stacks  stack)
{


    //Return a an array with the insructions or printf  at each action
    //depedning size of stack
    // if there are no moves we move first two to the stack b
    if (stack.total_moves == 0)
    {
        stack.mov.swap.pb = 2;
        ft_sorting_apply_operations(stack);
    }
    else 
    {
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
                stack.mov.a.ra = 1;
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
                stack.mov.a.ra = 1;
                ft_sorting_apply_operations(stack);
            }
        }
        else if (stack.a->size > 3 && stack.a->size <= 5)
        {
            if  (ft_list_is_sorted(*stack.a))
                stack.operations = ft_instructions_empty();
            else
            {
                stack.mov.a.ra = 1;
                ft_sorting_apply_operations(stack);
            }
        }
        else if (stack.a->size > 5)
        {
            if  (ft_list_is_sorted(*stack.a))
                stack.operations = ft_instructions_empty();
            else
            {
                stack.mov.a.ra = 1;
                ft_sorting_apply_operations(stack);
            }
        }
    }
    stack.total_moves++;
    return (stack);
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

t_list    ft_sorting_apply_operations(t_stacks stack)
{
    t_mov   mov;

    mov = stack.mov;
    ft_move_compound_rotation(mov);
    ft_stack_rotate(stack);
    ft_stack_reverse_rotate(stack);
    ft_stack_swap(stack);
    ft_stack_push(stack);
    mov = ft_mov_initiliaze();
}

void   ft_move_compound_rotation(t_mov mov)
{
    size_t  min;

    if (mov.a.ra && mov.b.rb)
    {
        if(mov.a.ra > mov.b.rb)
            min = mov.b.rb;
        else
            min = mov.a.ra;
        mov.a.rr = min;
        mov.a.ra -= min;
        mov.b.rb -= min;
    }   
    if (mov.a.rra && mov.b.rrb)
    {
        if(mov.a.rra > mov.b.rrb)
            min = mov.b.rrb;
        else
            min = mov.a.rra;
        mov.a.rrr = min;
        mov.a.rra -= min;
        mov.b.rrb -= min;
    }
}

void   ft_move_compound_swap(t_mov mov)
{
    size_t  min;

    if (mov.swap.sa && mov.swap.sb)
    {
        if(mov.swap.sa > mov.swap.sb)
            min = mov.swap.sb;
        else
            min = mov.swap.sa;
        mov.swap.ss = min;
        mov.swap.sa -= min;
        mov.swap.sb -= min;
    }   
}