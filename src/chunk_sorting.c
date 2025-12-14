/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/14 19:45:56 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top_a(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	while (max_op < (chunk.high_max - chunk.low_min + 1) && \
stacks->a->size > 2 && chunk.low_min != chunk.high_max)
	{
		if (rotate_to_order(stacks, operations))
		{
			stacks->smallest_sorted = find_smallest_sorted(stacks);
			return ;
		}
		if (chunk.low_min >= stacks->smallest_sorted && \
stacks->smallest_sorted != stacks->total)
			return ;
		if (section_sorted(stacks, stacks->a->first->rank, stacks->total, \
stacks->a->size - 1) && chunk.iteration >= calc_iteration(\
stacks->a->first->rank, stacks->total))
			return ;
		move_from_top_a_ext(stacks, chunk, operations, &max_op);
	}
}

void	move_from_top_b(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	while (max_op < (chunk.high_max - chunk.low_min + 1) && stacks->b->size > 0)
	{
		/* rotate_to_order(stacks, operations);
		if (stacks->a->last->rank + 1 == stacks->a->last->prev->rank && \
stacks->a->last->rank + 2 == stacks->a->first->rank && section_sorted(\
stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1))
		{
			reverse_rotate_stack(stacks, 'A', "1P", operations);
			reverse_rotate_stack(stacks, 'A', "1P", operations);
		}
		else if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && \
stacks->a->first->rank + 1 == stacks->a->first->next->next->rank && \
section_sorted(stacks, stacks->a->first->next->next->rank, stacks->total, \
stacks->a->size - 1))
			swap_stack(stacks, 'A', "1P", operations);
		else
			move_from_top_b_ext(stacks, chunk, operations, &max_op); */
		if ((stacks->b->first->rank >= chunk.high_min && \
	stacks->b->first->rank <= chunk.high_max) || \
	(stacks->b->first->rank + 1 == stacks->a->first->rank && section_sorted(\
	stacks, stacks->a->first->rank, stacks->total, stacks->a->size - 1)))
			push_stack(stacks, "AP", operations);
		else if (stacks->b->first->rank >= chunk.mid_min && \
	stacks->b->first->rank <= chunk.mid_max)
		{
			push_stack(stacks, "AP", operations);
			if (!section_sorted(stacks, stacks->a->first->rank, \
	stacks->total, stacks->a->size - 1))
				rotate_stack(stacks, 'A', "1P", operations);
		}
		else if (stacks->b->first->rank >= chunk.low_min && \
	stacks->b->first->rank <= chunk.low_max && stacks->b->size > 2)
			rotate_stack(stacks, 'B', "1P", operations);
		max_op++;
	}
}

void	move_from_bottom_a(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	if (rotate_to_order(stacks, operations))
		return ;
	if (chunk.low_min >= stacks->smallest_sorted && \
stacks->smallest_sorted != stacks->total)
		return ;
	if (section_sorted(stacks, stacks->a->first->rank, stacks->total, \
stacks->a->size - 1) && chunk.iteration >= calc_iteration(\
stacks->a->first->rank, stacks->total))
		return ;
	while (stacks->a->last->rank >= chunk.low_min && \
stacks->a->last->rank <= chunk.high_max)
	{
		reverse_rotate_stack(stacks, 'A', "1P", operations);
		if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && \
section_sorted(stacks, stacks->a->first->next->next->rank, 0, \
stacks->total - chunk.low_min - 1))
			swap_stack(stacks, 'A', "1P", operations);
		else
			move_from_bottom_a_ext(stacks, chunk, operations);
		stacks->smallest_sorted = find_smallest_sorted(stacks);
	}
}

void	move_from_bottom_b(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	while (max_op < (chunk.high_max - chunk.low_min + 1) && \
stacks->b->last->rank >= chunk.low_min && \
stacks->b->last->rank <= chunk.high_max && stacks->b->size > 2)
	{
		if (rotate_to_order(stacks, operations))
			return ;
		reverse_rotate_stack(stacks, 'B', "1P", operations);
		if (stacks->b->first->rank >= chunk.mid_min)
		{
			push_stack(stacks, "AP", operations);
			if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && \
stacks->a->first->rank + 1 == stacks->a->first->next->next->rank && \
section_sorted(stacks, stacks->a->first->next->next->rank, stacks->total, \
stacks->a->size - 1))
				swap_stack(stacks, 'A', "1P", operations);
			else if (stacks->a->first->rank <= chunk.mid_max && \
chunk.mid_max != chunk.high_max)
				rotate_stack(stacks, 'A', "1P", operations);
		}
		stacks->smallest_sorted = find_smallest_sorted(stacks);
		max_op++;
	}
}
