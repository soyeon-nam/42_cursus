/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:05 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:01:08 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			push_swap(char ***arr)
{
	t_stack		stack;
	int			i;

	parse(arr, &stack);
	i = -1;
	while (arr[++i])//split  mallocfree
		free_malloc_slpit(arr[i]);
	quick_sort(&stack);
	terminate(0, &stack, 0);
}
