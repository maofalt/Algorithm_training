#include "MergeSort.h"

t_node	*XOR(t_node *a, t_node *b)
{
	return (t_node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

t_node	*ft_node_create(t_data data, t_node *npx)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->npx = npx;
	return (new);
}

//Inserted at the end of the list
t_node	ft_node_insert(t_node **head, t_node **tail, t_data data)
{
	t_node	*new;
	t_node	*h;
	t_node	*t;
	t_node	npx;

	h = *head;
	t = *tail;
	if (!head && !tail) {
		new = ft_node_create(data, NULL);
		*head = new;
		*tail = new;
	}
	else if (h == t)
		*tail = ft_node_create(data, NULL);
	else
	{
		new = ft_node_create(data, XOR(h, t));
		if (!h->npx || !t->npx)
		{
			t->npx = XOR(new, h);
			h->npx = XOR(new, t);
		}
		else{
			h->npx = XOR(new, XOR(t->npx, h));
			t->npx = XOR(new, XOR(h->npx, t));
		}
	}
}

int	main()
{
	t_node	*start = NULL;
	
	(void)start;
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
