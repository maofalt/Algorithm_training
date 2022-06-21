#ifndef KARATSUBA_H
# define KARATSUBA_H

# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_tab
{
	int	*ar;
	int	size;
}	t_tab;

//Main Functions :: main.c

t_tab	ft_additioning(t_tab arr1, t_tab arr2);
t_tab	RecIntMult(t_tab nb1, t_tab nb2);
t_tab	ft_substracting(t_tab big, t_tab small);

//.Function to manipulate the structure created :: ft_struct_manipulation
void	ft_struct_nbrs(t_tab nb1, t_tab nb2, t_tab nbs[4]);
t_tab	ft_int_to_struct(int nbr);
t_tab	ft_struct_struct(t_tab nb, int start);
t_tab	ft_struct_resize(t_tab array, int add);
t_tab	ft_struct_to_n_power(t_tab array, int power);
void	ft_resize_bef_add(t_tab arr1, t_tab arr2, t_tab nb[2], int *max);

//functions that help with parsing and display parsing_functions.c
int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_max_min(int sign);
int	ft_atoi(const char *nptr);
int	ft_verify_number(char *nbr);
t_tab	ft_char_to_int(char *str_nbr);
void	print_array(char *c,t_tab nb);

// Utils functions to increase readibility of Main Functions
void	ft_compute_prod(t_tab int_res[3], t_tab nbs[4]);
int	ft_find_max_size_prod(t_tab int_res[3]);
void	ft_all_resize(t_tab int_res[3], int max);
t_tab	ft_add_all(t_tab int_res[3]);
int	ft_find_max_size(t_tab nb1, t_tab nb2);
void	ft_add_fix_array(int big[200], t_tab nb[2], int len1, int len2);int	ft_size_res(int nb[200], int *i);
int	ft_size_nbr(int nbr);
t_tab	ft_compute_substraction(t_tab res[3]);

#endif
