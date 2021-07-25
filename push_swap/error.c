#include "push_swap.h"

void		error(t_node *stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit (0);
}