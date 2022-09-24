/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/09/24 16:46:02 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

/* Parse entry numbers
-1  Creation of list struct
-2a While loop, as long as it is a valid int number we insert a new node into our list
-2b Same while loop, we identify the extremes of our function
-3 if error during a number we free the list*/
t_list	*ft_parsing(char **raw_nb, int nb_arg)
{
	int		i;
	int		j;
	t_list	*list_a;
	t_data	data;

	if (raw_nb[0][0] == '.' || raw_nb[0][0] == '/')
		i = 1;
	else
		i = 0;
	list_a = ft_list_create(NULL, NULL, 0);
	j = 0;
	while (!ft_verify_number(raw_nb[i]))
	{
		data = ft_data_create(ft_atoi(raw_nb[i]), j++);
		ft_node_insert_end(list_a, data);
		ft_extremes_parsing(list_a, data);
		if (i == nb_arg - 1)
			break ;
		i++;
	}
	if ((ft_verify_number(raw_nb[i])) || ft_check_doubles(list_a))
		ft_list_free(list_a);
	return (list_a);
}

size_t	ft_check_doubles(t_list *list)
{
	t_node	*c;
	t_node	*t;
	size_t	i;
	size_t	j;
	int		nb;

	c = list->head;
	t = list->tail;
	i = 0;
	while (i++ < list->size)
	{
		j = 0;
		nb = c->data.nb;
		while (j++ < list->size - i)
		{
			ft_node_next(&c, &t);
			printf("Compare %d =? %d\n", nb, c->data.nb);
			if (nb == c->data.nb)
				return (1);
		}
		ft_node_next(&c, &t);
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
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num += *nptr++ - '0';
	}
	return (num * sign);
}

int	ft_parsing_allowed_chars(char *str)
{
	const char	allow_char[] = "0123456789-";
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
		while (j < 11)
		{
			if (str[i] == allow_char[j])
				exist++;
			j ++;
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
	while (nbr[k] == '-')
		k++;
	while (nbr[k] == '0')
		k++;
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

int	ft_check_forbidden_order(char *nbr)
{
	char	c;

	c = *nbr;
	while (ft_isspace(*nbr))
		c = *nbr++;
	while (*nbr == '-')
		c = *nbr++;
	if (!ft_isdigit(*nbr))
		return (1);
	while (*nbr)
	{
		if (*nbr == '-')
			return (1);
		c = *nbr++;
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
	if (ft_count_minus(nbr))
		return (1);
	if (ft_check_forbidden_order(nbr))
		return (1);
	nbr_small = ft_parsing_extract_nbr(nbr);
	nbr_size = ft_strlen(nbr_small);
	if (nbr_size > 11)
		return (1);
	res = 0;
	tmp_nbr = ft_atoi(nbr_small);
	if (nbr[0] == '-')
		tmp_nbr = -1 * tmp_nbr;
	// printf("str %s \n", nbr);
	// printf("small nb %s \n", nbr_small);
	// printf("tmp nb %d \n", tmp_nbr);
	if (tmp_nbr > (INT_MAX / 10) || tmp_nbr < (INT_MIN / 10))
		res = 1;
	if (tmp_nbr == (INT_MAX / 10) && (nbr[ft_strlen(nbr)- 1] - '0') > 7)
		res = 1;
	if (tmp_nbr == (INT_MIN / 10) && (nbr[ft_strlen(nbr) - 1] - '0') > 8)
		res = 1;
	free(nbr_small);
	return (res);
}
