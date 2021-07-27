
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

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

