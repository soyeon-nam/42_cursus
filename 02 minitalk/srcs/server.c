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
	if (signo == SIGUSR2)
		info.bit_field.uc |= (1 << info.bit_ordinal_nb);
	if (info.bit_ordinal_nb == 7)
	{
		if (info.bit_field.uc)
			ft_putchar_fd(info.bit_field.uc, STDOUT_FILENO);
		else
			ft_putchar_fd('\n', STDOUT_FILENO);
		info.bit_ordinal_nb = 0;
		info.bit_field.uc = 0;
		return ;
	}
	++info.bit_ordinal_nb;
}

int	main(void)
{
	struct sigaction act;

	act.sa_flags = 0;
	// act.sa_mask doesn't have to initialize??
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_putstr_fd("Server PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		pause();
	return (0);
}
