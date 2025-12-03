/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   locations.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/03 11:53:55 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/03 12:13:45 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_loc	minimum_rotation(int *rot_required)
{
	int		smallest;
	int		i;
	t_loc	loc;

	smallest = INT_MAX;
	i = 0;
	while (i < 4)
	{
		if (rot_required[i] < smallest)
		{
			smallest = rot_required[i];
			loc = i;
		}
		i++;
	}
	return (loc);
}

int	rotation_required_location(t_stack *stack, int loc, t_chunk chunk)
{
	int		pos_one;
	t_item	*current;
	int		stack_size_i;

	stack_size_i = 0;
	if (loc == TOP_A || loc == TOP_B)
	{
		current = stack->first;
		while ((current->rank < chunk.low_min || current->rank > chunk.high_max) && stack_size_i++ < stack->size)
			current = current->next;
	}
	else
	{
		current = stack->last;
		while ((current->rank < chunk.low_min || current->rank > chunk.high_max) && stack_size_i++ < stack->size)
			current = current->prev;
	}
	pos_one = current->position;
	if (pos_one <= (stack->size / 2 + 1))
		return (pos_one - 1);
	else
		return (-(stack->size - pos_one + 1));
}
