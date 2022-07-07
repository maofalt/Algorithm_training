#include "MergeSort.h"


void    ft_stack_swap(t_stacks *stack)
{
    if (stack->mov.sa && stack->mov.sb )
    {
        stack->mov.sa = 0;
        stack->mov.sb = 0;
        stack->mov.ss = 1;
    }
    if ((stack->mov.sa || stack->mov.ss) && stack->a.size > 1)
        ft_list_swap_first_nodes(stack->a);
    if ((stack->mov.sb || stack->mov.ss) && stack->a.size > 1)
        ft_list_swap_first_nodes(stack->b);
}

void    ft_stack_push(t_stacks *stack)
{
    if (stack->mov.pa && stack->b.size < 0)
        ft_list_cut_past(stack->b, stack->a);
    if (stack->mov.pb && stack->a.size < 0)
        ft_list_cut_past(stack->a, stack->b);
}

void    ft_stack_rotate(t_stacks *stack)
{
    if (stack->mov.ra && stack->mov.rb )
    {
        stack->mov.ra = 0;
        stack->mov.rb = 0;
        stack->mov.rr = 1;
    }
    if ((stack->mov.ra || stack->mov.rr) && stack->a.size > 1)
        ft_list_rotate(stack->a);
    if ((stack->mov.rb || stack->mov.rr) && stack->a.size > 1)
        ft_list_rotate(stack->b);
}

void    ft_stack_reverse_rotate(t_stacks *stack)
{
    if (stack->mov.rra && stack->mov.rrb )
    {
        stack->mov.rra = 0;
        stack->mov.rrb = 0;
        stack->mov.rrr = 1;
    }
    if ((stack->mov.rra || stack->mov.rrr) && stack->a.size > 1)
        ft_list_reverse_rotate(stack->a);
    if ((stack->mov.rrb || stack->mov.rrr) && stack->a.size > 1)
        ft_list_reverse_rotate(stack->b);
}