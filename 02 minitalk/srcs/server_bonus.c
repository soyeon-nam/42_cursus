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

static t_info_b	info;

static void	init_info()
{
	t_list		*next_ptr;
	char		*client_pid;

	info.oponent_pid = 0;
	info.null = 0;
	info.received_msg_bit_cnt = 0;
	info.bit_field.uc = 0;
	while (info.msg)
	{
		next_ptr = info.msg->next;
		free(info.msg->content);
		free(info.msg);
		info.msg = next_ptr;
	}
	info.msg = 0;
	ft_putstr_fd("Please Enter Client PID : ", STDOUT_FILENO);
	get_next_line(STDIN_FILENO, &client_pid);
	ft_putchar_fd('\n', STDOUT_FILENO);
	info.oponent_pid = ft_atoi(client_pid);
	free(client_pid);
}

static void	print_msg()
{
	t_list		*last;
	t_list		*curr;

	curr = info.msg;
	last = ft_lstlast(info.msg);
	// ft_putstr_fd("received message: >>", STDOUT_FILENO);
	while (curr)
	{
		write(1, (char *)(curr->content), 1);
		curr = curr->next;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	init_info();
}

static void	check_error()
{
	static int		total_bit = 0;
	static int		flag = 0;

	if (info.null == 1 && info.bit_field.uc == 0)
		return ;
	else if (info.null == 2 && info.bit_field.uc == 0 && flag == 0)
	{	
		flag = 1;
		return ;
	}
	else if (info.null == 2 && flag == 1)
	{
		total_bit *= 10;
		total_bit += (info.bit_field.uc - '0'); // - '0' 코드 추가!
		return ;
	}
	else if (info.null == 3 && info.bit_field.uc == 0) 
		return ;

/*
** 	line 84~87은 수정한 코드
** 	info.null == 4 && info.bit_field.uc == 0 경우
*/
	// printf("total_bit: %d\n", total_bit);
	// printf("info.bit_field.uc: %d\n", info.bit_field.uc);
	// printf("info.bit_ordinal_nb: %d\n", info.received_msg_bit_cnt);
	
	if (total_bit == info.received_msg_bit_cnt)
	{
		// write(1, "\nequal\n", 8);
		return ;
	}

/*
** 	line 91~는 원래 코드
** 	else if (info.null == 4 && info.bit_field.uc == 0)
** 		if (total_bit == info.bit_field.uc)
** 			return ;
** 	init_info();
**	ft_putstr_fd("*** ERROR : Invalid attempt was made. ***", \
**				STDERR_FILENO);
**	exit(0);
*/
}

static char	*init_content(char c) // 함수 추가!
{
	char	*content;

	content = (char *)malloc(sizeof(char) * 1);
	// if (content == NULL)
	// 	terminate();
	*content = c;
	return (content);
}

static void	handler(int signo)
{
	t_list			*new;
	// static int		killed_cnt;

	if (signo == SIGUSR2)
	{
		info.bit_field.uc |= (1 << (info.killed_cnt % 8));
		// write(1, "	[received 1]\n", 15);
	}
	else
		// write(1, "	[received 0]\n", 15);
	usleep(20);
	kill(info.oponent_pid, signo);
	// printf("killed_cnt: %d\n", info.killed_cnt);
	info.killed_cnt++;
	if (info.killed_cnt % 8 == 0) // 조건 추가!
	{
		if (info.bit_field.uc == 0)
			++info.null;
		// else
		else if (!(1 <= info.null && info.null <= 4))
		{
			// new = ft_lstnew(&(info.bit_field.uc));
			info.received_msg_bit_cnt += 8; // <- 옮긴위치
			new = ft_lstnew(init_content(info.bit_field.uc)); // 함수 추가!
			ft_lstadd_back(&info.msg, new);
		}
		// printf("info.null: %d\n", info.null);
		if (1 <= info.null && info.null <= 4)
			check_error(); // <- 이것만 잘 작동하면 된다!
		if (info.null == 4)
		{
			info.killed_cnt = 0;
			return (print_msg());
		}
		info.bit_field.uc = '\0'; // 코드 추가! // buffer init
	}
	// ++info.bit_ordinal_nb; // <- 원래위치
}

int	main(void)
{
	struct sigaction act;

	act.sa_flags = 0;
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_putstr_fd("Server PID : ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	init_info();
	while (1)
	{
		if (info.killed_cnt == 0)
			kill(info.oponent_pid, SIGUSR1);
		pause();
	}
	return (0);
}

//처음부터 사이즈를 알기 어려울 때는 배열을 사용하는 것보다 연결리스트가 효율적
