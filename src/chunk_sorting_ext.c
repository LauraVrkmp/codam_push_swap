/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sorting_ext.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/12 20:22:28 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 20:35:05 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top_a_ext(t_stacks *stacks, t_chunk chunk, \
t_list **operations, int *max_op)
{
	if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && \
stacks->a->first->rank + 1 == stacks->a->first->next->next->rank && \
section_sorted(stacks, stacks->a->first->next->next->rank, stacks->total, \
stacks->a->size - 1))
	{
		swap_stack(stacks, 'A', "1P", operations);
		return ;
	}
	else if ((stacks->a->first->rank >= chunk.high_min && \
stacks->a->first->rank <= chunk.high_max && !section_sorted(stacks, \
stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1)) || \
stacks->a->first->rank >= stacks->total - 2)
		rotate_stack(stacks, 'A', "1P", operations);
	else if (stacks->a->first->rank <= chunk.mid_max && \
!section_sorted(stacks, stacks->a->first->rank, 0, stacks->total - \
chunk.low_min + 1))
	{
		push_stack(stacks, "BP", operations);
		if (stacks->b->first->rank <= chunk.low_max && \
stacks->b->size > 1)
			rotate_stack(stacks, 'B', "1P", operations);
	}
	stacks->smallest_sorted = find_smallest_sorted(stacks);
	(*max_op)++;
}

static void	move_from_top_b_double_ext(t_stacks *stacks, t_chunk chunk, \
t_list **operations)
{
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
}

void	move_from_top_b_ext(t_stacks *stacks, t_chunk chunk, \
t_list **operations, int *max_op)
{
	if (stacks->b->size == 2 && stacks->b->first->rank == 1 && \
stacks->b->first->next->rank == 2)
	{
		swap_stack(stacks, 'B', "1P", operations);
		while (stacks->b->size)
			push_stack(stacks, "AP", operations);
	}
	else if (stacks->b->first->rank + 2 == stacks->a->first->rank && \
stacks->b->first->next->rank + 1 == stacks->a->first->rank && section_sorted(\
stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1))
	{
		push_stack(stacks, "AP", operations);
		push_stack(stacks, "AP", operations);
		swap_stack(stacks, 'A', "1P", operations);
		(*max_op)++;
	}
	else
		move_from_top_b_double_ext(stacks, chunk, operations);
	stacks->smallest_sorted = find_smallest_sorted(stacks);
	(*max_op)++;
}

void	move_from_bottom_a_ext(t_stacks *stacks, t_chunk chunk, \
t_list **operations)
{
	if (stacks->a->first->rank + 1 == stacks->a->last->rank && \
stacks->a->last->rank + 1 == stacks->a->first->next->rank && section_sorted(\
stacks, stacks->a->first->next->rank, 0, stacks->total - chunk.low_min))
	{
		reverse_rotate_stack(stacks, 'A', "1P", operations);
		swap_stack(stacks, 'A', "1P", operations);
	}
	else if (!section_sorted(stacks, stacks->a->first->rank, 0, \
stacks->total - chunk.low_min + 1) \
&& stacks->a->first->rank >= chunk.low_min && \
stacks->a->first->rank <= chunk.mid_max && chunk.low_min + 1 < chunk.high_max)
	{
		push_stack(stacks, "BP", operations);
		if (stacks->a->first->rank >= chunk.low_min && \
stacks->b->first->rank <= chunk.low_max)
			rotate_stack(stacks, 'B', "1P", operations);
	}
}
