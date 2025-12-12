/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_case.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 20:20:33 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_case_ext(t_stacks *stacks, t_chunk chunk, \
t_list **operations, int test_base)
{
	if (chunk.location == BOTTOM_A)
	{
		while (stacks->a->first->rank != chunk.high_max)
		{
			reverse_rotate_stack(stacks, 'A', "1P", operations);
			if (stacks->a->first->rank != chunk.high_max)
				push_stack(stacks, "BP", operations);
		}
		if (test_base == 2 && \
stacks->a->first->rank - 1 == stacks->a->first->next->rank)
			swap_stack(stacks, 'A', "1P", operations);
	}
	else if (chunk.location == BOTTOM_B)
	{
		while (stacks->b->size > 1 && stacks->b->first->rank != chunk.low_min)
			reverse_rotate_stack(stacks, 'B', "1P", operations);
		if (test_base == 2 && \
stacks->b->first->rank + 1 == stacks->b->first->next->rank)
			swap_stack(stacks, 'B', "1P", operations);
		while (stacks->b->first && \
stacks->b->first->rank + 1 == stacks->a->first->rank)
			push_stack(stacks, "AP", operations);
	}
}

static void	base_case_top_b(t_stacks *stacks, t_chunk chunk, \
t_list **operations, int test_base)
{
	if (test_base == 2 && \
stacks->b->first->rank + 1 == stacks->b->first->next->rank)
		swap_stack(stacks, 'B', "1P", operations);
	while (test_base--)
		push_stack(stacks, "AP", operations);
	while (chunk.low_min + 1 == stacks->a->first->rank && \
stacks->b->first->rank != chunk.low_min)
		rotate_stack(stacks, 'B', "1P", operations);
	if (stacks->b->first && \
stacks->b->first->rank + 1 == stacks->a->first->rank)
		push_stack(stacks, "AP", operations);
}

void	base_case(t_stacks *stacks, t_chunk chunk, \
t_list **operations, int test_base)
{
	if (chunk.low_min >= stacks->smallest_sorted && \
stacks->smallest_sorted != stacks->total && \
chunk.iteration >= calc_iteration(stacks->smallest_sorted, stacks->total))
		return ;
	if (stacks->a->size == 3 && !section_sorted(stacks, \
stacks->a->first->rank, stacks->total, stacks->a->size - 1))
		solve_three(stacks, operations);
	else if (chunk.location == TOP_A && \
stacks->a->first->rank - 1 == stacks->a->first->next->rank)
		swap_stack(stacks, 'A', "1P", operations);
	else if (chunk.location == TOP_B && stacks->b->size > 0)
		base_case_top_b(stacks, chunk, operations, test_base);
	else
		base_case_ext(stacks, chunk, operations, test_base);
	stacks->smallest_sorted = find_smallest_sorted(stacks);
}

int	check_solved(t_stacks *stacks)
{
	int		i;
	t_item	*current;

	i = 0;
	current = stacks->a->first;
	if (stacks->b->size != 0)
		return (0);
	while (i < stacks->a->size)
	{
		if (current->rank != i + 1)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
