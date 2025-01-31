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

	first = a->head->index;
	second = a->head->next->index;
	third = a->head->prev->index;
	if ((first > second && second < third && first < third)
		|| (first > second && second > third)
		|| (first < second && second > third && first < third))
		swap(a, "sa");
	if (!is_sorted(a))
		reverse_rotate(a, "rra");
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = get_max_bits(a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < a->size)
		{
			if ((a->head->index >> i) & 1)
				rotate(a, "ra");
			else
				push(a, b, "pb");
		}
		while (b->size > 0)
			push(b, a, "pa");
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pushed;

	pushed = 0;
	while (a->size > 3 && pushed < 2)
	{
		if (a->head->index == 0 || a->head->index == 1)
		{
			push(a, b, "pb");
			pushed++;
		}
		else
			rotate(a, "ra");
	}
	sort_three(a);
	while (b->size > 0)
	{
		push(b, a, "pa");
		if (a->head->index == 1)
			swap(a, "sa");
	}
}