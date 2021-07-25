/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:02:34 by snam              #+#    #+#             */
/*   Updated: 2021/07/23 18:04:27 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		is_error;

	if (argc == 2)
	{
		atoi_ps(argv[1], &is_error);
		if (is_error)
			write(2, "Error\n", 6);
	}
	else if (argc >= 3)
		push_swap(argc, argv);
	else
		write(2, "Error\n", 6);
	return (0);
}
