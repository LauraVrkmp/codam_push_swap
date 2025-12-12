/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 17:53:30 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 14:04:12 by laveerka      ########   odam.nl         */
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

static void	parse_args(int amount, char **arguments, t_stacks *stacks)
{
	int				i;
	size_t			j;
	size_t			start_numb;
	int				count;
	long long		number;

	i = 1;
	count = 1;
	while (i < amount)
	{
		j = 0;
		if (j == 0 && arguments[i][j] == '\0')
			init_exit("Error", stacks, NULL);
		while (j < ft_strlen(arguments[i]))
		{
			while (arguments[i][j] == ' ')
				j++;
			if (arguments[i][j] == '\0')
				break ;
			start_numb = j;
			while (arguments[i][j] && arguments[i][j] != ' ')
			{
				if ((j == start_numb && (arguments[i][j] == '-' || arguments[i][j] == '+') && !ft_isdigit(arguments[i][j + 1])) || (arguments[i][j] != '-' && arguments[i][j] != '+' && !ft_isdigit(arguments[i][j])))
					init_exit("Error", stacks, NULL);
				j++;
			}
			j = start_numb;
			number = ft_atoi_long_long(arguments[i] + start_numb);
			if (number > INT_MAX || number < INT_MIN)
				init_exit("Error", stacks, NULL);
			create_item(stacks, number, count++);		
			j += long_long_length(number) + (arguments[i][start_numb] == '+');	
		}
		i++;
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

void	check_dup(t_stacks *stacks)
{
	int		i;
	int		j;
	t_item	*current;
	t_item	*compare;

	i = 1;
	current = stacks->a->first;
	while (i < stacks->a->size)
	{
		j = i;
		compare = current->next;
		while (j < stacks->a->size)
		{
			if (current->number == compare->number)
				init_exit("Error", stacks, NULL);
			compare = compare->next;
			j++;
		}
		current = current->next;
		i++;
	}
}
