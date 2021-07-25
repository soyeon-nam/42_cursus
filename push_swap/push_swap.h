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

#include <stdio.h>






#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

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

int			tag_number_three(t_node *stack);


int			atoi_ps(const char *str, int *is_int);


t_node		*arrange_stack(char **argv, int argc);
void		arrange_sorting(t_info *info, t_stack *stack, 
					void (**f)(t_stack *), int argc);
					
void		quick_sort(t_stack *stack, t_info *info, 
					void (**f)(t_stack *));

void		conquer(t_node **stack, int left, 
				void (**f)(t_stack *), short is_b);
void		conquer_three(t_node **stack, 
				void (**f)(t_stack *), short is_b);



void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);

void		free_stack(t_node *stack);
