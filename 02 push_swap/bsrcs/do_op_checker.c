/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:26 by snam              #+#    #+#             */
/*   Updated: 2021/08/15 16:38:23 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static inline void	op_error(char *line, t_stack *stack)
{
	free(line);
	terminate(0, stack, 1);
}

void	do_op_checker(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "sa"))
		op_s(stack->a);
	else if (!ft_strcmp(line, "sb"))
		op_s(stack->b);
	else if (!ft_strcmp(line, "ss") && op_s(stack->a))
		op_s(stack->b);
	else if (!ft_strcmp(line, "pa"))
		op_p(&(stack->a), &(stack->b));
	else if (!ft_strcmp(line, "pb"))
		op_p(&(stack->b), &(stack->a));
	else if (!ft_strcmp(line, "ra"))
		op_r(&(stack->a));
	else if (!ft_strcmp(line, "rb"))
		op_r(&(stack->b));
	else if (!ft_strcmp(line, "rr") && op_r(&(stack->a)))
		op_r(&(stack->b));
	else if (!ft_strcmp(line, "rra"))
		op_rr(&(stack->a));
	else if (!ft_strcmp(line, "rrb"))
		op_rr(&(stack->b));
	else if (!ft_strcmp(line, "rrr") && op_rr(&(stack->a)))
		op_rr(&(stack->b));
	else
		op_error(line, stack);
}
