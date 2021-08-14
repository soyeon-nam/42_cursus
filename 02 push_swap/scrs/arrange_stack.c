/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:53 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:06:07 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	***split_argv_based_whitespace(int argc, char **argv)
{
	char		***arr;
	int			i;
	
	arr = (char ***)malloc(sizeof(char **) * argc);
	if (!arr)
		terminate(0, 0, 1);
	i = -1;
	while (++i < argc - 1)
	{
		arr[i] = ft_split(argv[i + 1], ' ');
		if (!arr[i])
			terminate(arr, 0, 1);
	}
	arr[i] = 0;
	return (arr);
}

static void	check_dup(t_stack *stack, int item, char ***arr)
{
	t_node		*stack_curr;

	if (stack->a)
	{
		stack_curr = stack->a->next;
		while (1)
		{
			if (stack_curr->item == item)
				terminate(arr, stack, 1);
			if (stack_curr->next == stack->a->next)
				break ;
			stack_curr = stack_curr->next;
		}
	}
	return ;
}

static void	create_node(t_stack *stack, int item, char ***arr)
{
	t_node		*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		terminate(arr, stack, 1);
	new->item = item;
	top_node(&(stack->a), &new);
	op_r(&(stack->a));
}

static void	parse(char ***arr, t_stack *stack)
{
	int			i;
	int			j;
	int			is_biggest_node_hitherto;
	int			item;

	stack->a = 0;
	stack->b = 0;
	is_biggest_node_hitherto = 0;
	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			item = ft_atoi_ps(arr[i][j], arr, stack);
			check_dup(stack, item, arr);
			create_node(stack, item, arr);
		}
	}
}

t_stack	*arrange_stack(int argc, char **argv)
{
	char		***arr;
	int			i;
	t_stack		*stack;

	arr = split_argv_based_whitespace(argc, argv);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		terminate(arr, 0, 1);
	parse(arr, stack);
	i = -1;
	while (arr[++i])
		free_malloc_slpit(arr[i]);
	free(arr);
	return (stack);
}
