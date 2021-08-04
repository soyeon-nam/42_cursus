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

void	push_swap(char ***arr);

void	parse(char ***arr, t_stack *stack);

void	quick_sort(t_stack *stack);
int		count_item(t_node *stack);

void	sort_under_six(t_stack *stack, int cnt);

void	a_to_b(t_stack *stack, int cnt);
void	conquer_a(t_stack *stack, int cnt);
void	b_to_a(t_stack *stack, int cnt);
void	conquer_b(t_stack *stack, int cnt);

void	set_pivot(t_node *stack, t_sort_info *info, int cnt);
int		find_pivot(t_node *stack, int cnt, int order);

void	do_op(char *str, t_stack *stack);
void	do_multiple_op(t_stack *stack, int num, ...);
bool	op_r(t_node **head);

void	pop_node(t_node **stack);
void	top_node(t_node **stack, t_node **node);

int		ft_atoi_ps(const char *str, char ***arr, t_stack *stack);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);

void	terminate(char	***split, t_stack *stack, bool is_error);
void	**free_malloc_slpit(char **str);

int	is_acsend(t_node *stack, int cnt);
int	is_decsend(t_node *stack, int cnt);
