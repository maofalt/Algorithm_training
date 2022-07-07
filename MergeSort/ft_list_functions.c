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

	new = ft_node_create(data, XOR(list->head, list->tail));
	if ((!list->head && !list->tail) || !list)
		*list = ft_list_create(new, new, 0);
	else if ((list->head == list->tail) || list->size == 1)
		*list = ft_list_create(list->head, new, 1);
	else
	{
		if (list->size == 2)
		{
			list->head->npx = XOR(new, list->tail);
			list->tail->npx = XOR(new, list->head);
		}
		else
		{
			list->head->npx = XOR(new, XOR(list->head->npx, list->tail));
			list->tail->npx = XOR(new, XOR(list->tail->npx, list->head));
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
	else if ((list->head == list->tail) || list->size == 1)
		*list = ft_list_create(new, list->head, 1);
	else
	{
		if (list->size == 2)
		{
			list->head->npx = XOR(new, list->tail);
			list->tail->npx = XOR(new, list->head);
		}
		else
		{
			list->head->npx = XOR(new, XOR(list->head->npx, list->tail));
			list->tail->npx = XOR(new, XOR(list->tail->npx, list->head));
		}
		list->head = new;
	}
	list->size++;
	ft_list_new_index(list);
}

//We remove a node from the top
void	ft_node_remove(t_list *list, t_node *node)
{
	if ((!list->head && !list->tail) || !list)
		return ;
	else if ((list->head == list->tail) || list->size == 1)
	{
		node = list->head;
		*list = ft_list_create(NULL, NULL, 0);
		node->npx = NULL;
	}
	else if (list->size == 2)
	{
		node = list->head;
		*list = ft_list_create(list->tail, list->tail, 1);
		list->tail->npx = NULL;
		node->npx = NULL;
	}
	else if (list->size == 3)
	{
		node = list->head;
		*list = ft_list_create(XOR(node->npx, list->tail), list->tail, 2);
		list->head->npx = NULL;
		list->tail->npx = NULL;
		node->npx = NULL;
	}
	else
	{
		node = list->head;
		*list = ft_list_create(XOR(node->npx, list->tail), list->tail, list->size - 1);
		list->head->npx = XOR(XOR(list->head->npx, node),list->tail);
		list->tail->npx = XOR(XOR(node, list->tail->npx),list->head);
		node->npx = NULL;
	}
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

void	ft_list_free(t_list *list)
{
	t_node			*current;
	t_node			*tmp;
	t_node			*t;
	size_t			i;

	t = list->tail;
	current = list->head;
	if (list->size == 1)
	{
		//free(list->head->npx);
		free(list->head);
	}
	else if (list->size == 2)
	{
		//free(list->head->npx);
		free(list->head);
		//free(list->tail->npx);
		free(list->tail);
	}
	else
	{	
		i = 0;
		while (i++ < list->size)
		{
			
			tmp = XOR(current->npx, t);
			free(current);
			t = current;
			current = tmp;
		}
	}
}

t_list	ft_list_rotate(t_list list)
{
	t_node	*new_head;
	t_node	*new_tail;
	t_list	new_list;

	new_tail = list.head;
	new_head = XOR(list.head->npx, list.tail);
	new_list = ft_list_create(new_head, new_tail, list.size);
	ft_list_new_index(&new_list);
	return (new_list);
}

t_list	ft_list_reverse_rotate(t_list list)
{
	t_node	*new_head;
	t_node	*new_tail;
	t_list	new_list;

	new_tail = XOR(list.tail->npx, list.head);
	new_head = list.tail;
	new_list = ft_list_create(new_head, new_tail, list.size);
	ft_list_new_index(&new_list);
	return (new_list);
}

int	main()
{
	t_data d,a,t,s;
	t_node	*head = NULL, *tail = NULL;
	t_list	list;
	

	list = ft_list_create(head, tail, 0);
	d.nb = 1;
	d.index = 0;
	a.nb = -2;
	a.index = 0;
	t.nb = 3;
	t.index = 0;
	s.nb = 4;
	s.index = 0;
	ft_node_insert_end(&list, d);
	ft_node_insert_end(&list, a);
	ft_node_insert_end(&list, t);
	ft_node_insert_start(&list, s);
	ft_list_print_data(list);
	//int		i = 0;
	//list2 = ft_list_create(head, tail, 0);
	// printf("After rotation \n");
	// while (i++ < 4)
	// {
	// 	printf("Rotation [%d]\n", i);
	// 	list = ft_list_rotate(list);
	// 	ft_list_print_data(list);
	// }
	ft_list_free(&list);
}
