/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extremes_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:17:45 by motero            #+#    #+#             */
/*   Updated: 2022/08/02 19:42:56 by motero           ###   ########.fr       */
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
	if (data.nb < list->xtrm.min.nb)
	{
		list->xtrm.min.nb = data.nb;
		list->xtrm.min.i = data.index;
	}
	else
		list->xtrm.min.i = (list->xtrm.min.i + 1) % list->size;
	if (data.nb > list->xtrm.max.nb)
	{
		list->xtrm.max.nb = data.nb;
		list->xtrm.max.i = data.index;
	}
	else
		list->xtrm.max.i = (list->xtrm.max.i + 1) % list->size;
}
