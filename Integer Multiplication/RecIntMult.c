#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int	*ft_char_to_int(char *str_nbr, int *size_nbr)
{
	int	*nbr;
	int	i = 0;

	*size_nbr = strlen(str_nbr);
	nbr = (int *)malloc(sizeof(int) * *size_nbr);
	while (str_nbr[i])
	{
		nbr[i] = str_nbr[i] - '0';
		i++;
	}
	return (nbr);
}

int	*ft_int_to_array(int nbr)
{
	int	*array;
	int	digit;
	int i = 0;
	int	size = ft_size_nbr(nbr);

	printf("\n --------------------\nft_int_to_array\n");
	printf("nbr %d\n", nbr);
	printf("size of nbr %d \n", size);
	array =  malloc(sizeof(int) * size);
	while (nbr)
	{
		digit = nbr % 10;
		array[size - 1 - i] = digit;
		nbr /= 10;
		i++;
	}
	return (array);
}

int	*ft_array_to_array(int *nbr, int size, int start)
{
	int	*array;
	int	i = 0;

	array = malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i] = nbr[start + i];
		i++;
	}
	return (array);
}

int	*ft_array_to_n_power(int *array, int arr_siz, int power)
{
	int	*new_array;
	int	i, j ;

	//printf("array size %d, power %d \n", arr_siz, power);
	new_array = malloc(sizeof(int) * (arr_siz + power));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < power)
		new_array[i++] = 0;
	j = 0;
	while (j < arr_siz)
	{
		//printf("i = %d, j = %d\n", i, j);
		new_array[i + j] = array[j];
		j++;
	}
//	free(array);
	return (new_array);
}

int	*ft_additioning(int	*arr1, int siz1, int *arr2, int siz2)
{
	int	*result;
	int	size_res;
	int ret = 0;
	int i = 0;

	size_res = ft_size_result(arr1[0], siz1 - 1, arr2[0], siz2 - 1);
	printf("ft_additioning: \n size res=%d\n",size_res);
	result = malloc(sizeof(int) * size_res);
	if(!result)
		return (NULL);
	while (i < size_res)
	{
		result[size_res - i] = (arr1[siz1 - 1 - i] + arr2[siz2 - 1 - i] + ret) % 10;
		ret =  (arr1[siz1 - 1 - i] + arr2[siz2 - 1- i] + ret) / 10;
		i++;
	}
	return (result);
}

int	*RecIntMult(int *nbr1, int s_nb1, int *nbr2, int s_nb2)
{
	int	*a, *b, *c, *d;
	int	*ac, *ad, *bc, *bd;
	int	*result;
	int new_size, new_size2;

	if (s_nb1 == 1 && s_nb2 == 1)
		return (ft_int_to_array(nbr1[0] * nbr2[0]));
	a = ft_array_to_array(nbr1, s_nb1/2, 0);
	printf("a %d \n", a[0]);
	b = ft_array_to_array(nbr1, s_nb1/2, s_nb1/2);
	printf("b %d \n", b[0]);
	c = ft_array_to_array(nbr2, s_nb2/2, 0);
	printf("c %d \n", c[0]);
	d = ft_array_to_array(nbr2, s_nb2/2, s_nb2/2);
	printf("d %d \n", d[0]);
	ac = RecIntMult(a, s_nb1/2, c,s_nb2/2);
	printf("ac %d \n", ac[0]);
	ad = RecIntMult(a, s_nb1/2, d, s_nb2/2);
	printf("ad %d \n", ad[0]);
	bc = RecIntMult(b, s_nb1/2, c, s_nb2/2);
	printf("bc %d \n", bc[0]);
	bd = RecIntMult(b, s_nb1/2, d, s_nb2/2);
	printf("bd %d \n", bd[0]);
	//ralloc adding ac adding n zeros, same function for (ad+bc)
	ac = ft_array_to_n_power(ac, s_nb1/2, s_nb1);
	ad = ft_array_to_n_power(ac, s_nb1/2, s_nb1/2);
	bc = ft_array_to_n_power(ac, s_nb1/2, s_nb1/2);
	//additioning with grade school additioning
	result = ft_additioning(ad, s_nb1, bc, s_nb1);
	new_size = ft_size_result(ad[0], s_nb1 - 1, bc[0], s_nb1 - 1);
	result = ft_additioning(result, new_size, ac, (3 * s_nb1)/2);
	new_size2 = ft_size_result(result[0], new_size - 1, ac[0],((3 * s_nb1)/2) - 1);
	result = ft_additioning(result, new_size2, bd, s_nb1/2);
	new_size = ft_size_result(result[0], new_size2 - 1, bd[0], (s_nb1/2) - 1);
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
	int i = 0;
	int	*nbr1;
	int *nbr2;
	int size_nbr1, size_nbr2;
	int	*result;
	int size_result;

	if  (argc == 3)
	{
		//Transform said numbers to int (atoi)
		nbr1 = ft_char_to_int(argv[1], &size_nbr1);
		nbr2 = ft_char_to_int(argv[2], &size_nbr2);
		printf("size of 1st array is %d\n",  size_nbr1);
		printf("First number is ");
		while (i < size_nbr1)
			printf("%d", nbr1[i++]);
		printf("size of array 2nd is %d\n",  size_nbr2);
		printf("\nSecond number is \n");
		i = 0;
		while (i < size_nbr2)
		{
			printf("%d\n", nbr2[i]);
			i++;
		}
		//free(nbr1);
		//free(nbr2);
		//Algorithm Multiplication
		printf("Start of recursion \n ==================================\n");
		result = RecIntMult(nbr1,size_nbr1, nbr2, size_nbr2);
		printf("\n=========================================\n Result is ready\n ");
		size_result = ft_size_result(nbr1[0], size_nbr1,  nbr2[0], size_nbr2);
		i = 0;
		while (i < size_result)
			printf("%d",result[i++]);
	}
	else
		printf("There are not two numbers\n");
	return (0);
}
