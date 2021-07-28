/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:53 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:54 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		check_dup(t_stack *stack, int item, char ***arr)
{
	t_node		*stack_a;
	t_node		*stack_curr;
	int			sign;

	if (stack->a)
	{
		sign = 1;
		stack_curr = stack_a = stack->a;
		while (1)
		{
			if (stack_curr->item == item)
				terminate(arr, stack, 1);
			if (stack_curr->next == stack)
				break ;
			if (stack_curr->item < stack_curr->next->item)
				sign = 0;
			stack_curr = stack_curr->next;
		}
		if (sign == 1 && (stack_curr->item > item))
		{
			// printf("SORTED\n");
			return (1);
		}
	}
	return (0);
}

static void		create_node(t_stack **stack, int item, char ***arr)
{
	t_node		*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		terminate(arr, stack, 1);
	new->item = item;
	top_node(&((*stack)->a), &new);
}

void			parse(char ***arr, t_stack *stack)
{
	int			i;
	int			j;
	int			is_sorted;
	int			item;

	i = 0;
	j = 0;
	stack->a = 0;
	stack->b = 0;
	while (arr[i])
		while (arr[i][j]);
		{
			item = ft_atoi_ps(arr[i][j], arr, stack);
			is_sorted += check_dup(stack, item, arr);
			create_node(stack, item, arr);
		}
	if (is_sorted == i * j - 1)
		terminate(arr, stack, 0);
}
