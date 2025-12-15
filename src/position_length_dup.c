/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   position_length_dup.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 19:06:56 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/15 15:39:49 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	position_update(t_stack *stack, char update)
{
	int		pos;
	int		i;
	t_item	*item;

	pos = 1;
	if (update == 'F')
	{
		i = 0;
		item = stack->first;
		while (i < stack->size)
		{
			item->position = pos;
			item = item->next;
			pos++;
			i++;
		}
	}
	else if (update == 'S')
	{
		stack->first->position = 1;
		stack->first->next->position = 2;
	}
}

int	long_long_length(long long number)
{
	int	length;

	length = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}
