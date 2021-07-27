#include "push_swap.h"

int				count_item(t_node *stack)
{
	int			ret;
	t_node		*curr_stack;

	ret = 1;
	curr_stack = stack;
	while (curr_stack != stack)
	{
		curr_stack = curr_stack->next;
		++ret;
	}
	return (ret);
}

void			quick_sort(t_stack *stack)
{
	int			cnt;

	cnt = count_item(stack->a);
	if (cnt < 10)

	else

}