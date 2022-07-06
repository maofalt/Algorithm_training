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
	else if (list->head == list->tail)
			*list = ft_list_create(new, list->head, 1);
	else
	{
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
	else if ((list->head == list->tail) || list->size == 1)
		*list = ft_list_create(new, list->head, 1);
	else
	{
		if (list->size == 2)
		{
			printf("we enter here\n");
			list->head->npx = XOR(new, list->tail);
			list->tail->npx = XOR(new, list->head);
		}
		else
		{
			//error is here. Last is not relink to 1 and probably the same in the other sense
			list->head->npx = XOR(new, XOR(list->head->npx, list->tail));
			list->tail->npx = XOR(new, XOR(list->tail->npx, list->head));
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
		while (i < list.size + 2)
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

int	main()
{
	t_data d,a,t,s;
	t_node	*head = NULL, *tail = NULL;
	t_list	list;
	//int		test = 0;

	list = ft_list_create(head, tail, 0);
	d.nb = 1;
	d.index = 0;
	a.nb = -96;
	a.index = 0;
	t.nb = 589;
	t.index = 0;
	s.nb = 9875;
	s.index = 0;
	ft_node_insert_start(&list, d);
	ft_node_insert_start(&list, a);
	ft_node_insert_start(&list, t);
	ft_node_insert_start(&list, s);
	ft_list_print_data(list);
	//list2 = ft_list_create(head, tail, 0);
	//list = ft_list_rotate(list);
	//ft_list_print_data(list);
	ft_list_free(&list);
}
