#include "push_swap.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	error_exit(t_stack *a, t_stack *b, char **split, int split_init)
{
	if (split && split_init)
		free_split(split - (split - ft_split(*split, ' ')));
	else if (split)
		free_split(split);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	add_node(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit(stack, NULL, NULL, 0);
	new->value = value;
	new->index = -1;
	if (stack->size++ == 0)
	{
		new->next = new;
		new->prev = new;
		stack->head = new;
	}
	else
	{
		new->next = stack->head;
		new->prev = stack->head->prev;
		stack->head->prev->next = new;
		stack->head->prev = new;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack->head)
		return ;
	current = stack->head;
	next = current->next;
	while (stack->size--)
	{
		free(current);
		current = next;
		if (stack->size > 0)
			next = next->next;
	}
	stack->head = NULL;
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	current = a->head;
	while (1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		if (current == a->head->prev)
			break ;
	}
	return (1);
}

