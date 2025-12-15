/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:37:59 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/15 15:32:42 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	moving_and_recursion(t_stacks *stacks, t_chunk chunk, \
t_list **operations)
{
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

void	chunk_sorting(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	test_base;

	if (chunk.iteration == 0)
		calc_chunk(&chunk, 1, stacks->total);
	else if (chunk.division == DIV_HIGH)
		calc_chunk(&chunk, chunk.high_min, chunk.high_max);
	else if (chunk.division == DIV_MID)
		calc_chunk(&chunk, chunk.mid_min, chunk.mid_max);
	else
		calc_chunk(&chunk, chunk.low_min, chunk.low_max);
	chunk.iteration++;
	if (chunk.iteration != 1)
		chunk.location = determine_location(stacks, chunk);
	test_base = test_chunk_size(stacks, chunk);
	if (chunk.high_max - chunk.low_min == 0 || check_solved(stacks) || \
(stacks->a->size <= 3 && !section_sorted(stacks, stacks->total - \
stacks->a->size + 1, stacks->total, stacks->a->size - 1)))
		return (base_case(stacks, chunk, operations, test_base));
	moving_and_recursion(stacks, chunk, operations);
}
