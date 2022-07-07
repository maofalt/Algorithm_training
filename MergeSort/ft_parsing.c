#include "MergeSort.h"

int	ft_parsing(char **raw_nb)
{
	int	i = 0;
	// verify each arg to see if is number
	while (ft_verify_nb(raw_nb[i]))
	{
		i++;
	}
	if (!(ft_verify_nb(raw_nb[i])))
	{
		ft_free_parsed_nodes(node, i);
		return (-1);
	}
	else
		return (1);
	
	// parse at same time  modify the node
	// if  error ret -1 && free the nodes that were parsed
	
}
