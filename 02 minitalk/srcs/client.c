/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:13:38 by snam              #+#    #+#             */
/*   Updated: 2021/08/21 21:13:39 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int server_pid, char *msg)
{
	int		signal;
	int		bit_index;
	int		i;

	while (*msg)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			signal = 1 & (*msg >> bit_index);
			usleep(20);
			if (signal == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			++bit_index;
		}
		++msg;
	}
	i = 0;
	while (i++ < 8)
	{
		usleep(20);
		kill(server_pid, SIGUSR1);
	}
}

int	main(int ac, char **ag)
{
	int		server_pid;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(ag[1]);
	if (server_pid > PID_MAX || *ag[2] == '\0')
		return(0);
	send_message(server_pid, ag[2]);
	return (0);
}
