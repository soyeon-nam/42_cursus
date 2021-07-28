#include "../inc/push_swap.h"

int				find_two_pivot(t_node *stack, int cnt, int *pivot1, int *pivot2)
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
