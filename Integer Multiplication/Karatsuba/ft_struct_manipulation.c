#include "Karatsuba.h"

void	ft_struct_nbrs(t_tab nb1, t_tab nb2, t_tab nbs[4])
{
	int	i, middle;
	t_tab tmp = nb1;

	i = 0;
	while (i < 4)
	{
		if (i > 1)
			tmp = nb2;
		middle = i % 2;
		nbs[i] = ft_struct_struct(tmp, middle);
		i++;
	}
	free(nb1.ar);
	free(nb2.ar);
}

t_tab	ft_int_to_struct(t_tab nb1, t_tab nb2)
{
	t_tab	tab;
	int	digit, nbr;
	int i = 0;
	
	nbr = nb1.ar[0] * nb2.ar[0];
	tab.size = ft_size_nbr(nbr);
	tab.ar =  malloc(sizeof(int) * 2);
	if (tab.size != 2)
	{
		tab.ar[0] = 0;
	}
	while (nbr)
	{
		digit = nbr % 10;
		tab.ar[tab.size - 1 - i] = digit;
		nbr /= 10;
		i++;
	}
	return (tab);
}

t_tab	ft_struct_struct(t_tab nb, int start)
{
	t_tab	tab;
	int	i = 0;

	tab.size = nb.size / 2;
	tab.ar = malloc(sizeof(int) * tab.size);
	while (i < tab.size)
	{
		tab.ar[i] = nb.ar[(tab.size * start) + i];
		i++;
	}
	return (tab);
}

t_tab	ft_struct_resize(t_tab array, int add)
{
	t_tab	tab;
	int	i, j;

	tab.size = array.size + add;
	tab.ar = malloc(sizeof(int) * (array.size + add));
	i = 0;
	while (i < add)
		tab.ar[i++] = 0;
	j = 0;
	while (j < array.size)
	{
		tab.ar[i + j] = array.ar[j];
		j++;
	}
	return (tab);
}

t_tab	ft_struct_to_n_power(t_tab array, int power)
{
	t_tab	tab;
	int	i, j;

	tab.size = array.size + power;
	tab.ar = malloc(sizeof(int) * (array.size + power));
	j = 0;
	while (j < array.size)
	{
		tab.ar[j] = array.ar[j];
		j++;
	}
	i = 0;
	while (i < power)
		tab.ar[j + i++] = 0;
	free(array.ar);
	return (tab);
}

void	ft_resize_bef_add(t_tab arr1, t_tab arr2, t_tab nb[2], int *max)
{
	t_tab tmp1, tmp2;
	
	*max =(arr1.size > arr2.size) ? arr1.size : arr2.size;
	tmp1 = ft_struct_resize(arr1, *max - arr1.size);
	//free(arr1.ar);
	//arr1 = tmp1;
	tmp2  = ft_struct_resize(arr2, *max - arr2.size);
	//free(arr2.ar);
	//arr2 = tmp2;
	if (arr1.size == *max)
	{
		nb[0] = tmp1;
		nb[1] = tmp2;
	}
	else
	{
		nb[1]  = tmp2;
		nb[0]  = tmp1;
	}
}
