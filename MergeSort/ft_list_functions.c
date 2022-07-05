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

t_list	ft_list_create(t_node *head, t_node *tail, size_t size)
{
	t_list	new_list;

	new_list.head = head;
	new_list.tail = tail;
	new_list.size = size;
	return (new_list);
}

void	ft_node_insert_end(t_list *list, t_data data)
{
	t_node	*new;

	if (!list->head && !list->tail)
		*list = ft_list_create(ft_node_create(data, NULL), 
		ft_node_create(data, NULL), 0);
	else if (list->head == list->tail)
		list->tail = ft_node_create(data, NULL);
	else
	{
		new = ft_node_create(data, XOR(list->head, list->tail));
		if (!list->head->npx || !list->tail->npx)
		{
			list->tail->npx = XOR(new, list->head);
			list->head->npx = XOR(new, list->tail);
		}
		else
		{
			list->tail->npx = XOR(new, XOR(list->head->npx, list->tail));
			list->head->npx = XOR(new, XOR(list->tail->npx, list->head));
		}
		list->tail = new;
	}
	list->size++;
	ft_list_new_index(list);

}


void	ft_node_insert_start(t_list *list, t_data data)
{
	t_node	*new;

	new = ft_node_create(data, XOR(list->head, list->tail));
	if ((!list->head && !list->tail) || !list)
		*list = ft_list_create(new, new, 0);
	else if (list->head == list->tail)
		*list = ft_list_create(ft_node_create(data, NULL), list->head, 1);
	else
	{
	//	new = ft_node_create(data, XOR(list->head, list->tail));
		if (!list->head->npx || !list->tail->npx)
		{
			list->head->npx = XOR(new, list->tail);
			list->tail->npx = XOR(new, list->head);
		}
		else
		{
			list->head->npx = XOR(new, XOR(list->tail->npx, list->head));
			list->tail->npx = XOR(new, XOR(list->head->npx, list->tail));
		}
		list->head = new;
	}
	list->size++;
	ft_list_new_index(list);
}

void	ft_list_new_index(t_list *list)
{
	t_node	*current;
	t_node	*tmp;
	t_node	*t;
	size_t		i;

	t = list->tail;
	current = list->head;
	i = 0;
	
	if (list->size < 3)
	{
		list->head->data.index = 0;
		list->tail->data.index = 1;
	}
	else 
	{
		while (i < list->size)
		{
			current->data.index = i++;
			tmp = XOR(current->npx, t);
			t = current;
			current = tmp;
		}
	}
}

/*void	ft_node_insert_end(t_list *list, t_data data)*/
/*{*/
	/*t_node	*new;*/
	/*t_node	*h;*/
	/*t_node	*t;*/

	/*h = *head;*/
	/*t = *tail;*/
	/*if (!head && !tail) {*/
		/**head = ft_node_create(data, NULL);*/
		/**tail = *head;*/
	/*}*/
	/*else if (h == t)*/
		/**tail = ft_node_create(data, NULL);*/
	/*else*/
	/*{*/
		/*new = ft_node_create(data, XOR(h, t));*/
		/*if (!h->npx || !t->npx)*/
		/*{*/
			/*t->npx = XOR(new, h);*/
			/*h->npx = XOR(new, t);*/
		/*}*/
		/*else{*/
			/*h->npx = XOR(new, XOR(t->npx, h));*/
			/*t->npx = XOR(new, XOR(h->npx, t));*/
		/*}*/
		/**head = h;*/
		/**tail = t;*/
	/*}*/
	/*list->size++;*/
/*}*/


//Print all the list, We compare the index inside each node and compare it
//to the size of the list
void	ft_list_print_data(t_list list)
{
	t_node	*current;
	t_node	*tmp;
	t_node	*t;
	size_t	i;

	t = list.tail;
	current = list.head;
	i = 0;
	if (list.size < 3)
	{
		printf("Index:[%zu]= %d\n", current->data.index, list.head->data.nb);
		printf("Index:[%zu]= %d\n", list.tail->data.index, list.tail->data.nb);
	}
	else
	{
		while (i < list.size)
		{
			printf("Index:[%zu]= %d\n", current->data.index, current->data.nb);
			tmp = XOR(current->npx, t);
			t = current;
			current = tmp;
			i++;
		}
	}
}

int	main()
{
	t_data d,a,t,s;
	t_node	*head = NULL, *tail = NULL;
	t_list	list;
	
	list = ft_list_create(head, tail, 0);
	//Insert 6 . So linked list becomes  6 -> NULL
	d.nb = 0;
	d.index = 0;
	a.nb = 1;
	a.index = 0;
	t.nb = 589;
	t.index = 0;
	s.nb = 9875;
	s.index = 0;
	ft_node_insert_start(&list, d);
	ft_list_print_data(list);
	printf("---------------\n");
	ft_node_insert_start(&list, a);
	ft_list_print_data(list);
	printf("---------------\n");
	ft_node_insert_start(&list, t);
	ft_list_print_data(list);
	printf("---------------\n");
	ft_node_insert_start(&list, s);
	ft_list_print_data(list);
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
