/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:02:34 by snam              #+#    #+#             */
/*   Updated: 2021/07/22 23:05:15 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		argc = split_argv(&argv);//number of items
	if (argc >= 2 && argv)
		push_swap(argc, argv);
	else
		write(2, "Error", 5);
	return (0);
}
