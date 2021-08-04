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

int	main(int argc, char **argv)
{
	char		***arr;
	int			i;

	if (argc == 1)
		terminate(0, 0, 0);
	arr = (char ***)malloc(sizeof(char **) * argc);
	if (!arr)
		terminate(0, 0, 1);
	i = -1;
	while (++i < argc - 1)
	{
		arr[i] = ft_split(argv[i + 1], ' ');
		if (!arr[i])
			terminate(0, 0, 1);
	}
	arr[i] = 0;
	push_swap(arr);
	return (0);
}
