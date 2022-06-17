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

//Total numbers of operations k*n^2
//2n operations per row * n of rows
//Multiplication is done as following
//	nbr1 |1 2 3 4 5 6
//x	nbr2 |0 0 0 2 5 6
//-------------------
//line 1 |* * * * * *
//line 2 |* * * * * 0
//line 3 |* * * * 0 0
//etc... 
//1- Extract unity of nbr 2 with modulo
//2- Sustract unity of nbr 2 with /10 (round down)
//3- Same 2 steps for nbr 1
//4- Multiply unity from nbr 1and nbr 2
//5- Increase it by  then tenth power and increase the 10th power each passing loop
//6- We do the same for each line, multiplying each line resulting by 10th power
int	grade_school_algo(int nbr1, int nbr2)
{
	int	multiplier;
	int rest;
	int	tmp = 0;
	int	result = 0;
	int power = 0;
	int	power2 = 0;
	int	tmp_nbr1 = nbr1;

	while (nbr2)
	{
		multiplier = nbr2  % 10;
		nbr2 /= 10;
		power = 0;
		tmp = 0;
		while (tmp_nbr1)
		{
			rest = tmp_nbr1 % 10;
			tmp_nbr1 /= 10;
			tmp += (rest * multiplier) * pow(10, power++);
		}
		result += (tmp * pow(10, power2++));
		tmp_nbr1 = nbr1;
	}
	return (result);
}

//1-Verification fo only two Arguments
//2- Transform the numbers with atoi
//3-We apply the algortihm Multiplication
//4-We print both numbers and the result
//5- We veriffy the result is correct
int	main(int argc, char **argv)
{
	int i = 1;
	int	nbr1;
	int nbr2;
	int	result = 0;

	if  (argc == 3)
	{
		while (argv[i])
		{		
		//Verify arguments are numbers and not larger than INt_Max
			if(!(ft_verify_number(argv[i++])))
			{
				printf("Not a number or too big\n");
				return (-1);
			}
		}
		//Transform said numbers to int (atoi)
		nbr1 = ft_atoi(argv[1]);
		nbr2 = ft_atoi(argv[2]);
		//Algorithm Multiplication
		if (nbr1 >= nbr2)
			result = grade_school_algo(nbr1, nbr2);
		else
			result = grade_school_algo(nbr2, nbr1);
		printf("\t%d\n", nbr1);
		printf("x\t%d\n",nbr2);
		printf("____________________\n");
		printf("\t%d",result);
		if (nbr1*nbr2 == result)
			printf("\nRight Result\n");
		else
			printf("\ngo review your code\n Result  must be %d\n ", nbr1*nbr2);
		return (1);
	}
	else
		printf("There are not two numbers\n");
	return (0);
}
