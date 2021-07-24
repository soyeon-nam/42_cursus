/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:51:38 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 20:57:34 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>


#include <stdio.h>


typedef struct		s_node
{
	int				item;
	struct s_node	*prev;
	struct s_node	*next;	
}					t_node;

typedef struct		s_info
{
	int				a_sorted;
	int				b_sorted;
	int				a_left;
	int				b_left;
}					t_info;

typedef struct		s_stack
{
	struct s_node	*a;
	struct s_node	*b;
}					t_stack;

void		push_swap(int argc, char **argv);



t_node		*arrange_stack(char **argv, int argc);


int			add_node(t_node **stack, int item);

void		quick_sort(t_stack *stack, t_info *info);

void		free_stack(t_node *stack);



int			ft_atoi_ps(const char *str, int *is_int);

int			split_argv(char ***argv);
void		**free_malloc(char **str, int i);
