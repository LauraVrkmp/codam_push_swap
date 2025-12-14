/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 17:53:30 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/14 17:59:17 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_item(t_stack *stack, t_item *item)
{
	t_item	*before;

	if (stack->first == NULL)
	{
		item->next = item;
		item->prev = item;
		stack->first = item;
		stack->last = item;
	}
	else
	{
		before = stack->last;
		item->prev = before;
		item->next = stack->first;
		before->next = item;
		stack->first->prev = item;
		stack->last = item;
	}
}

static void	create_item(t_stacks *stacks, long long number, int position)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (item == NULL)
		init_exit("Malloc failed", stacks, NULL);
	item->number = number;
	item->position = position;
	item->rank = -1;
	insert_item(stacks->a, item);
	stacks->a->size++;
}

static int	parse_loop(char **arguments, int (*i_j_count)[3], t_stacks *stacks)
{
	int			start_numb;
	long long	number;

	start_numb = (*i_j_count)[1];
	while (arguments[(*i_j_count)[0]][(*i_j_count)[1]] && \
arguments[(*i_j_count)[0]][(*i_j_count)[1]] != ' ')
	{
		if (((*i_j_count)[1] == start_numb && \
(arguments[(*i_j_count)[0]][(*i_j_count)[1]] == '-' || \
arguments[(*i_j_count)[0]][(*i_j_count)[1]] == '+') && \
!ft_isdigit(arguments[(*i_j_count)[0]][(*i_j_count)[1] + 1])) || \
(arguments[(*i_j_count)[0]][(*i_j_count)[1]] != '-' && \
arguments[(*i_j_count)[0]][(*i_j_count)[1]] != '+' && \
!ft_isdigit(arguments[(*i_j_count)[0]][(*i_j_count)[1]])))
			init_exit("Error", stacks, NULL);
		(*i_j_count)[1]++;
	}
	(*i_j_count)[1] = start_numb;
	number = ft_atoi_long_long(arguments[(*i_j_count)[0]] + start_numb);
	if (number > INT_MAX || number < INT_MIN)
		init_exit("Error", stacks, NULL);
	create_item(stacks, number, (*i_j_count)[2]++);
	(*i_j_count)[1] += long_long_length(number) + \
(arguments[(*i_j_count)[0]][start_numb] == '+');
	return ((*i_j_count)[1]);
}

static void	parse_args(int amount, char **arguments, t_stacks *stacks)
{
	int				i_j_count[3];

	i_j_count[0] = 1;
	i_j_count[2] = 1;
	while (i_j_count[0] < amount)
	{
		i_j_count[1] = 0;
		if (i_j_count[1] == 0 && arguments[i_j_count[0]][i_j_count[1]] == '\0')
			init_exit("Error", stacks, NULL);
		while (i_j_count[1] < (int)ft_strlen(arguments[i_j_count[0]]))
		{
			while (arguments[i_j_count[0]][i_j_count[1]] == ' ')
				i_j_count[1]++;
			if (arguments[i_j_count[0]][i_j_count[1]] == '\0')
				break ;
			i_j_count[1] = parse_loop(arguments, &i_j_count, stacks);
		}
		i_j_count[0]++;
	}
}

void	input_check_create(int amount, char **arguments, \
t_stacks *stacks)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	if (stack_a == NULL)
		init_exit("Malloc failed", stacks, NULL);
	stack_a->size = 0;
	stack_a->id = 'A';
	stack_a->first = NULL;
	stack_a->last = NULL;
	stacks->a = stack_a;
	stack_b = malloc(sizeof(t_stack));
	if (stack_b == NULL)
		init_exit("Malloc failed", stacks, NULL);
	stack_b->size = 0;
	stack_b->id = 'B';
	stack_b->first = NULL;
	stack_b->last = NULL;
	stacks->b = stack_b;
	parse_args(amount, arguments, stacks);
	stacks->total = stacks->a->size;
	stacks->smallest_sorted = stacks->a->size;
}
