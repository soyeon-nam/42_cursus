#include "push_swap.h"

static void		conquer_three_zero(t_node **stack, void (**f)(t_stack *), short is_b)
{
	f[0 + is_b](stack);
	f[2 + is_b](stack);
	f[0 + is_b](stack);
	f[3 + is_b](stack);
	f[0 + is_b](stack);
}

static void		conquer_three_one(t_node **stack, void (**f)(t_stack *), short is_b)
{
	f[2 + is_b](stack);
	f[0 + is_b](stack);
	f[3 + is_b](stack);
	f[0 + is_b](stack);
}

static void		conquer_three_two(t_node **stack, void (**f)(t_stack *), short is_b)
{
	f[0 + is_b](stack);
	f[2 + is_b](stack);
	f[0 + is_b](stack);
	f[3 + is_b](stack);
}

static void		conquer_three(t_node **stack, void (**f)(t_stack *), short is_b)
{
	int			num;

	num = tag_number_three(*stack);
	if (num = 0)
		conquer_three_zero(stack, f, is_b);
	else if (num = 1)
		conquer_three_one(stack, f, is_b);
	else if (num = 2)
		conquer_three_two(stack, f, is_b);
	else if (num = 5)
	{
		f[2 + is_b](stack);
		f[0 + is_b](stack);
		f[3 + is_b](stack);
	}
	else if (num = 6)
		f[0 + is_b](stack);
	else
		return ;
}

void			conquer(t_node **stack, int left, 
					void (**f)(t_stack *), short is_b)
{
	if (left == 3)
		conquer_three(stack, f, is_b);
	if else (left == 2)
		if ((*stack)->prev->item > (*stack)->prev->prev->item)
			f[0 + is_b](stack);
	else
		return ;
}
