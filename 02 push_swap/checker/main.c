#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	char		***arr;
	int			i;

	if (argc == 1)
		return (0);
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
	push_swap(arr);
	return (0);
}
