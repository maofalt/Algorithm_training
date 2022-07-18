/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeSort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:36:43 by motero            #+#    #+#             */
/*   Updated: 2022/07/18 15:11:34 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGESORT_H
# define MERGESORT_H

# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>


/*############################################################################*/
/*                             NODE DEFINITION                                */
/*############################################################################*/

//Note structure of a memory efficient doubly linked list, npx store the XOR 
//of next and previous node
//Normally a Circular XOR list is impossible however we just need t keep track
//of both  the head and tail ptrs (handling edge cases of 1 and 2 elements)
typedef struct s_data
{
	int		nb;
	size_t	index;
}	t_data;

//Our node structure, possessing npx (prev and next address XORed), as well as data structur
typedef struct s_node
{
	t_data			data;
	t_mov			mov;
	struct s_node*	npx;
}					t_node;

typedef struct s_list
{
	t_node		*head;
	t_node		*tail;
	size_t		size;
}				t_list;

typedef struct s_mov
{
	t_a			a;
	t_swap		swap;
	t_b			b;
}				t_mov;

typedef struct s_a
{
	size_t		ra;
	size_t		rra;
	size_t		rr;
	size_t		rrr;
}				t_a;

typedef struct s_swap
{
	size_t		sa;
	size_t		sb;
	size_t		ss;
	size_t		pa;
	size_t		pb;
}				t_swap;

typedef struct s_b
{
	size_t		rb;
	size_t		rrb;
}				t_b;

typedef struct s_stacks
{
	t_list		*a;
	t_list		*b;
	t_mov		mov;
	char		*operations;
	size_t		total_moves;
}				t_stacks;

/*############################################################################*/
/*                            NODE FUNCTIONS                                  */
/*############################################################################*/

/* retuns XORed value of the node addresses */
t_node *XOR(t_node *a, t_node *b);
//Creates new node from a dats structure and from the XOR address of previous &&
// next nodes
t_node	*ft_node_create(t_data data, t_node *npx);
//Remove the head node of the list structure, and returns it,. reliinking the nodes.
t_node	*ft_node_remove(t_list *list);
//Insert node as a head and a tail respectiveloy, as well as incresing decreasing the list 
//size and reassessing the index 
void	ft_node_insert_end(t_list *list, t_data data);
void	ft_node_insert_start(t_list *list, t_data data);

/*############################################################################*/
/*                            DATA FUNCTIONS                                  */
/*############################################################################*/
//Create a data sttructure, passing the nb and the index. 
t_data	ft_data_create(int nb, size_t index);

/*############################################################################*/
/*                            LIST FUNCTIONS                                  */
/*############################################################################*/

//Create a list structure, allowing us to know at any moment the head, tail and size of our list.
t_list	ft_list_create(t_node *head, t_node *tail, size_t size);
//After modification tot he list, we reindex all the lsit absed on the head, tail and size
void	ft_list_new_index(t_list *list);
//Forbidden print data. Refactored with your ft_prinft
void	ft_list_print_data(t_list list);
//Free the entire list passed
void	ft_list_free(t_list *list);
//Rotates the list "upwards", the head becomes the last , and the second become the first
t_list	ft_list_rotate(t_list list);
t_list	ft_list_reverse_rotate(t_list list);
//We swap the 1st and 2nd nodes of the list
void	ft_list_swap_first_nodes(t_list *list);
//
void	ft_list_cut_past(t_list	*a, t_list *b);
// Reset mov quantas after each pre-calculation of opperations
void	ft_list_reset_mov(t_list *list);


/*############################################################################*/
/*                            STACK OPERATIONS                                */
/*############################################################################*/

void    ft_stack_reverse_rotate(t_stacks stack);
void    ft_stack_rotate(t_stacks stack);
void    ft_stack_push(t_stacks stack);
void    ft_stack_swap(t_stacks stack);
t_mov   ft_mov_initiliaze(void);
t_stacks    ft_stack_create(t_list *list_a, t_list *list_b);

/*############################################################################*/
/*                          PARSING FUNCTIONS                                 */
/*############################################################################*/

t_list	ft_parsing(char **raw_nb, int nb_arg);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_max_min(int sign);
int		ft_atoi(const char *nptr);
int		ft_verify_number(char *nbr);
int		ft_parsing_allowed_chars(char *str);
char	*ft_parsing_extract_nbr(char *nbr);

/*############################################################################*/
/*                          SORTING FUNCTIONS                                 */
/*############################################################################*/


t_stacks    ft_sorting_main(t_stacks  stack);
t_list    	ft_sorting_apply_operations(t_stacks stack);
int			ft_list_is_sorted(t_list list);
char    	*ft_instructions_empty(void);
void    	ft_sorting_apply_rotation(t_stacks stack);
void		ft_sorting_apply_rev_rotation(t_stacks stack);
void    	ft_sorting_apply_swap(t_stacks stack);
void    	ft_sorting_apply_push(t_stacks stack);
void  		ft_move_compound_rotation(t_stacks stack);
void		ft_move_compound_swap(t_stacks stack);

#endif
