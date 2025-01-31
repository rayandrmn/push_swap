#include "push_swap.h"

void	swap(t_stack *s, char *op)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->head->value;
	s->head->value = s->head->next->value;
	s->head->next->value = tmp;
	if (op)
		printf("%s\n", op);
}

void	push(t_stack *src, t_stack *dst, char *op)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	tmp = src->head;
	src->head = (src->size == 1) ? NULL : src->head->next;
	if (--src->size > 0)
	{
		src->head->prev = tmp->prev;
		tmp->prev->next = src->head;
	}
	if (dst->size++ == 0)
	{
		dst->head = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = dst->head;
		tmp->prev = dst->head->prev;
		dst->head->prev->next = tmp;
		dst->head->prev = tmp;
		dst->head = tmp;
	}
	if (op)
		printf("%s\n", op);
}

void	rotate(t_stack *s, char *op)
{
	if (s->size < 2)
		return ;
	s->head = s->head->next;
	if (op)
		write(1, op, ft_strlen(op));
}

void	reverse_rotate(t_stack *s, char *op)
{
	if (s->size < 2)
		return ;
	s->head = s->head->prev;
	if (op)
		write(1, op, ft_strlen(op));
}