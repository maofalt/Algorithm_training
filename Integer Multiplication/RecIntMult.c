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

int	*ft_char_to_int(char *str_nbr)
{
	int	*nbr;
	int	size_nbr = strlen(str_nbr);

	if (size_nbr % 2)
		size_nbr += 1;
	nbr = (int *)malloc(sizeof(int) * size_nbr);
	while (str_nbr)
	{
		*nbr = *str_nbr - '0';
		(*str_nbr)++;
		(*nbr)++;
	}
	if (str_nbr == 0)
		*nbr = 0;
	return (nbr);
}
//1-Verification fo only two Arguments
//2- Transform the numbers with atoi
//3-We apply the algortihm Multiplication
//4-We print both numbers and the result
//5- We veriffy the result is correct
int	main(int argc, char **argv)
{
	//int i = 1;
	int	*nbr1;
	int	size_nbr1;
	int	size_nbr2;
	int *nbr2;
	//int	result = 0;

	if  (argc == 3)
	{
		//Transform said numbers to int (atoi)
		nbr1 = ft_char_to_int(argv[1]);
		nbr2 = ft_char_to_int(argv[2]);
		size_nbr1 = sizeof(nbr1) / sizeof(nbr1[0]);
		printf("size of nbr1 is %d\n",size_nbr1);
		size_nbr2 = sizeof(nbr2)/sizeof(nbr2[0]);
		printf("size of nbr2 is %d\n",size_nbr2);
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
