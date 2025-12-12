/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:37:59 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 17:59:17 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_chunk(t_chunk *chunk, int start, int end)
{
	chunk->low_min = start;
	chunk->low_max = start + (end - start + 1) / 3 + \
((end - start + 1) % 3 > 0) - 1;
	chunk->mid_min = chunk->low_max + (chunk->low_max < end);
	chunk->mid_max = chunk->low_max + (end - start + 1) / 3 + \
((end - start + 1) % 3 > 1);
	chunk->high_min = chunk->mid_max + (chunk->mid_max < end);
	chunk->high_max = end;
}

static int	number_in_chunk(t_chunk chunk, t_stack *item_stack)
{
	t_item	*item;
	int		save;
	int		i;

	i = 0;
	if (chunk.location == TOP_A || chunk.location == TOP_B)
	{
		item = item_stack->first;
		save = item->rank;
		while (item->rank >= chunk.low_min && \
item->rank <= chunk.high_max)
		{
			item = item->next;
			i++;
			if (item->rank == save)
				break ;
		}
	}
	else
	{
		item = item_stack->last;
		save = item->rank;
		while (item->rank >= chunk.low_min && \
item->rank <= chunk.high_max)
		{
			item = item->prev;
			i++;
			if (item->rank == save)
				break ;
		}
	}
	return (i);
}

int	test_chunk_size(t_stacks *stacks, t_chunk chunk)
{
	t_stack	*item_stack;

	if (chunk.location == TOP_A || chunk.location == BOTTOM_A)
		item_stack = stacks->a;
	else
		item_stack = stacks->b;
	if (item_stack->size > 0)
		return (number_in_chunk(chunk, item_stack));
	return (0);
}

static t_loc	determine_location(t_stacks *stacks, t_chunk chunk)
{
	int		rot_required[4];
	t_loc	min_rot;

	rot_required[0] = rotation_required_location(stacks->a, TOP_A, chunk);
	rot_required[1] = rotation_required_location(stacks->a, BOTTOM_A, chunk);
	rot_required[2] = rotation_required_location(stacks->b, TOP_B, chunk);
	rot_required[3] = rotation_required_location(stacks->b, BOTTOM_B, chunk);
	min_rot = minimum_rotation(stacks, rot_required, chunk);
	return (min_rot);
}

void	chunk_sorting(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	test_base;

	if (stacks->a->size == stacks->total)
	{
		calc_chunk(&chunk, 1, stacks->total);
		chunk.iteration = 1;
	}
	else
	{
		if (chunk.division == DIV_HIGH)
			calc_chunk(&chunk, chunk.high_min, chunk.high_max);
		else if (chunk.division == DIV_MID)
			calc_chunk(&chunk, chunk.mid_min, chunk.mid_max);
		else
			calc_chunk(&chunk, chunk.low_min, chunk.low_max);
		chunk.iteration++;
	}
	if (stacks->a->size == stacks->total)
		chunk.location = TOP_A;
	else
		chunk.location = determine_location(stacks, chunk);
	test_base = test_chunk_size(stacks, chunk);
	if (chunk.high_max - chunk.low_min == 0 || check_solved(stacks) || \
(stacks->a->size <= 3 && !section_sorted(stacks, stacks->total - \
stacks->a->size + 1, stacks->total, stacks->a->size - 1)))
		return (base_case(stacks, chunk, operations, test_base));
	if (chunk.location == TOP_A)
		move_from_top_a(stacks, chunk, operations);
	else if (chunk.location == TOP_B)
		move_from_top_b(stacks, chunk, operations);
	else if (chunk.location == BOTTOM_A)
		move_from_bottom_a(stacks, chunk, operations);
	else
		move_from_bottom_b(stacks, chunk, operations);
	chunk.division = DIV_HIGH;
	chunk_sorting(stacks, chunk, operations);
	chunk.division = DIV_MID;
	chunk_sorting(stacks, chunk, operations);
	chunk.division = DIV_LOW;
	chunk_sorting(stacks, chunk, operations);
}
