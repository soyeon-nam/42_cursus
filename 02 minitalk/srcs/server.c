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
		BIT_FIELD |= (1 << info.bit_ordinal_nb);
	if (info.bit_ordinal_nb == 7)
	{
		if (BIT_FIELD)
			ft_putchar_fd(BIT_FIELD, STDOUT_FILENO);
		else
			ft_putchar_fd('\n', STDOUT_FILENO);
		info.bit_ordinal_nb = 0;
		BIT_FIELD = 0;
		return ;
	}
	++info.bit_ordinal_nb;
}

int	main(void)
{
	struct sigaction act;

	// act.sa_mask doesn't have to initialize??
	act.sa_flags = 0;
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
