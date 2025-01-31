#include "push_swap.h"

void	index_stack(t_stack *a)
{
	t_node	*current;
	t_node	*min;
	int		index;
	int		i;

	index = 0;
	while (index < a->size)
	{
		min = NULL;
		current = a->head;
		i = -1;
		while (++i < a->size)
		{
			if (current->index == -1 && (!min || current->value < min->value))
				min = current;
			current = current->next;
		}
		min->index = index++;
	}
}

t_node	*find_min(t_stack *s)
{
	t_node	*current;
	t_node	*min;

	current = s->head;
	min = current;
	while (1)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
		if (current == s->head)
			break ;
	}
	return (min);
}

int	get_max_bits(t_stack *s)
{
	int	max_num;
	int	bits;

	max_num = s->size - 1;
	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}