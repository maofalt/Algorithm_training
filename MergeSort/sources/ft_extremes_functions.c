/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extremes_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:17:45 by motero            #+#    #+#             */
/*   Updated: 2022/08/03 17:18:43 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_xtrm	ft_extremes_initializes(void)
{
	t_xtrm	xtrm;

	xtrm.max.i = 0;
	xtrm.max.nb = 0;
	xtrm.min.i = 0;
	xtrm.max.nb = 0;
	return (xtrm);
}

void	ft_extremes_parsing(t_list *list, t_data data)
{
	if (data.index == 0)
	{
		list->xtrm.min.nb = data.nb;
		list->xtrm.min.i = data.index;
		list->xtrm.max.nb = data.nb;
		list->xtrm.max.i = data.index;
	}
	else
	{
		if (data.nb < list->xtrm.min.nb)
		{
			list->xtrm.min.nb = data.nb;
			list->xtrm.min.i = data.index;
		}
		if (data.nb > list->xtrm.max.nb)
		{
			list->xtrm.max.nb = data.nb;
			list->xtrm.max.i = data.index;
		}
	}
}
