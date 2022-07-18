#include "MergeSort.h"

int	main(int argc, char **argv)
{
	t_stacks	*stack;
	t_list		list_a;

	stack = malloc(sizeof(t_stacks));
	if (argc >= 2)
	{
		list_a = ft_parsing(argv, argc);
		stack->a = &list_a;
		stack->mov = ft_mov_initiliaze();
		stack->total_moves = 0;
		stack->operations = NULL;
		if (stack->a->head)
		{
			ft_list_print_data(*stack->a);
			ft_sorting_main(stack);
			ft_list_print_data(*stack->a);
			ft_list_free(stack->a);
			free(stack->operations);
		}
		else
		{
			printf("Error while Parsing\n");
			return (free(stack), 1);
		}
	}
	else
	{
		printf("There are not numbers\n");
	}
	free(stack);
	return (0);
}
