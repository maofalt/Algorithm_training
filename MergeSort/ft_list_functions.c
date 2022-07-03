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

t_list	ft_list_create(t_list *node)
{
	t_list	new_list;

	new_list.head = NULL;
	new_list.tail = NULL;
	new_list.size = 0;
	return (new_list);
}

//Inserted at the end of the list
void	ft_node_insert(t_list *list, t_data data)
{
	t_node	*new;
	t_node	*before;
	t_node	*after;

	if (list->size == 0) 
		list->head = ft_node_create(data, NULL);
	else if (list->size == 1 && data.index == 0)
	{
		list->tail = list->head;
		list->head = ft_node_create(data, NULL);
	}
	else if (list->size == 1 && data.index == 1)
		list->tail = ft_node_create(data, NULL);
	else
	{
		new = ft_node_create(data, XOR(before, after));
		if (list->size == 2)
		{
			after->npx = XOR(new, before);
			before->npx = XOR(new, after);
		}
		before = ft_list_find_index_add();
		after = ft_list_get_next_add();
		else
		{
			h->npx = XOR(new, XOR(t->npx, h));
			t->npx = XOR(new, XOR(h->npx, t));
		}
	}
	list->size++;
	
}

// void	ft_node_insert(t_node **head, t_node **tail, t_data data)
// {
// 	t_node	*new;
// 	t_node	*h;
// 	t_node	*t;

// 	h = *head;
// 	t = *tail;
// 	if (!head && !tail) {
// 		head = ft_node_create(data, NULL);
// 		*tail = *head;
// 	}
// 	else if (h == t)
// 		*tail = ft_node_create(data, NULL);
// 	else
// 	{
// 		new = ft_node_create(data, XOR(h, t));
// 		if (!h->npx || !t->npx)
// 		{
// 			t->npx = XOR(new, h);
// 			h->npx = XOR(new, t);
// 		}
// 		else{
// 			h->npx = XOR(new, XOR(t->npx, h));
// 			t->npx = XOR(new, XOR(h->npx, t));
// 		}
// 		*head = h;
// 		*tail = t;
// 	}
// }

void	ft_list_print_data(t_list list)
{
	t_node	*current;
	t_node	*t;
	t_node	*tmp;

	current = head;
	t = tail;
	while (current->data.index != list.size)
	{
		printf("Index:%d|Nbr:%d\n",current->data.index, current->data.nb);
		tmp = XOR(current->npx, t->npx);
		t = current;
		current = tmp;
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
