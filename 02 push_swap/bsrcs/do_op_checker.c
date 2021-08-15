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

void	do_op_checker(char *str, t_stack *stack)
{
	if (!ft_strcmp(str, "sa"))
		op_s(stack->a);
	else if (!ft_strcmp(str, "sb"))
		op_s(stack->b);
	else if (!ft_strcmp(str, "ss") && op_s(stack->a))
		op_s(stack->b);
	else if (!ft_strcmp(str, "pa"))
		op_p(&(stack->a), &(stack->b));
	else if (!ft_strcmp(str, "pb"))
		op_p(&(stack->b), &(stack->a));
	else if (!ft_strcmp(str, "ra"))
		op_r(&(stack->a));
	else if (!ft_strcmp(str, "rb"))
		op_r(&(stack->b));
	else if (!ft_strcmp(str, "rr") && op_r(&(stack->a)))
		op_r(&(stack->b));
	else if (!ft_strcmp(str, "rra"))
		op_rr(&(stack->a));
	else if (!ft_strcmp(str, "rrb"))
		op_rr(&(stack->b));
	else if (!ft_strcmp(str, "rrr") && op_rr(&(stack->a)))
		op_rr(&(stack->b));
	else
		terminate(0, stack, 1);
}
