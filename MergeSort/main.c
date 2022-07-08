#include "MergeSort.h"

int	main(int argc, char **argv)
{
	t_list	list;

	if (argc > 2) 
	{
		list = ft_parsing(argv, argc);
		if (list.head){
			ft_list_print_data(list);
			ft_list_free(&list);
		}
		else
		{
			printf("Error while Parsing\n");
			return (0);
		}
	}
	else if (argc == 2)
	{
		if (ft_parsing(argv, argc).head){
			ft_list_print_data(list);
			ft_list_free(&list);
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
