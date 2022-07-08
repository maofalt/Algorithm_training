/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/07/08 18:49:05 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"

t_list	ft_parsing(char **raw_nb, int nb_arg)
{
	int	i;
	t_list	list_a;
	t_data	data;

	i = 1;
	list_a = ft_list_create(NULL, NULL, 0);
	while (!ft_verify_number(raw_nb[i]))
	{
		data = ft_data_create(ft_atoi(raw_nb[i]), i);
		ft_node_insert_end(&list_a, data);
		if (i == nb_arg - 1)
			break;
		i++;
	}
	if ((ft_verify_number(raw_nb[i])))
	{
		ft_list_free(&list_a);
		return (list_a);
	}
	else
		return (list_a);
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
	int 		i;
	int			j;
	int			exist;

	i = 0;
	size  = strlen(str);
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
	return(0);
}

char	*ft_parsing_extract_nbr(char *nbr)
{
	const int	nbr_size = strlen(nbr);
	char		*nbr_small;
	int			i;

	nbr_small = malloc(sizeof(char) * nbr_size);
	if (!nbr_small)
		return (NULL);
	i = 0;
	while (i < (nbr_size - 1))
	{
		nbr_small[i] = nbr[i];
		i++;
	}
	nbr_small[i] = 0;
	return (nbr_small);
}

//Return 1 if both are number and no larger than Int max
//else return 0
//forbidden strlen here correct!!
int	ft_verify_number(char *nbr)
{
	const int	nbr_size = strlen(nbr);
	char		*nbr_small;
	int 		tmp_nbr;
	int			res;

	if (nbr_size > 11)
		return (1);
	if (ft_parsing_allowed_chars(nbr))
		return (1);
	nbr_small = ft_parsing_extract_nbr(nbr);
	res = 0;
	tmp_nbr = ft_atoi(nbr_small);
	if (tmp_nbr >  (INT_MAX/10) || tmp_nbr < (INT_MIN/10))
		res = 1;
	if (tmp_nbr == (INT_MAX/10) && (nbr[nbr_size - 1] - '0') > 7)
		res = 1;
	if (tmp_nbr == (INT_MIN/10) && (nbr[nbr_size - 1] - '0') > 8)
		res = 1;
	free(nbr_small);
	return (res);
}