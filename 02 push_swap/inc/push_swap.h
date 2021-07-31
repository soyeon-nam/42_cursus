#include <stdio.h>



#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

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

void			push_swap(char ***arr);


void			parse(char ***arr, t_stack *stack);

void			quick_sort(t_stack *stack);
int				count_item(t_node *stack);

void			sort_under_six(t_stack *stack, int cnt);

void			a_to_b(t_stack *stack, int cnt);
void            b_to_a(t_stack *stack, int cnt);


int				find_pivot(t_node *stack, int cnt, int order);

void			do_op(char *str, t_node **a, t_node **b);


void		pop_node(t_node **stack);
void		top_node(t_node **stack, t_node **node);


int				ft_atoi_ps(const char *str, char ***arr, t_stack *stack);
char					**ft_split_ps(char const *s, char c);
void	**free_malloc_slpit(char **str);


void		terminate(char	***split, t_stack *stack, bool is_error);


int		ft_strcmp(char *s1, char *s2);