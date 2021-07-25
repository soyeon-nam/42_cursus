#include "push_swap.h"

int				tag_number_three(t_node *stack)
	int			ret;

	ret = 0;
	if (curr->item < curr->prev->item)
		ret += 1;
	if (curr->prev->item < curr->prev->prev->item)
		ret += 2;
	if (curr->item < curr->prev->prev->item)
		ret += 4;
	return (ret);
}

void		process_three(t_node **stack)
{
	int			num;

	num = tag_number_three(*stack);
	if (num = 0)
	{
		f[3 + is_b](stack);
		f[0 + is_b](stack);
	}
	else if (num = 1)
		f[3 + is_b](stack);
	else if (num = 2)
		f[2 + is_b](stack);
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

void		process_four(t_stack **stack)
{		
	int				rewind;
	int				pivot;

	pivot = find_pivot((*stack)->a, 4);
	while (1)
	{
		if (pivot < ((*stack)->a)->prev->item)
			ra(stack);
		else
		{
			pb(stack);
			--(*left_m);
			++(*left_s);
			break ;
		}
	}
	process_three(stack);
	pa(stack);
}

void		process_five(t_stack **stack)
{
	pivot = find_pivot((*stack)->a, 4);
	while (5--)
	{
		if (pivot < ((*stack)->a)->prev->item)
			ra(stack);
		else
		{
			pb(stack);
			--(*left_m);
			++(*left_s);
		}
	}
	process_three(stack);
	if (stack.b->item > stack.b->next->item)
		sb(stack);
	pa(stack);
	pa(stack);
}