/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   locations_iterations.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/09 11:06:27 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 18:01:11 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_loc	cheapest_rot(t_stacks *stacks, int loc, int i, t_chunk chunk)
{
	if (loc == TOP_A && i == TOP_B)
	{
		if (stacks->a->first->rank == chunk.high_max && section_sorted(stacks, \
stacks->a->first->rank, stacks->total, stacks->a->size - 1))
			return (TOP_B);
	}
	if (loc == TOP_B && i == BOTTOM_B)
	{
		if (stacks->b->last->rank >= chunk.high_min && \
stacks->b->last->rank <= chunk.high_max && \
stacks->b->size != chunk.high_max - chunk.low_min + 1)
			return (BOTTOM_B);
	}
	return (loc);
}

t_loc	minimum_rotation(t_stacks *stacks, int *rot_required, t_chunk chunk)
{
	int		smallest;
	int		i;
	t_loc	loc;

	smallest = INT_MAX;
	i = 0;
	while (i < 4)
	{
		if (rot_required[i] == smallest)
			loc = cheapest_rot(stacks, loc, i, chunk);
		else if (rot_required[i] < smallest && rot_required[i] != -1)
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
	t_item	*current;
	int		stack_size_i;
	int		i;

	stack_size_i = 0;
	current = NULL;
	i = 1;
	if (loc == TOP_A || loc == TOP_B)
	{
		if (stack->first)
		{
			current = stack->first;
			while ((current->rank < chunk.low_min || \
current->rank > chunk.high_max) && stack_size_i++ < stack->size)
			{
				current = current->next;
				i++;
			}
		}
	}
	else
	{
		if (stack->first)
		{
			current = stack->last;
			while ((current->rank < chunk.low_min || \
current->rank > chunk.high_max) && stack_size_i++ < stack->size)
			{
				current = current->prev;
				i++;
			}
		}
	}
	if (current)
	{
		return (i);
	}
	return (-1);
}

int	calc_iteration(int first_a, int total)
{
	t_chunk	iter_chunk;
	int		iteration;

	iteration = 1;
	calc_chunk(&iter_chunk, 1, total);
	while (first_a != iter_chunk.low_min && \
iter_chunk.low_min != iter_chunk.high_max)
	{
		if (first_a >= iter_chunk.low_min && first_a <= iter_chunk.low_max)
		{
			iteration++;
			calc_chunk(&iter_chunk, iter_chunk.low_min, iter_chunk.low_max);
		}
		else if (first_a >= iter_chunk.mid_min && first_a <= iter_chunk.mid_max)
		{
			iteration++;
			calc_chunk(&iter_chunk, iter_chunk.mid_min, iter_chunk.mid_max);
		}
		else
		{
			iteration++;
			calc_chunk(&iter_chunk, iter_chunk.high_min, iter_chunk.high_max);
		}
	}
	return (iteration);
}
