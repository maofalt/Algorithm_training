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

	while (nbr)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

int	*ft_char_to_int(char *str_nbr, int *max)
{
	int	*nbr;
	int size_nbr = strlen(str_nbr);
	int	i = 0;
	int	par = 0;
	int	j = 0;

	if (size_nbr % 2)
		par = 1;
	size_nbr += par;
	if ((int)size_nbr > *max)
		*max = size_nbr;
	nbr = (int *)malloc(sizeof(int) * (*max));
	while (j < (*max - (size_nbr  - par)))
	{
		nbr[j++] = 0;
	}
	while (str_nbr[i])
	{
		nbr[i + j] = str_nbr[i] - '0';
		i++;
	}
	size_nbr += par;
	return (nbr);
}

/*int	*RecIntMult(int *nbr1, int size_nbr, int *nbr2)*/
/*{*/
	/*if (size\)*/
/*}*/

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
	static int max = 0;

	if  (argc == 3)
	{
		//Transform said numbers to int (atoi)
		if (strlen(argv[1]) > strlen(argv[2]))
		{
			nbr1 = ft_char_to_int(argv[1], &max);
			nbr2 = ft_char_to_int(argv[2], &max);
		}
		else
		{
			nbr1 = ft_char_to_int(argv[2], &max);
			nbr2 = ft_char_to_int(argv[1], &max);
		}
		printf("size of array is %d\n",  max);
		printf("First number is ");
		while (i < (int)max)
			printf("%d", nbr1[i++]);
		printf("\nSecond number is ");
		i = 0;
		while (i < (int)max)
			printf("%d", nbr2[i++]);
		free(nbr1);
		free(nbr2);
		//Algorithm Multiplication
		/*result = RecIntMult(nbr1, nbr2);*/
		/*printf("\t%d\n", nbr1);*/
		/*printf("x\t%d\n",nbr2);*/
		/*printf("____________________\n");*/
		/*printf("\t%d",result);*/
		/*if (nbr1*nbr2 == result)*/
			/*printf("\nRight Result\n");*/
		/*else*/
			/*printf("\ngo review your code\n Result  must be %d\n ", nbr1*nbr2);*/
		/*return (1);*/
	}
	else
		printf("There are not two numbers\n");
	return (0);
}
