#include "push_swap.h"

void	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**split;
	int		num;
	int		split_init;

	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(a, NULL, NULL, 0);
		split_init = 1;
		while (*split)
		{
			if (!validate_number(*split) || ft_atoi(*split, &num)
				|| is_duplicate(a, num))
				error_exit(a, NULL, split, split_init);
			add_node(a, num);
			split++;
			split_init = 0;
		}
		free_split(split - (split_init ? 0 : (int)(split - ft_split(argv[i], ' '))));
	}
	index_stack(a);
}

int	validate_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *num)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*(str++) == '-');
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && n > (long)INT_MAX))
			return (-1);
	}
	if (*str)
		return (-1);
	*num = (int)(n * sign);
	return (0);
}

int	is_duplicate(t_stack *a, int num)
{
	t_node	*current;
	int		i;

	if (a->size == 0)
		return (0);
	current = a->head;
	i = 0;
	while (i < a->size)
	{
		if (current->value == num)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}