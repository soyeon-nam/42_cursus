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

int				g_received_signo;
static int		g_transmited_bit_cnt;

static void	handler(int signo)
{
	if (signo == SIGUSR1)
		g_received_signo = 0;
	else if (signo == SIGUSR2)
		g_received_signo = 1;
}

static void	terminate_error(int server_pid, int bit_left)
{
	int i;

	while (bit_left--)
	{
		usleep(50);
		kill(server_pid, SIGUSR1);
	}
	i = 0;
	while (i++ < 15)
	{
		usleep(50);
		kill(server_pid, SIGUSR1);
	}
	usleep(50);
	kill(server_pid, SIGUSR2);
	ft_putstr_fd("*** ERROR : Message was not sent properly. ***\n", \
				STDERR_FILENO);
	exit(0);
}

static void	send_byte(int server_pid, char byte)
{
	int		signal;
	int		bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		signal = 1 & (byte >> bit_index);
		usleep(2000);
		if (signal == 0)
		{	kill(server_pid, SIGUSR1);
			// write(1, "	[kill 0]\n", 11);
		}
		else
		{	kill(server_pid, SIGUSR2);
			// write(1, "	[kill 1]\n", 11);
		}
		g_transmited_bit_cnt++;
		pause();
		if (signal != g_received_signo)
			terminate_error(server_pid, 7 - bit_index);
		bit_index++;
	}
}

static void	send_message(int server_pid, char *msg)
{
	while (*msg)
	{
		send_byte(server_pid, *msg);
		++msg;
	}
}

static void	check_error(int server_pid)
{
	int		i;
	char	*transmited_bit_total;

	i = 0;
	while (i++ < 16)
	{
		usleep(2000);
		kill(server_pid, SIGUSR1);
		// g_transmited_bit_cnt++;
		// write(1, "	[null1 : 0]\n", 13);
	}

	transmited_bit_total = ft_itoa(g_transmited_bit_cnt);
	// ft_putstr_fd("transmited_bit_total: ", STDOUT_FILENO);
	// ft_putstr_fd(transmited_bit_total, STDOUT_FILENO);
	// ft_putstr_fd("\n", STDOUT_FILENO);
	while (*transmited_bit_total)
	{
		send_byte(server_pid, *transmited_bit_total);
		++transmited_bit_total;
	}
	i = 0;
	while (i++ < 16)
	{
		usleep(2000);
		kill(server_pid, SIGUSR1);
		// g_transmited_bit_cnt++;
		// write(1, "	[null2 : 0]\n", 13);
	}
	ft_putstr_fd("*** SUCCESS ***\n", STDOUT_FILENO);
}

int	main(int ac, char **ag)
{
	int					server_pid;
	struct sigaction	act;

	if (ac != 3)
		return (-1);
	server_pid = ft_atoi(ag[1]);
	if (server_pid > PID_MAX || *ag[2] == '\0')
		return(-1);
	act.sa_flags = 0;
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_putstr_fd("Client PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	pause();
	send_message(server_pid, ag[2]);
	check_error(server_pid);
	return (0);
}
