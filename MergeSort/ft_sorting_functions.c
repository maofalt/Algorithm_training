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

void    ft_sorting_main(t_stacks  stack)
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
     if (stack.a->size == 2)
    {
        if  (ft_list_is_sorted(stack.a));
            stack.operations = ft_instructions_empty();
        else
            
    }
    //Size 3

    //Size n < Size 5

    //Size n < Size 200

    return (instructions);

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