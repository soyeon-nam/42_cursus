/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:48 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:49 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				main(int argc, char **argv)
{
	char		***arr;
	int			i;
	int			j;

	arr = (char ***)malloc(sizeof(char **) * argc);
	if (!arr)
		terminate(0, 0, 1);
	i = 0;
	while (++i < argc)
	{
		arr[j] = ft_split_ps(argv[i]);
		if (arr[j])
			++j;
	}
	arr[j] = 0;
	push_swap(arr);
	return (0);
}
