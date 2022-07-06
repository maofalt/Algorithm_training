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

typedef struct s_node
{
	t_data			data;
	struct s_node*	npx;
}					t_node;

typedef struct s_list
{
	t_node		*head;
	t_node		*tail;
	size_t		size;
}				t_list;

/*############################################################################*/
/*                            NODE FUNCTIONS                                 */
/*############################################################################*/

/* retuns XORed value of the node addresses */
t_node *XOR(t_node *a, t_node *b);
t_node	*ft_node_create(t_data data, t_node *npx);
t_list	ft_list_create(t_node *head, t_node *tail, size_t size);
void	ft_node_insert_end(t_list *list, t_data data);
void	ft_node_insert_start(t_list *list, t_data data);
void	ft_list_new_index(t_list *list);
void	ft_list_print_data(t_list list);
void	ft_list_free(t_list *list);

/*############################################################################*/
/*                          PARSING FUNCTIONS                                 */
/*############################################################################*/

#endif
