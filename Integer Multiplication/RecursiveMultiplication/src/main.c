#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_tab
{
	int	*ar;
	int	size;
}	t_tab;

t_tab	ft_struct_to_n_power(t_tab array, int power);
t_tab	ft_struct_resize(t_tab array, int add);
void	print_array(char *c,t_tab nb);
int	ft_find_max_size(t_tab nb1, t_tab nb2);
t_tab	RecIntMult(t_tab nb1, t_tab nb2);


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == ' ');
}

static int	ft_max_min(int sign)
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
	int		bdr;
	char	c;

	num = 0;
	sign = 1;
	c = *nptr;
	while (ft_isspace(*nptr))
		c = *nptr++;
	c = *nptr;
	if (c == '-' || c == '+')
		sign = 1 - (2 * (*nptr++ == '-'));
	while (ft_isdigit(*nptr))
	{
		bdr = INT_MAX / 10;
		if ((num > bdr || num == bdr) && ((*nptr - '0') > 7))
			return (ft_max_min(sign));
		num = 10 * num + (*nptr++ - '0');
	}
	return (num * sign);
}

//Return 1 if both are number and no larger than Int max
//lse return 0
int	ft_verify_number(char *nbr)
{
	int	size_nbr1 = strlen(nbr);
	char *nbr_small;
	int	i = 0;
	int tmp_nbr;

	if (size_nbr1 > 10)
		return (0);
	nbr_small = malloc(sizeof(char) * size_nbr1);
	while (i < size_nbr1)
	{
		nbr_small[i] = nbr[i];
		i++;
	}
	nbr_small[i] = 0;
	tmp_nbr = ft_atoi(nbr_small);
	if (tmp_nbr >  (INT_MAX/10))
		return (0);
	if (tmp_nbr == (INT_MAX/10) && (nbr[size_nbr1 - 1] - 48) > 7)
		return (0);
	return (1);
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


t_tab	ft_char_to_int(char *str_nbr)
{
	t_tab	nbr;
	int	i = 0;

	nbr.size = strlen(str_nbr);
	nbr.ar = (int *)malloc(sizeof(int) * nbr.size);
	while (str_nbr[i])
	{
		nbr.ar[i] = str_nbr[i] - '0';
		i++;
	}
	return (nbr);
}

t_tab	ft_int_to_struct(int nbr)
{
	t_tab	tab;
	int	digit;
	int i = 0;
	
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
	return (tab);
}

void	ft_resize_bef_add(t_tab arr1, t_tab arr2, t_tab nb[2], int *max)
{
	*max =(arr1.size > arr2.size) ? arr1.size : arr2.size;
	if (arr1.size == *max)
	{
		nb[0] = arr1;
		nb[1]  = ft_struct_resize(arr2, *max - arr2.size);
	}
	else
	{
		nb[1]  = arr2;
		nb[0]  = ft_struct_resize(arr1, *max - arr1.size);
	}
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
}

int	ft_size_res(int nb[200], int *i)
{
	int res;

	while (nb[*i] == 0)
	{
		(*i)++;
	}
	if (*i == 200)
		(*i)--;
	res = 200 - *i;
	return(res);
}

t_tab	ft_additioning(t_tab arr1, t_tab arr2)
{
	t_tab	res, nb[2] ;
	int i = 0, j= 0;
	int	 max;
	int	fou[200] = {0};

	ft_resize_bef_add(arr1, arr2, nb, &max);
	ft_add_fix_array(fou, nb, nb[0].size, nb[1].size);
	res.size = ft_size_res(fou, &i);
	res.ar = malloc(sizeof(int) * res.size);
	j = 0;
	while (j < res.size)
	{
		res.ar[j] = fou[i + j];
		j++;
	}
	max = (res.size % 2) ? res.size + 1 : res.size;
	res = ft_struct_resize(res, max - res.size);
	return (res);
}

void	print_array(char *c,t_tab nb)
{
	int  i = 0;

	printf("%s ", c);
	while (i < nb.size)
	{
		printf("%d", nb.ar[i]);
		i++;
	}
	printf("\n");
}

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
}

