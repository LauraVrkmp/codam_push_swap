/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   position_length.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 19:06:56 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 18:05:04 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
