#include "../inc/push_swap.h"

void	do_many_op(t_stack *stack, int num, ...)
{
	va_list			ap;
	char			*op;

	va_start(ap, num);
	while (num--)
	{
		op = va_arg(ap, char *);
		do_op(op, &(stack->a), &(stack->b));
	}
}