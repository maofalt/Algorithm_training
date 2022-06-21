#include "Karatsuba.h"

t_tab	ft_substracting(t_tab big, t_tab small)
{
	t_tab res;
	int ret= 0 , i = 0, raw_res = 0;

	res.ar = malloc(sizeof(int) * big.size);
	res.size = big.size;
	if (!res.ar)
		res.ar = NULL;
	while (i < big.size)
	{
		raw_res =  (big.ar[res.size - 1 - i] - small.ar[res.size - 1 - i] - ret);
		//printf("|%d| \t %d\n-\t%d\n-\t%d\n---------------\n%d\n\n",i , big.ar[res.size - 1 - i], small.ar[res.size - 1 - i],ret, raw_res);
		ret = (raw_res < 0) ? 1 : 0;
		res.ar[res.size - 1 - i] = (raw_res < 0) ? (10 +raw_res)%10 : (raw_res)%10 ;
		i++;
	}
	res.ar[res.size - 1 -i] += ret;
	return (res);
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
	//max = (res.size % 2) ? res.size + 1 : res.size;
	//res = ft_struct_resize(res, max - res.size);
	return (res);
}


t_tab	RecIntMult(t_tab nb1, t_tab nb2)
{
	t_tab	nbs[4], int_res[3], sum[2], result;
	int   max;
	static int counter;

	printf("iteration|%d|\n", counter);
	print_array("nb1", nb1);
	print_array("nb2", nb2);
	counter++;
	//This stop our recursion once both numbers are of size = 1
	if (nb1.size == 1 && nb2.size == 1)
		return (ft_int_to_struct(nb1.ar[0] * nb2.ar[0]));
//	Find max size of nb2 and nb1, and we increase its size by 1 (if necessary) to be even
	max = ft_find_max_size(nb1, nb2);
	nb1 = ft_struct_resize(nb1, max - nb1.size);
	nb2 = ft_struct_resize(nb2, max - nb2.size);
	//Split by half each number
	ft_struct_nbrs(nb1, nb2, nbs);
//	Compute of p =a+b & q =c+d and resize result
//	Recursion starts here for ac bd and pq|| nbs[0.1] nbs[2.3] sum[0.1]
	ft_compute_prod(int_res, nbs);
//	printf("Trying to sum\n");
	sum[0] = ft_additioning(nbs[0], nbs[1]);
	sum[1] = ft_additioning(nbs[2], nbs[3]);
	print_array("p",sum[0]);
	print_array("q", sum[1]);
	int_res[2] = RecIntMult(sum[0], sum[1]);
	print_array("pq", int_res[2]);
//	Compute adbc = pq -ac-bd : first k = sum(ac +bd), then substract pq - k;
	int_res[2] = ft_compute_substraction(int_res);
	//ralloc adding ac adding n zeros, same function for (adbc)
	int_res[0] = ft_struct_to_n_power(int_res[0], max);
	int_res[2] = ft_struct_to_n_power(int_res[2], max/2);
	max = ft_find_max_size_prod(int_res);
	//ralloc size of ac aad bc and bc
	ft_all_resize(int_res, max);
	//additioning with grade school additioning
	result = ft_add_all(int_res);
	print_array("result", result);
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

/*int	main(int argc, char **argv)*/
/*{*/
	/*int i = 0, max = 0;*/
	/*t_tab	nbr1, nbr2, result;*/

	/*if  (argc == 3)*/
	/*{*/
		/*//Transform said numbers to int (atoi)*/
		/*nbr1 = ft_char_to_int(argv[1]);*/
		/*nbr2 = ft_char_to_int(argv[2]);*/
		/*//Find bigges size array and roundoup to the next even number*/
		/*max = ft_find_max_size(nbr1, nbr2);*/
		/*//Restruct both number to that max size, adding max-nbr*.size 0 to the left*/
		/*nbr1 = ft_struct_resize(nbr1, max - nbr1.size);*/
		/*nbr2 = ft_struct_resize(nbr2, max - nbr2.size);*/
		/*//We calculate ecusrively the number*/
		/*result = ft_substracting(nbr1, nbr2);*/
		/*i = 0;*/
		/*while (i < result.size)*/
			/*printf("%d",result.ar[i++]);*/
	/*}*/
	/*else*/
		/*printf("There are not two numbers\n");*/
	/*return (0);*/
/*}*/
