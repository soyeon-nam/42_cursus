/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:13:45 by snam              #+#    #+#             */
/*   Updated: 2021/08/21 21:13:46 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	info;

static void	handler(int signo)
{
	if (!info.bit_arr)
	{
		info.bit_arr = (int *)malloc(sizeof(int) * 8);
		if (!info.bit_arr)
		{
			ft_putchar_fd("ERROR\n", STDOUT_FILENO);
			exit(0);
		}
	}
	if (signo == SIGUSR1)
		bit_arr[info.bit_index] = 0;
	else
		bit_arr[info.bit_index] = 1;
	while (info.bit_index == 8)
	{
		// bitwise operation needed
		return ;
	}
	info.bit_index++;
}

int	main(void)
{
	int		signal;
	struct sigaction act;

	act.__sigaction_u.__sa_handler = &handler;
	sigaction(SIGUSR1, handler, 0);
	sigaction(SIGUSR2, handler, 0);
	ft_putstr_fd("Server PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		pause();
	return (0);
}
