#include "../inc/push_swap.h"

static int	is_divided_b(t_node *stack, int cnt, int pivot)
{
	int			ret;

	ret = 0;
	while (cnt--)
		stack = stack->next;
	while (1)
	{
		if (stack->item >= pivot)
			break ;
		stack = stack->prev;
		++ret;
	}
	return (ret);
}

void	divide_b(t_stack *stack, int cnt, t_sort_info *info, t_rewind *r)
{
	int				rra;
	int				rrb;

	rra = 0;
	rrb = 0;
	set_pivot(stack->b, info, cnt);
	cnt -= is_divided_b(stack->a, cnt, info->pivot1);
	while (cnt--)
	{
		if (cnt == 1 && (stack->a->next->item <= info->pivot1))
		{
			do_multiple_op(stack, 2, "sb", "pa");
			break ;
		}
		if ((stack->b->next->item <= info->pivot1) && ++rrb)
			do_op("rb", stack);
		else if ((stack->b->next->item <= info->pivot2) && ++rra)
			do_multiple_op(stack, 2, "pa", "ra");
		else
			do_op("pa", stack);
	}
	r->rra = rra;
	r->rrb = rrb;
}
