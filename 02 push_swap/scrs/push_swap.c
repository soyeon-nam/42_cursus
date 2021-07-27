#include "../inc/push_swap.h"

void			push_swap(char ***arr)
{
	t_stack		stack;
	int			i;

	parse(arr, &stack);
	i = -1;
	while (arr[++i])//split  mallocfree
		free_malloc_slpit(arr[i]);
	quick_sort(&stack);
	terminate(0, &stack, 0);
}
