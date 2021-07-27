#include "../inc/push_swap.h"

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

int				find_pivot(t_node *stack, int cnt)
{
	int				cnt_init;
	t_node			*curr;
	t_node			*node;

	node = stack;
	while (1)
	{
		cnt = cnt_init;
		curr = stack;
		while (curr->next == curr)
		{
			if (node->item < curr->item)
				--big;
			curr = curr->next;
		}
		if (cnt == cnt / 3)
			break ;
		if (cnt == cnt * 2 / 3)
			break ;
		node = node->next;
	}
	return (node->item);
}

void			quick_sort(t_stack *stack)
{
	int			cnt;

	cnt = count_item(stack->a);
	if (cnt <= 5)
		sort_under_six();
	else
		a_to_b(cnt);
}