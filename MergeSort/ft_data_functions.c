#include "MergeSort.h"

t_data	ft_data_create(int nb, size_t index)
{
	t_data	new_data;

	new_data.nb = nb;
	new_data.index = index;
	return(new_data);
}
