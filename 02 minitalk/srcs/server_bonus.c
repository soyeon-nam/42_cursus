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

static t_info_b	info;
// static t_info_b	info = {0, 0, 0, 0, 0};

static void	init_info()
{
	t_list		*next_ptr;

	info.oponent_pid = 0;
	info.null = 0;
	info.bit_ordinal_nb = 0;
	info.bit_field.uc = 0;
	while (info.msg)
	{
		next_ptr = info.msg->next;
		free(info.msg);
		info.msg = next_ptr;
	}
	info.msg = 0;
}

static void	print_msg()
{
	t_list		*last;
	t_list		*curr;

	curr = info.msg;
	last = ft_lstlast(info.msg);
	while (curr)
	{
		write(1, &(curr->content), 1);
		curr = curr->next;
	}
	write(1, "\n", 1);
	init_info();
}

static void	check_error()
{
	static int		total_bit = 0;
	static int		flag = 0;

	if (info.null == 1 && info.bit_field.uc == 0)
		return ;
	else if (info.null == 2 && info.bit_field.uc == 0 && flag == 0)
		flag = 1;
	else if (info.null == 2 && flag == 1)
	{
		total_bit *= 10;
		total_bit += info.bit_field.uc;
		return ;
	}
	else if (info.null == 3 && info.bit_field.uc == 0)
		return ;
	else if (info.null == 4 && info.bit_field.uc == 0)
		if (total_bit == info.bit_field.uc)
			return ;
	init_info();
	ft_putstr_fd("*** ERROR : Invalid attempt was made. ***", \
				STDERR_FILENO);
	exit(0);		
}

static void	handler(int signo)
{
	t_list			*new;
	
	if (signo == SIGUSR2)
		info.bit_field.uc |= (1 << (info.bit_ordinal_nb % 8));
	usleep(50);
	kill(info.oponent_pid, signo);
	if (info.bit_ordinal_nb % 8 == 0)
	{
		if (info.bit_field.uc == 0)
			++info.null;
		else 
		{
			new = ft_lstnew(&(info.bit_field.uc));
			ft_lstadd_back(&info.msg, new);
		}
		if (1 <= info.null && info.null <= 4)
			check_error();
		if (info.null == 4)
			return (print_msg());
	}
	++info.bit_ordinal_nb;
}

int	main(void)
{
	struct sigaction act;
	char	*client_pid;

	act.sa_flags = 0;
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_putstr_fd("Server PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	get_next_line(STDIN_FILENO, &client_pid);
	info.oponent_pid = ft_atoi(client_pid);
	while (1)
		pause();
	return (0);
}
//처음부터 사이즈를 알기 어려울 때는 연결리스트 사용하는 게 배열을 사용하는 것보다 효율적
