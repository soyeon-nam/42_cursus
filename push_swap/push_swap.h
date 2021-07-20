#include <unistd.h>
#include <stdarg.h>


typedef struct		s_node
{
	int			num;
	t_node		*prev;
	t_node		*next;	
}					t_node;
