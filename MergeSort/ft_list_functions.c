#include "MergeSort.h"

t_node	*XOR(t_node *a, t_node *b)
{
	return (t_node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

t_node	*ft_node_create(t_data data, t_node *npx)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->npx;
	return (new);
}

t_node	ft_node_insert(t_node **head, t_node **tail, t_data data)
{
	
}

t_node	ft_node_insert_before()
{

}

int	main()
{
	t_node	*start = NULL;
	
	//Insert 6 . So linked list becomes  6 -> NULL
	//
	//i // Insert 7 at the beginning. So linked list becomes
    // 7->6->NULL
	

	// Insert 1 at the beginning. So linked list becomes
	// 1->7->6->NULL

	  // Insert 4 at the end. So linked list becomes
    // 1->7->6->4->NULLi
	
	// Insert 8, after 7. So linked list becomes
    // 1->7->8->6->4->NULL
	
	//print list

}
