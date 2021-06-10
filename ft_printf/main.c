#include "ft_printf.h"
#include <limits.h> 

int			main(void)
{	
	int d = 135;

	printf("%-4.d/\n", d);
	ft_printf("%-4.d/\n\n", d);

	printf("%-4.*d/\n", -4, d);
	ft_printf("%-4.*d/\n\n", -4, d);

	printf("%-4.*d/\n", -3, d);
	ft_printf("%-4.*d/\n\n", -3, d);

	printf("%-4.*d/\n", -2, d);
	ft_printf("%-4.*d/\n\n", -2, d);

	printf("%-4.*d/\n", -1, d);
	ft_printf("%-4.*d\n\n", -1, d);

	return (0);
}
