/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:58:05 by motero            #+#    #+#             */
/*   Updated: 2022/08/31 13:49:03 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PushSwap.h"

t_data	ft_data_create(int nb, size_t index)
{
	t_data	new_data;

	new_data.nb = nb;
	new_data.index = index - 1;
	new_data.final_index = 0;
	return (new_data);
}
