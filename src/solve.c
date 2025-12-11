/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 10:45:45 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/11 10:15:27 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three(t_stacks *stacks, t_list **operations)
{
	if (check_solved(stacks))
		return ;
	else if (stacks->a->first->rank > stacks->a->first->next->rank && stacks->a->first->rank < stacks->a->last->rank)
		swap_stack(stacks, 'A', "1P", operations);
	else if (stacks->a->first->rank > stacks->a->first->next->rank && stacks->a->first->next->rank > stacks->a->last->rank)
	{
		swap_stack(stacks, 'A', "1P", operations);
		reverse_rotate_stack(stacks, 'A', "1P", operations);
	}
	else if (stacks->a->first->rank > stacks->a->last->rank && stacks->a->first->next->rank < stacks->a->last->rank)
		rotate_stack(stacks, 'A', "1P", operations);
	else
	{
		reverse_rotate_stack(stacks, 'A', "1P", operations);
		if (stacks->a->first->rank > stacks->a->first->next->rank)
			swap_stack(stacks, 'A', "1P", operations);
	}
}

void	solve_up_to_five(t_stacks *stacks, t_list **operations)
{
	int	top_a;

	if (check_ordered_not_sorted(stacks))
		return (rotate_to_pos(stacks, 1, operations));
	while (stacks->a->size > 3 && !check_ordered_not_sorted(stacks))
		push_stack(stacks, "BP", operations);
	if (!check_ordered_not_sorted(stacks))
		solve_three(stacks, operations);
	while (stacks->b->size > 0)
	{
		top_a = required_top(stacks);
		rotate_to_pos(stacks, top_a, operations);
		push_stack(stacks, "AP", operations);
	}
	return (rotate_to_pos(stacks, 1, operations));
}

void	solve_big(t_stacks *stacks, t_list **operations)
{
	t_chunk	chunk;

	chunk.division = DIV_HIGH;
	chunk.location = TOP_A;
	chunk_sorting(stacks, chunk, operations);
}
