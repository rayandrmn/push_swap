#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (argc > 1)
	{
		parse_args(argc, argv, &a);
		if (!is_sorted(&a))
			sort_stack(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}