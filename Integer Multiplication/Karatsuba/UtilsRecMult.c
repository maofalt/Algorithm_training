#include "Karatsuba.h"

void	ft_compute_prod(t_tab int_res[3], t_tab nbs[4])
{
	int	i = 0;

	while (i < 2)
	{
		int_res[i] = RecIntMult(nbs[i], nbs[i + 2]);
		i++;
	}
}


int	ft_find_max_size_prod(t_tab int_res[3])
{
	int	max;

	max = (int_res[0].size > int_res[1].size) ? int_res[0].size : int_res[1].size;
	max = (int_res[2].size > max) ? int_res[2].size : max;
	max = (max % 2) ? max + 1 : max;
	return (max);
}

void	ft_all_resize(t_tab int_res[3], int max)
{
	int	i = 0;
	t_tab	tmp[3];

	while (i < 3)
	{
		tmp[i] = ft_struct_resize(int_res[i], max - int_res[i].size);
		free(int_res[i].ar);
		int_res[i] = tmp[i];
		i++;
	}

}

t_tab	ft_add_all(t_tab int_res[3])
{
	t_tab	result, result2;

	result = ft_additioning(int_res[0], int_res[1]);
	result2 = ft_additioning(result, int_res[2]);
	free(int_res[0].ar);
	free(int_res[1].ar);
	free(int_res[2].ar);
	free(result.ar);
	return (result2);
}

int	ft_find_max_size(t_tab nb1, t_tab nb2)
{
	int	max;

	if (nb1.size == 1 && nb2.size == 1)
		return (1);
	max = (nb1.size > nb2.size) ? nb1.size : nb2.size;
	max = (max % 2) ? max + 1 : max;
	return (max);
}

void	ft_add_fix_array(int big[200], t_tab nb[2], int len1, int len2)
{
	int	i, ret=0, sum;

	i = 0;
	while (len1 - i >= 1)
	{
		sum = ret + (int)(nb[0].ar[len1 - 1 - i]  + nb[1].ar[len2 - 1 - i] );
		big[199 - i] = sum % 10;
		ret = sum / 10;
		i++;
	}
	big[199 - i] += ret;
	free(nb[0].ar);
	free(nb[1].ar);
}

int	ft_size_res(int nb[200], int *i)
{
	int res, j = 0;

	while (nb[j] == 0 && j < 200)
	{
		(j)++;
		if (j == 200)
			break;
	}
	//printf("j=%d\n", j);
	if (j == 200)
		(j)--;
	res = 200 - j;
	*i = j;
	/*while (nb[*i] == 0)*/
	/*{*/
		/*(*i)++;*/
	/*}*/
	/*if (*i == 200)*/
		/*(*i)--;*/
	/*res = 200 - *i;*/
	return(res);
}

int	ft_size_nbr(int nbr)
{
	int size = 0;

	if (nbr == 0)
		return (1);
	while (nbr)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

t_tab	ft_compute_substraction(t_tab res[3])
{
	t_tab	adbc, sum, tmp;
	int		max;
	
	sum = ft_additioning(res[0], res[1]);
	max = ft_find_max_size(sum, res[2]);
	tmp = ft_struct_resize(sum, max - sum.size);
	free(sum.ar);
	sum = tmp;
	tmp = ft_struct_resize(res[2], max - res[2].size);
	free(res[2].ar);
	res[2] = tmp;
	adbc = ft_substracting(res[2], sum);
	free(sum.ar);
	return (adbc);
}
