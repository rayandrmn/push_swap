#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

/* Parsing */
void	parse_args(int argc, char **argv, t_stack *a);
int		validate_number(const char *str);
int		ft_atoi(const char *str, int *num);
int		is_duplicate(t_stack *a, int num);
void	index_stack(t_stack *a);

/* Operations */
void	swap(t_stack *s, char *op);
void	push(t_stack *src, t_stack *dst, char *op);
void	rotate(t_stack *s, char *op);
void	reverse_rotate(t_stack *s, char *op);
void	double_op(t_stack *a, t_stack *b, void (*op)(t_stack*, char*), char *n);

/* Sorting */
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

/* Utils */
void	add_node(t_stack *stack, int value);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *a);
t_node	*find_min(t_stack *s);
void	error_exit(t_stack *a, t_stack *b, char **split, int split_init);
char	**ft_split(const char *s, char c);
void	free_split(char **split);
void	sort_small(t_stack *a, t_stack *b);
int		get_max_bits(t_stack *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	sort_five(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *s, char *op);
void	rotate(t_stack *s, char *op);
#endif