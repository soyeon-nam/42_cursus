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

void		push_swap(int argc, char **argv);



t_node		*arrange_stack(char **argv, int argc);


int			add_node(t_node **stack, int item);

void		quick_sort(t_node *stack_a);

void		free_stack(t_node *stack);



int			ft_atoi_ps(const char *str, bool *is_int);
int			split_argv(char ***str);


