#include "push_swap.h"

void	index_stack(t_stack *a)
{
	t_node	*nodes[a->size];
	t_node	*current;
	int		i;

	current = a->head;
	i = -1;
	while (++i < a->size)
	{
		nodes[i] = current;
		current = current->next;
	}
	qsort(nodes, a->size, sizeof(t_node *), compare_nodes);
	i = -1;
	while (++i < a->size)
		nodes[i]->index = i;
}

static int	compare_nodes(const void *a, const void *b)
{
	t_node	*node_a = *(t_node **)a;
	t_node	*node_b = *(t_node **)b;
	return (node_a->value - node_b->value);
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

void	push_chunk(t_stack *a, t_stack *b, int min_range, int max_range)
{
	int	pushed;
	int	rotations;

	pushed = 0;
	rotations = 0;
	while (pushed < (max_range - min_range))
	{
		if (a->head->index >= min_range && a->head->index < max_range)
		{
			push(a, b, "pb\n");
			pushed++;
		}
		else
		{
			rotate(a, "ra\n");
			rotations++;
		}
		if (rotations > a->size / 2 && pushed < max_range / 2)
		{
			reverse_rotate(a, "rra\n");
			rotations--;
		}
	}
}

void	smart_rotate_and_push(t_stack *a, t_stack *b)
{
	t_node	*max;
	int		position;
	int		moves;

	max = find_max(b);
	position = get_node_position(b, max);
	moves = (position > b->size / 2) ? b->size - position : position;
	while (b->head != max)
	{
		if (position > b->size / 2)
			reverse_rotate(b, "rrb\n");
		else
			rotate(b, "rb\n");
	}
	push(b, a, "pa\n");
}