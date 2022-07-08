/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/07/08 17:12:11 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeSort.h"

int	ft_parsing(char **raw_nb)
{
	int	i = 0;
	// verify each arg to see if is number
	while (ft_verify_number(raw_nb[i]))
	{
		i++;
	}
	if (!(ft_verify_number(raw_nb[i])))
	{
		//ft_free_parsed_nodes(node, i);
		return (-1);
	}
	else
		return (1);
	
	// parse at same time  modify the node
	// if  error ret -1 && free the nodes that were parsed
	
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
		num += *nptr++ - '0';
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

//Return 1 if both are number and no larger than Int max
//else return 0
//forbidden strlen here correct!!
int	ft_verify_number(char *nbr)
{
	const int	nbr_size = strlen(nbr);
	
	char		*nbr_small;
	int			i;
	int 		tmp_nbr;

	if (nbr_size > 10)
		return (0);
	if (ft_parsing_allowed_chars(nbr))
		return (0);
	nbr_small = malloc(sizeof(char) * nbr_size);
	i = 0;
	while (i < nbr_size)
	{
		nbr_small[i] = nbr[i];
		i++;
	}
	nbr_small[i] = 0;
	tmp_nbr = ft_atoi(nbr_small);
	if (tmp_nbr >  (INT_MAX/10))
		return (0);
	if (tmp_nbr == (INT_MAX/10) && (nbr[nbr_size - 1] - '0') > 7)
		return (0);
	return (1);
}

// t_tab	ft_char_to_int(char *str_nbr)
// {
// 	t_tab	nbr;
// 	int	i = 0;

// 	nbr.size = strlen(str_nbr);
// 	nbr.ar = (int *)malloc(sizeof(int) * nbr.size);
// 	while (str_nbr[i])
// 	{
// 		nbr.ar[i] = str_nbr[i] - '0';
// 		i++;
// 	}
// 	return (nbr);
// }

int	main()
{

	char 	string[]="-01234567899874-9a81";

	if(ft_parsing_allowed_chars(string)) 
		printf("Forbidden character ahead! ABORT!\n");
	else 
		printf("Everything is fine\n");
}