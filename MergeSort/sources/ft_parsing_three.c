/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:54 by motero            #+#    #+#             */
/*   Updated: 2022/09/26 03:12:55 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

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

int	ft_tests_size(char *nbr, int tmp_nbr)
{
	static int	pos_last;

	pos_last = ft_strlen(nbr) - 1;
	if (nbr[0] == '-')
		tmp_nbr = -1 * tmp_nbr;
	if (tmp_nbr > (INT_MAX / 10) || tmp_nbr < (INT_MIN / 10))
		return (1);
	if (tmp_nbr == (INT_MAX / 10) && (nbr[pos_last] - '0') > 7)
		return (1);
	if (tmp_nbr == (INT_MIN / 10) && (nbr[pos_last] - '0') > 8)
		return (1);
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

	if (ft_parsing_allowed_chars(nbr) || ft_count_minus(nbr))
		return (1);
	if (ft_count_plus(nbr) || ft_check_forbidden_order(nbr))
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
	tmp_nbr = ft_atoi(nbr_small);
	res = ft_tests_size(nbr, tmp_nbr);
	free(nbr_small);
	return (res);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
