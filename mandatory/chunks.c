/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:37:59 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/07 06:05:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_chunk(t_chunk *chunk, int start, int end)
{
	chunk->low_min = start;
	chunk->low_max = start + (end - start + 1) / 3 + ((end - start + 1) % 3 > 0) - 1;
	chunk->mid_min = chunk->low_max + (chunk->low_max < end);
	chunk->mid_max = chunk->low_max + (end - start + 1) / 3 + ((end - start + 1) % 3 > 1);
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
		while (item->rank >= chunk.low_min && item->rank <= chunk.high_max)
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
		while (item->rank >= chunk.low_min && item->rank <= chunk.high_max)
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
	//ft_printf("location TOP_A min: %d\n", rot_required[0]);
	rot_required[1] = rotation_required_location(stacks->a, BOTTOM_A, chunk);
	//ft_printf("location BOTTOM_A min: %d\n", rot_required[1]);
	rot_required[2] = rotation_required_location(stacks->b, TOP_B, chunk);
	//ft_printf("location TOP_B min: %d\n", rot_required[2]);
	rot_required[3] = rotation_required_location(stacks->b, BOTTOM_B, chunk);
	//ft_printf("location BOTTOM_B min: %d\n", rot_required[3]);
	min_rot = minimum_rotation(stacks, rot_required, chunk);
	return (min_rot);
}

void	chunk_sorting(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	test_base;

	if (stacks->a->size == stacks->total)
		calc_chunk(&chunk, 1, stacks->total);
	test_base = test_chunk_size(stacks, chunk);
	if (chunk.high_max - chunk.low_min == 0 || check_solved(stacks) || (test_base == 3 && stacks->a->size == 3 && !section_sorted(stacks, stacks->a->first->rank, stacks->total, stacks->a->size - 1)))
		return (base_case(stacks, chunk, operations, test_base));
	if (stacks->a->size != stacks->total)
	{
		if (chunk.division == DIV_HIGH)
			calc_chunk(&chunk, chunk.high_min, chunk.high_max);
		else if (chunk.division == DIV_MID)
			calc_chunk(&chunk, chunk.mid_min, chunk.mid_max);
		else
			calc_chunk(&chunk, chunk.low_min, chunk.low_max);
	}
	/* ft_printf("min: %d, max: %d\n", chunk.low_min, chunk.low_max);
	ft_printf("min: %d, max: %d\n", chunk.mid_min, chunk.mid_max);
	ft_printf("min: %d, max: %d\n", chunk.high_min, chunk.high_max); */
	if (stacks->a->size == stacks->total)
		chunk.location = TOP_A;
	else
		chunk.location = determine_location(stacks, chunk);
	/* if (chunk.location == TOP_A)
		ft_printf("TOP_A\n");
	else if (chunk.location == BOTTOM_A)
		ft_printf("BOTTOM_A\n");
	else if (chunk.location == TOP_B)
		ft_printf("TOP_B\n");
	else
		ft_printf("BOTTOM_B\n"); */
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
