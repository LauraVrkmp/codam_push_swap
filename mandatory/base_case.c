/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_case.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/30 12:00:57 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_case_ext(t_stacks *stacks, t_chunk *chunk, t_list **operations, int test_base)
{
	int	to_move;

	to_move = test_base;
	if (!ft_strncmp("BOTTOM_A", chunk->loc, ft_strlen(chunk->loc)))
	{
		while (to_move--)
			reverse_rotate_stack(stacks, 'A', 1, operations);
		if (test_base == 2 && stacks->a->first->rank > stacks->a->first->next->rank)
			swap_stack(stacks, 'B', 1, operations);
	}
	else if (!ft_strncmp("BOTTOM_B", chunk->loc, ft_strlen(chunk->loc)))
	{
		while (to_move--)
			reverse_rotate_stack(stacks, 'B', 1, operations);
		if (test_base == 2 && stacks->b->first->rank < stacks->b->first->next->rank)
			swap_stack(stacks, 'B', 1, operations);
		while (test_base--)
			push_stack(stacks, 'A', operations);
	}
}

void	base_case(t_stacks *stacks, t_chunk *chunk, t_list **operations, int test_base)
{
	if (!ft_strncmp("TOP_A", chunk->loc, ft_strlen(chunk->loc)) && test_base == 2 && stacks->a->first->rank > stacks->a->first->next->rank)
		swap_stack(stacks, 'A', 1, operations);
	else if (!ft_strncmp("TOP_B", chunk->loc, ft_strlen(chunk->loc)))
	{
		if (test_base == 2 && stacks->b->first->rank < stacks->b->first->next->rank)
			swap_stack(stacks, 'B', 1, operations);
		while (test_base--)
			push_stack(stacks, 'A', operations);
	}
	else
		base_case_ext(stacks, chunk, operations, test_base);
}
