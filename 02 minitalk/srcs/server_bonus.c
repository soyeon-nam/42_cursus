/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:40:51 by snam              #+#    #+#             */
/*   Updated: 2021/08/31 03:40:53 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_bonus	info;

static void	handshaking(int signo, int si_pid)
{
	int		i;

	if (info.killed_cnt == 1 && signo == SIGUSR2)
		info.opponent_pid = si_pid;
	else if (info.opponent_pid != si_pid || signo != SIGUSR2)
	{
		info.opponent_pid = 0;
		info.killed_cnt = 0;
		info.bit_field.uc = 0;
	}
	else if (info.killed_cnt == 8)
	{
		i = 8;
		while (i--)
		{
			usleep(20);
			kill(info.opponent_pid, SIGUSR2);
		}
	}
}

void	get_msg_bit_total()
{
	static int	msg_bit_cnt;

	msg_bit_cnt++;
	if (msg_bit_cnt % 8)
	{
		if (info.bit_field.uc)
			msg_bit_cnt = (msg_bit_cnt * 10) + (info.bit_field.uc - '0');
		else
			info.msg_bit_total = msg_bit_cnt;
	}
	//error case when??
}

static void	sigaction(int signo, siginfo_t *siginfo, void *context)
{
	static int	killed_cnt;

	info.bit_field.uc <<= 1;
	if (signo == SIGUSR2)
		info.bit_field.uc |= 1;
	info.killed_cnt++;
	if (info.killed_cnt <= 8)
		return (handshaking(signo, siginfo->si_pid));
	if (!info.msg_bit_total)
	{
		// msg_bit_cnt++;
		// if (msg_bit_cnt % 8)
		// {
		// 	if (info.bit_field.uc)
		// 		msg_bit_cnt = (msg_bit_cnt * 10) + (info.bit_field.uc - '0');
		// 	else
		// 		info.msg_bit_total = msg_bit_cnt;
		// }
	}
	else
	{

	}
	kill(info.opponent_pid, signo);
}











int	main(int ac, char *av)
{
	struct sigaction	act;

	if (ac != 1)
		return (1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigaction;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	info.current_pid = getpid();

	while (1)
	{
		if (info.msg_bit_total)
		{
			/* error handling : init, msg = 0, error message */
			sleep(5);
		}
		else
			pause();
	}
	return (0);
}

//처음부터 사이즈를 알기 어려울 때는 배열을 사용하는 것보다 연결리스트가 효율적
