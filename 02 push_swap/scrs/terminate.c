/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:26 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:01:26 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	**free_malloc_slpit(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}

static void		free_stack(t_node *stack)
{
	t_node		*curr;
	t_node		*prev;

	curr = stack->prev;
	while (curr != stack)
	{
		prev = curr->prev;
		free(curr);
		curr = NULL;
		curr = prev;
	}
	free(stack);
}

void		terminate(char	***split, t_stack *stack, bool is_error)
{
	int		i;

	i = -1;
	if (split)
		while (split[++i])
			free_malloc_slpit(split[i]);
	if (stack)
	{
		if (stack->a)
			free_stack(stack->a);
		if (stack->b)
			free_stack(stack->b);
	}
	if (is_error)
		write(1, "Error\n", 6);
	exit(0);
}
