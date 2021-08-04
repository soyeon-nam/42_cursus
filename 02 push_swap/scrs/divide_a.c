#include "../inc/push_swap.h"

static int	is_divided_a(t_node *stack, int cnt, int pivot)
{
	int			ret;

	ret = 0;
	while (cnt--)
		stack = stack->next;
	while (1)
	{
		if (stack->item <= pivot)
			break ;
		stack = stack->prev;
		++ret;
	}
	return (ret);
}

void	divide_a(t_stack *stack, int cnt, t_sort_info *info)
{
	int				rra;
	int				rrb;

	rra = 0;
	rrb = 0;
	set_pivot(stack->a, info, cnt);
	cnt -= is_divided_a(stack->a, cnt, info->pivot2);
	while (cnt--)
	{
		if (cnt == 1 && (stack->a->next->item > info->pivot2))
		{
			do_multiple_op(stack, 2, "sa", "pb");
			break ;
		}
		if ((stack->a->next->item > info->pivot2) && ++rra)
			do_op("ra", stack);
		else if ((stack->a->next->item > info->pivot1) && ++rrb)
			do_multiple_op(stack, 2, "pb", "rb");
		else
			do_op("pb", stack);
	}
	rewind_stack(stack, rra, rrb);
}
