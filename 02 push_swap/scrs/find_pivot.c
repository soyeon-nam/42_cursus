#include "../inc/push_swap.h"

int	find_pivot(t_node *stack, int cnt, int order)
{
	int				check;
	t_node			*curr;
	t_node			*node;

	node = stack;
	while (1)
	{
		check = cnt;
		curr = node;
		while (1)
		{
			if (node->item < curr->item)
				--check;
			if (curr->next == node)
				break;
			curr = curr->next;
		}
		if (check == order)
			break ;
		node = node->next;
	}
	return (node->item);
}
