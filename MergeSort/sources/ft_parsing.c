/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 01:46:04 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
/* Parse entry numbers
-1  Creation of list struct
-2a While loop, as long as it is a valid int number we insert a new node into our list
-2b Same while loop, we identify the extremes of our function
-3 if error during a number we free the list*/
t_list	*ft_parsing(char **raw_nb, int nb_arg)
{
	int		i;
	int		j;
	int 	k;
	char	**str;
	t_list	*list_a;
	t_data	data;

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
			free(list_a);
			return (NULL);
		}
		i = 0;
		//printf("nbr nbrs %zu\n", ft_nbr_words(raw_nb[1], ' '));
		while (i < (int)(ft_nbr_words(raw_nb[k], ' ')) && !ft_verify_number(str[i]))
		{
			//printf("[%d]=%d\n", i, ft_atoi(str[i]));
			data = ft_data_create(ft_atoi(str[i]), j++);
			//printf("-->data %zu\n", data.index);
			ft_node_insert_end(list_a, data);
			ft_extremes_parsing(list_a, data);
			i++;
		}
		if (i != (int)ft_nbr_words(raw_nb[k], ' ') || ft_check_doubles(list_a))
		{
			ft_list_free(list_a);
			ft_free_split(str);
			return (list_a);
		}
		ft_free_split(str);
		k++;
	}
	// if (nb_arg > 2)
	// {
	// 	i = 2;
	// 	while (!ft_verify_number(raw_nb[i]))
	// 	{
	// 		data = ft_data_create(ft_atoi(raw_nb[i]), j++);
	// 		ft_node_insert_end(list_a, data);
	// 		ft_extremes_parsing(list_a, data);
	// 		if (i == nb_arg - 1)
	// 			break ;
	// 		i++;
	// 	}
	// 	if ((ft_verify_number(raw_nb[i])) || ft_check_doubles(list_a))
	// 		ft_list_free(list_a);
	// }
	return (list_a);
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

int	ft_max_min(int sign)
{
	if (sign == 1)
		return (INT_MAX);
	else
		return (INT_MIN);
}

int	ft_atoi(const char *nptr)
{
	int		num;
	int		sign;
	char	c;

	num = 0;
	sign = 1;
	c = *nptr;
	while (ft_isspace(*nptr))
		c = *nptr++;
	c = *nptr;
	if (c == '-')
		sign = 1 - (2 * (*nptr++ == '-'));
	if (c == '+')
		c = *nptr++;
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num += *nptr++ - '0';
	}
	return (num * sign);
}

int	ft_parsing_allowed_chars(char *str)
{
	const char	allow_char[] = "0123456789-+";
	int			size;
	int			i;
	int			j;
	int			exist;

	i = 0;
	size = strlen(str);
	while (i < size)
	{
		j = 0;
		exist = 0;
		while (j < 12)
		{
			if (str[i] == allow_char[j])
				exist++;
			j++;
		}
		if (!exist)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_parsing_extract_nbr(char *nbr)
{
	const int	nbr_size = strlen(nbr);
	char		*nbr_small;
	int			i;
	int			k;

	k = 0;
	while (ft_isspace(nbr[k]))
		k++;
	while (nbr[k] == '-' || nbr[k] == '+')
		k++;
	while (nbr[k] == '0')
		k++;
	if (nbr[k] == 0)
		k--;
	nbr_small = malloc(sizeof(char) * (nbr_size - k));
	if (!nbr_small)
		return (NULL);
	i = 0;
	while (i < (nbr_size - k - 1))
	{
		nbr_small[i] = nbr[k + i];
		i++;
	}
	nbr_small[i] = 0;
	return (nbr_small);
}

int	ft_count_minus(char *nbr)
{
	char	c;
	int		i;

	c = *nbr;
	i = 0;
	while (ft_isspace(*nbr))
		c = *nbr++;
	while (*nbr)
		if (*nbr++ == '-')
			i++;
	if (i > 1)
		return (1);
	else
		return (0);
}

int	ft_count_plus(char *nbr)
{
	char	c;
	int		i;

	c = *nbr;
	i = 0;
	while (ft_isspace(*nbr))
		c = *nbr++;
	while (*nbr)
		if (*nbr++ == '+')
			i++;
	if (i > 1)
		return (1);
	else
		return (0);
}

int	ft_check_forbidden_order(char *nbr)
{
	char	c;
	int		min;
	int		plus;

	c = *nbr;
	min = 0;
	plus = 0;
	while (ft_isspace(*nbr))
		c = *nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			min = 1;
		if (*nbr == '+')
			plus = 1;
		c = *nbr++;
	}
	if (!ft_isdigit(*nbr) || plus + min == 2)
		return (1);
	while (*nbr++)
	{
		if (*nbr == '-' || *nbr == '+')
			return (1);
	}
	return (0);
}
//Return 1 if both are number and no larger than Int max
//else return 0
//forbidden strlen here correct!!
int	ft_verify_number(char *nbr)
{
	char		*nbr_small;
	int			tmp_nbr;
	int			res;
	int			nbr_size;

	if (ft_parsing_allowed_chars(nbr))
		return (1);
	if (ft_count_minus(nbr) || ft_count_plus(nbr))
		return (1);
	if (ft_check_forbidden_order(nbr))
		return (1);
	nbr_small = ft_parsing_extract_nbr(nbr);
	if (!nbr_small)
		return (1);
	nbr_size = ft_strlen(nbr_small);
	if (nbr_size > 9)
	{
		free(nbr_small);
		return (1);
	}
	res = 0;
	if (nbr_small)
		tmp_nbr = ft_atoi(nbr_small);
	if (nbr[0] == '-')
		tmp_nbr = -1 * tmp_nbr;
	if (tmp_nbr > (INT_MAX / 10) || tmp_nbr < (INT_MIN / 10))
		res = 1;
	if (tmp_nbr == (INT_MAX / 10) && (nbr[ft_strlen(nbr)- 1] - '0') > 7)
		res = 1;
	if (tmp_nbr == (INT_MIN / 10) && (nbr[ft_strlen(nbr) - 1] - '0') > 8)
		res = 1;
	free(nbr_small);
	return (res);
}
