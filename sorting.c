#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap(a, "sa");
	else if (a->size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->prev->value;

	if (first > second && second < third && first < third)
		swap(a, "sa\n");
	else if (first > second && second > third)
	{
		swap(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
	else if (first > second && second < third)
		rotate(a, "ra\n");
	else if (first < second && second > third && first < third)
	{
		reverse_rotate(a, "rra\n");
		swap(a, "sa\n");
	}
	else if (first < second && second > third)
		reverse_rotate(a, "rra\n");
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = get_max_bits(a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < a->size)
		{
			num = a->head->index;
			if ((num >> i) & 1)
				rotate(a, "ra\n");
			else
				push(a, b, "pb\n");
		}
		while (b->size > 0)
			push(b, a, "pa\n");
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->head->index == 0 || a->head->index == 1)
			push(a, b, "pb\n");
		else
			rotate(a, "ra\n");
	}
	sort_three(a);
	while (b->size > 0)
	{
		push(b, a, "pa\n");
		if (a->head->value > a->head->next->value)
			swap(a, "sa\n");
	}
}