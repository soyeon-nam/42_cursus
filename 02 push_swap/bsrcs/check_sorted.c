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

void	check_sorted(t_stack *stack)
{
	char	*line;
	int		gnl_ret;
	int		cnt;
	int		ret;

	cnt = count_item(stack->a);
	gnl_ret = get_next_line(STDIN_FILENO, &line);
	while (gnl_ret > 0)
	{
		do_op_checker(line, stack);
		free(line);
		gnl_ret = get_next_line(STDIN_FILENO, &line);
	}
	free(line);
	if (gnl_ret == -1)
		terminate(0, stack, 1);
	ret = 0;
	if (cnt > 0)
		ret = is_ascend(stack->a, cnt);
	if (ret)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
