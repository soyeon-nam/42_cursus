/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 03:40:31 by snam              #+#    #+#             */
/*   Updated: 2021/08/31 03:40:40 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_bonus	info;

static void	terminate_error()
{
	/* 전역 변수 모두 reset */
	exit(0);
}

static void	send_bit()
{
	/* sending check either */
}

static void	sigaction(int signo, siginfo_t *siginfo, void *context)
{
	++info.killed_cnt;
	if (siginfo->si_pid != info.opponent_pid)
		return (terminate_error());
	
		
}

static void	handshaking(int bit_total)
{
	int		i;

	i = 8;
	while (i--)
	{
		usleep(20);
		kill(info.opponent_pid, SIGUSR2);
	}
	i = 8;
	while (i--)
		pause(); //usleep(20);

	/* send how many bit client will send */
		// 개수 세서 다 보내면 NULL보내기
	/* 이 외의 것 ERROR -> terminate */
}

static void	send_message(int bit_total)
{
	/* 메세지 보내기 중간에 에러 나면 terminate_error() */
}

int	main(int ac, char **ag)
{
	struct sigaction	act;
	int					sending_bit_total;

	if (ac != 3)
		return (-1);
	info.opponent_pid = ft_atoi(ag[1]);
	if (info.opponent_pid > PID_MAX || *ag[2] == '\0')
		return(-1);

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigaction;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	info.current_pid = getpid();
	sending_bit_total = ft_strlen(ag[2]) * 8;
	handshaking(sending_bit_total);
	send_message(sending_bit_total);
	return (0);
}

// Min pid: 100
// Max pid: 99998