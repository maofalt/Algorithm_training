/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 02:52:30 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

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
