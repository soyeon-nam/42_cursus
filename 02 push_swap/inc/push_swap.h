#include <stdio.h>


#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct		s_node
{
	int				item;
	struct s_node	*prev;
	struct s_node	*next;	
}					t_node;

typedef struct		s_stack
{
	struct s_node	*a;
	struct s_node	*b;
}					t_stack;

typedef struct		s_sort_info
{
	int			pivot1;
	int			pivot2;
	int			small_cnt;
	int			middle_cnt;
	int			large_cnt;
}					t_sort_info;

typedef struct		s_rewind
{
	int		rra;
	int		rrb;
}					t_rewind;

/* -------- push_swap.c */
void	push_swap(char ***arr);

/* -------- parse.c */
void	parse(char ***arr, t_stack *stack);

/* -------- quick_sort.c */
void	quick_sort(t_stack *stack);

/* -------- sort_under_six.c */
void	sort_under_six(t_stack *stack, int cnt);

/* -------- a_to_b.c */
void	a_to_b(t_stack *stack, int cnt);
void	conquer_a(t_stack *stack, int cnt);

/* -------- b_to_a.c */
void	b_to_a(t_stack *stack, int cnt);
void	conquer_b(t_stack *stack, int cnt);

/* -------- find_pivot.c */
void	set_pivot(t_node *stack, t_sort_info *info, int cnt);
int		find_pivot(t_node *stack, int cnt, int order);

/* -------- divide_a.c */
void	divide_a(t_stack *stack, int cnt, t_sort_info *info);

/* -------- divide_b.c */
void	divide_b(t_stack *stack, int cnt, t_sort_info *info, t_rewind *rewind);

/* -------- do_op.c */
void	do_op(char *str, t_stack *stack);
bool	op_r(t_node **head);

/* -------- do_op_app.c */
void	pop_node(t_node **stack);
void	top_node(t_node **stack, t_node **node);

/* -------- do_multiple_op.c */
void	do_multiple_op(t_stack *stack, int num, ...);

/* -------- terminate.c */
void	terminate(char	***split, t_stack *stack, bool is_error);
void	**free_malloc_slpit(char **str);

/* -------- ft_atoi_ps.c */
int		ft_atoi_ps(const char *str, char ***arr, t_stack *stack);
/* -------- ft_split.c */
char	**ft_split(char const *s, char c);
/* -------- ft_strcmp.c */
int		ft_strcmp(char *s1, char *s2);
