#include "push_swap.h"

void	do_op(char *str, t_stack **stack)
{
	if (!ft_strcmp(str, "sa") && op_s(*a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && op_s(*b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ss") && op_s(*a) && op_s(*b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "pa") && push_node(a, pop_node(b)))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && push_node(b, pop_node(a)))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "ra") && op_r(a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && op_r(b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rr") && op_r(a) && op_r(b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rra") && op_rr(a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && op_rr(b))
		write(1, "rrb\n", 4);
	else if (!ft_strcmp(str, "rrr") && op_rr(a) && op_rr(b))
		write(1, "rrr\n", 4);
}

void		reverse(t_node **stack)
{
	*stack = (*stack)->next;
}
