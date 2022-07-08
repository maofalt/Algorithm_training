#include "MergeSort.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;
	if (argc > 2) 
	{
		//Doubles are still not handle
		*stack.a = ft_parsing(argv, argc);
		if (stack.a->head){
			ft_list_print_data(*stack.a);
			ft_sorting(*stack.a);
			ft_list_free(stack.a );
		}
		else
		{
			printf("Error while Parsing\n");
			return (0);
		}
	}
	else
	{
		printf("There are not numbers\n");
	}
}