void	ft_compute_prod(t_tab int_res[4], t_tab nbs[4])
{
	int	i = 0, k = 0, j=0;

	while (i < 4)
	{
		k = (i > 1) ? 1 : 0; 
		j = (i % 2) ? 3 : 2;
		int_res[i] = RecIntMult(nbs[k], nbs[j]);
		i++;
	}
}


int	ft_find_max_size_prod(t_tab int_res[4])
{
	int	max;

	max = (int_res[0].size > int_res[1].size) ? int_res[0].size : int_res[1].size;
	max = (int_res[2].size > max) ? int_res[2].size : max;
	max = (int_res[3].size > max) ? int_res[3].size : max;
	max = (max % 2) ? max + 1 : max;
	return (max);
}

void	ft_all_resize(t_tab int_res[4], int max)
{
	int	i = 0;

	while (i < 4)
	{
		int_res[i] = ft_struct_resize(int_res[i], max - int_res[i].size);
		i++;
	}

}

t_tab	ft_add_all(t_tab int_res[4])
{
	t_tab	result;

	result = ft_additioning(int_res[1], int_res[2]);
	result = ft_additioning(result, int_res[0]);
	result = ft_additioning(result, int_res[3]);
	return (result);
}

t_tab	RecIntMult(t_tab nb1, t_tab nb2)
{
	t_tab	nbs[4], int_res[4], result;
	int   max;

	//This stop our recursion once both numbers are of size = 1
	if (nb1.size == 1 && nb2.size == 1)
		return (ft_int_to_struct(nb1.ar[0] * nb2.ar[0]));
//	Find max size of nb2 and nb1, and we increase its size by 1 (if necessary) to be even
	max = ft_find_max_size(nb1, nb2);
	nb1 = ft_struct_resize(nb1, max - nb1.size);
	nb2 = ft_struct_resize(nb2, max - nb2.size);
	//Split by half each number
	ft_struct_nbrs(nb1, nb2, nbs);
//	Recursion starts here for each halff of each number
	ft_compute_prod(int_res, nbs);
	//ralloc adding ac adding n zeros, same function for (ad+bc)
	int_res[0] = ft_struct_to_n_power(int_res[0], max);
	int_res[1] = ft_struct_to_n_power(int_res[1], max/2);
	int_res[2] = ft_struct_to_n_power(int_res[2], max/2);
	max = ft_find_max_size_prod(int_res);
	//ralloc size of ac aad bc and bc
	ft_all_resize(int_res, max);
	//additioning with grade school additioning
	result = ft_add_all(int_res);
	return (result);
}

int	ft_find_max_size(t_tab nb1, t_tab nb2)
{
	int	max;

	max = (nb1.size > nb2.size) ? nb1.size : nb2.size;
	max = (max % 2) ? max + 1 : max;
	return (max);
}

//1-Verification fo only two Arguments
//2- Transform the numbers with atoi
//3-We apply the algortihm Multiplication
//4-We print both numbers and the result
//5- We veriffy the result is correct
int	main(int argc, char **argv)
{
	int i = 0, max = 0;
	t_tab	nbr1, nbr2, result;

	if  (argc == 3)
	{
		//Transform said numbers to int (atoi)
		nbr1 = ft_char_to_int(argv[1]);
		nbr2 = ft_char_to_int(argv[2]);
		//Find bigges size array and roundoup to the next even number
		max = ft_find_max_size(nbr1, nbr2);
		//Restruct both number to that max size, adding max-nbr*.size 0 to the left
		nbr1 = ft_struct_resize(nbr1, max - nbr1.size);
		nbr2 = ft_struct_resize(nbr2, max - nbr2.size);
		//We calculate ecusrively the number 
		result = RecIntMult(nbr1, nbr2);
		i = 0;
		while (i < result.size)
			printf("%d",result.ar[i++]);
	}
	else
		printf("There are not two numbers\n");
	return (0);
}
