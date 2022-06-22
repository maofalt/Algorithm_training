#ifndef MERGESORT_H
# define MERGESORT_H

//Note structure of a memory efficient doubly linked list, npx store the XOR 
//of next and previous node
typedef struct node
{
	int			value;
	int			index;
	struct node	*npx;
}				node;

/* retuns XOred alue fo the node addresses */
typedef struct	node *XOR(node *a, node *b)
{
	return (node *) ((unsigned int) (a) ^ (usigned int) (b));
}			xor_add;

#endif
