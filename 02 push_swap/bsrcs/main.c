#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;

	if (argc == 1)
		return (0);
	stack = arrange_stack(argc, argv);
	check_sorted(stack);
	terminate(0, stack, 0);
	return (0);
}
