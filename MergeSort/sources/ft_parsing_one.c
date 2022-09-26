/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 02:49:44 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_list	*ft_parsing(char **raw_nb, int nb_arg)
{
	int		j;
	int		k;
	char	**str;
	t_list	*list_a;

	k = 1;
	j = 0;
	list_a = ft_list_create(NULL, NULL, 0);
	if (!list_a)
		return (NULL);
	while (k < nb_arg)
	{
		str = ft_split(raw_nb[k], ' ');
		if (!str)
		{
			ft_list_free(list_a);
			return (NULL);
		}
		if (ft_parse_data(list_a, raw_nb[k], str, j))
			return (list_a);
		j++;
		k++;
		ft_free_split(str);
	}
	return (list_a);
}

//* Parse entry numbers
//-1  Creation of list struct
//-2a While loop, as long as it is a valid 
//int number we insert a new node into our list
//-2b Same while loop, we identify the extremes of our function
//-3 if error during a number we free the list*/
int	ft_parse_data(t_list *list_a, char *raw_nb, char **str, int j)
{
	int		i;
	t_data	data;

	i = 0;
	while (i < (int)(ft_nbr_words(raw_nb, ' ')) && !ft_verify_number(str[i]))
	{
		data = ft_data_create(ft_atoi(str[i++]), j);
		ft_node_insert_end(list_a, data);
		ft_extremes_parsing(list_a, data);
	}
	if (i != (int)ft_nbr_words(raw_nb, ' ') || ft_check_doubles(list_a))
	{
		ft_list_free(list_a);
		ft_free_split(str);
		return (1);
	}
	return (0);
}

size_t	ft_check_doubles(t_list *list)
{
	t_node	*nodes[2];
	size_t	i;
	size_t	j;
	size_t	k;
	int		nb;

	nodes[0] = list->head;
	nodes[1] = list->tail;
	i = 0;
	while (i++ < list->size)
	{
		j = 0;
		nb = nodes[0]->data.nb;
		while (j++ < list->size - i)
		{
			ft_node_next(&nodes[0], &nodes[1]);
			if (nb == nodes[0]->data.nb)
				return (1);
		}
		k = 1 + i;
		while (k--)
			ft_node_next(&nodes[0], &nodes[1]);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == ' ');
}
