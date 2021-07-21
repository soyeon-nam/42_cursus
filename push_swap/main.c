#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_node 	*stack_a;

	if (argc == 2)
		argv = split_argv(argv[1]);

	stack_a = init_stack(argv);
	push_swap(stack_a);



	if (!stack_a)
	{
		write(1, "ERROR", 5);
		return (1);
	}
	if (argc == 1)
	{

	}
	else if (argc == 2)
	{

	}
	else if (argc >= 3)
	{

	}
	else
		write(1, "error", 5);
	
	//스택 프리
}

int*	init_stack(char **argv)
{
	t_node	stack_a;

	stack_a = 
	i = 1;
	while (argv[i])
	{
		check_validation();
	}
	while ()




	return (stack_a);
}


int		check_validation(argv, stack_a)
{
	int		ret; //null vs 0 차이

//1. some arguments aren’t integers / are bigger than an integer
	ret = atoi();

//2. there are duplicates.
	while (stack_a != stack_a->next)
	{
		if (stack_a->item == ret)
			return (NULL);
		stack_a = stack_a->next
	}
	return (ret);
}

split_arg