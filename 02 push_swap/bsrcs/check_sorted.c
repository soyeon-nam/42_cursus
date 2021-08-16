/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:38:14 by snam              #+#    #+#             */
/*   Updated: 2021/08/15 16:38:16 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static bool	apply_input_op(t_stack *stack)
{
	char	*line;
	int		gnl_ret;

	gnl_ret = get_next_line(STDIN_FILENO, &line);
	while (gnl_ret > 0)
	{
		do_op_checker(line, stack);
		free(line);
		gnl_ret = get_next_line(STDIN_FILENO, &line);
	}
	if (*line || gnl_ret == -1)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

void	check_sorted(t_stack *stack)
{
	int		cnt;
	bool	is_error;
	bool	is_sorted;

	cnt = count_item(stack->a);
	if (!cnt)
		terminate(0, stack, 1);
	is_error = apply_input_op(stack);
	if (is_error)
		terminate(0, stack, 1);
	if (is_ascend(stack->a, cnt))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
