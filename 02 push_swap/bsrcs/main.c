/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:38:26 by snam              #+#    #+#             */
/*   Updated: 2021/08/15 16:38:28 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;

	if (argc == 1)
		return (0);
	stack = arrange_stack(argc, argv);
	check_sorted(stack);
	terminate(0, stack, 0);
	return (0);
}
