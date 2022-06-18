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

int	ft_size_result(int nb1, int pw1, int nb2, int pw2)
{
	int	size;

	printf("----------------\nft_size_result :\nnb1 =%d\npw1=%d\nnb2=%d\npw2=%d\n------------------\n",nb1,pw1,nb2,pw2);
	if(nb1 == 0 || nb2 == 0)
		return (1);
	size = (int)(log10(nb1 * pow(10, pw1 - 1)) + log10(nb2 * pow(10, pw2 - 1)) + 1);
	printf("size %d\n----------------------------\n", size);
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

	/*printf("\n --------------------\nft_int_to_struct\n");*/
	/*printf("nbr %d\n", nbr);*/
	/*printf("size of nbr %d \n", tab.size);*/
	tab.ar =  malloc(sizeof(int) * tab.size);
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
	//t_tab	resize;
	int	i = 0;

	//printf("\n-------\nft_struct_struct\n");
	//printf("size of nb to split %d\n",nb.size);
	//if (nb.size % 2)
	//	resize = ft_struct_resize(nb, 1);
	//else
	//	resize = nb;
	//print_array("resize:", resize);
	//printf("\nsize of resize %d\n",resize.size);
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

	//printf("array size %d, power %d \n", arr_siz, power);
	tab.size = array.size + add;
	tab.ar = malloc(sizeof(int) * (array.size + add));
	i = 0;
	while (i < add)
		tab.ar[i++] = 0;
	j = 0;
	while (j < array.size)
	{
		//printf("i = %d, j = %d\n", i, j);
		tab.ar[i + j] = array.ar[j];
		j++;
	}
//	free(array);
	return (tab);
}

t_tab	ft_struct_to_n_power(t_tab array, int power)
{
	t_tab	tab;
	int	i, j;

	//printf("array size %d, power %d \n", arr_siz, power);
	tab.size = array.size + power;
	tab.ar = malloc(sizeof(int) * (array.size + power));
	j = 0;
	while (j < array.size)
	{
		//printf("i = %d, j = %d\n", i, j);
		tab.ar[j] = array.ar[j];
		j++;
	}
	i = 0;
	while (i < power)
		tab.ar[j + i++] = 0;
//	free(array);
	return (tab);
}

t_tab	ft_additioning(t_tab arr1, t_tab arr2)
{
	t_tab	res, a, b;
	int i = 0, j=0,ret = 0;
	int	 max;
	int	fou[200] = {0};

	max =(arr1.size > arr2.size) ? arr1.size : arr2.size;
	if (arr1.size == max)
	{
		a = arr1;
		b = ft_struct_resize(arr2, max - arr2.size);
	}
	else
	{
		b = arr2;
		a = ft_struct_resize(arr1, max - arr1.size);
	}
	/*while (i < max )*/
	/*{*/
		/*tmp += (int)((a.ar[a.size - 1 - i] * pow(10, i)) + (b.ar[b.size - 1 - i] * pow(10 , i)));*/
		/*i++;*/
	/*}*/
//	printf("tmp %d\n",tmp);
	//res.size = 200;
//	printf("ft_additioning: \n size res=%d\n", res.size);
	//res.ar = malloc(sizeof(int) * 200);
	i = 0;
	while (a.size - i >= 1)
	{
		fou[199 - i] = (ret + (int)(a.ar[a.size - 1 - i]  + b.ar[b.size - 1 - i] )) % 10;
		printf("+%d\n",fou[199 - i]);
		ret = (int)(a.ar[a.size - 1 - i] + b.ar[b.size - 1 - i] ) / 10;
		i++;
	}
	i = 0;
	while (fou[i] == 0)
	{
		i++;
	}
	printf("**fou[i]=%d***size fou %d ****\n",fou[i], i);
	res.size = 200 - i;
	res.ar = malloc(sizeof(int) * res.size);
	while (j < res.size)
	{
		res.ar[j] = fou[i + j];
		j++;
	}
	print_array("res", res);
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

t_tab	RecIntMult(t_tab nb1, t_tab nb2)
{
	t_tab	a, b, c, d;
	t_tab	ac, ad, bc, bd;
	t_tab	result;
	int  max_size = nb2.size;
	static int coucou ;

	coucou++;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n Recursion number %d \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", coucou);
	print_array("Nbr1=", nb1);
	print_array("Nbr2=", nb2);
	if (nb1.size == 1 && nb2.size == 1)
		return (ft_int_to_struct(nb1.ar[0] * nb2.ar[0]));
	if (nb1.size > nb2.size)
		max_size = nb1.size;
	a = ft_struct_struct(nb1, 0);
	print_array("a", a);
	b = ft_struct_struct(nb1, 1);
	print_array("b", b);
	c = ft_struct_struct(nb2, 0);
	print_array("c", c);
	d = ft_struct_struct(nb2, 1);
	print_array("d", d);
//	Recursion starts here
	printf("=========ac=======\n");
	ac = RecIntMult(a, c);
	print_array("=", ac);
	printf("=========ad=====\n");
	ad = RecIntMult(a, d);
	print_array("=", ad);
	printf("=========bc======\n");
	bc = RecIntMult(b, c);
	print_array("=", bc);
	printf("=========bd=======\n");
	bd = RecIntMult(b, d);
	print_array("=", bd);
	//ralloc adding ac adding n zeros, same function for (ad+bc)
	ac = ft_struct_to_n_power(ac, max_size);
	print_array("ac", ac);
	ad = ft_struct_to_n_power(ad, max_size/2);
	print_array("ad", ad);
	bc = ft_struct_to_n_power(bc, max_size/2);
	print_array("bc", bc);
	//additioning with grade school additioning
	result = ft_additioning(ad, bc);
	print_array("(ad+bc*power", result);
	result = ft_additioning(result, ac);
	print_array("k +ac", result);
	result = ft_additioning(result, bd);
	print_array("total",result);
	//return result array
	return (result);

}

//1-Verification fo only two Arguments
//2- Transform the numbers with atoi
//3-We apply the algortihm Multiplication
//4-We print both numbers and the result
//5- We veriffy the result is correct
int	main(int argc, char **argv)
{
	int i = 0, max = 0;
	t_tab	nbr1;
	t_tab	nbr2;
	t_tab	result;

	if  (argc == 3)
	{
		//Transform said numbers to int (atoi)
		nbr1 = ft_char_to_int(argv[1]);
		nbr2 = ft_char_to_int(argv[2]);
		max = (nbr1.size > nbr2.size) ? nbr1.size : nbr2.size;
		max = (max % 2) ? max + 1 : max;
		nbr1 = ft_struct_resize(nbr1, max - nbr1.size);
		nbr2 = ft_struct_resize(nbr2, max - nbr2.size);
		printf("size of 1st array is %d\n", nbr1.size);
		printf("First number is ");
		while (i < nbr1.size)
			printf("%d", nbr1.ar[i++]);
		printf("\nsize of array 2nd is %d",  nbr2.size);
		printf("\nSecond number is \n");
		i = 0;
		while (i < nbr2.size)
		{
			printf("%d", nbr2.ar[i]);
			i++;
		}
		//free(nbr1);
		//free(nbr2);
		//Algorithm Multiplication
		printf("\nStart of recursion \n ==================================\n");
		result = RecIntMult(nbr1, nbr2);
		printf("\n=========================================\n Result is ready\n ");
		i = 0;
		printf("\nSize of result \n%d\n", result.size);
		while (i < result.size)
			printf("%d",result.ar[i++]);
	}
	else
		printf("There are not two numbers\n");
	return (0);
}
