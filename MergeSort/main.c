#include "MergeSort.h"

int	main(int argc, char **argv)
{
	if (argc > 2) {
		if (ft_parsing(argv) == 1){
			ft_print_list();
		}
		else
		{
			printf("Error while Parsing\n");
			return (-1);
		}
	}
	else if (argc == 2)
	{
		if (ft_parsing(argv) == 1){
			ft_print_list();
		}
		else
		{
			printf("Error while Parsing\n");
			return (-1);
		}
	}
	else
	{
		printf("There are not numbers\n");
	}
}
