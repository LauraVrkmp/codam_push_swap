/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 10:45:45 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/29 20:57:21 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three(t_stacks *stacks, t_list **operations)
{
	if (check_solved(stacks))
		return ;
	else if (stacks->a->first->rank > stacks->a->first->next->rank && stacks->a->first->rank < stacks->a->last->rank)
		swap_stack(stacks, 'A', 1, operations);
	else if (stacks->a->first->rank > stacks->a->first->next->rank && stacks->a->first->next->rank > stacks->a->last->rank)
	{
		swap_stack(stacks, 'A', 1, operations);
		reverse_rotate_stack(stacks, 'A', 1, operations);
	}
	else if (stacks->a->first->rank > stacks->a->last->rank && stacks->a->first->next->rank < stacks->a->last->rank)
		rotate_stack(stacks, 'A', 1, operations);
	else if (stacks->a->first->rank < stacks->a->first->next->rank && stacks->a->first->next->rank < stacks->a->last->rank)
	{
		swap_stack(stacks, 'A', 1, operations);
		rotate_stack(stacks, 'A', 1, operations);
	}
	else
		reverse_rotate_stack(stacks, 'A', 1, operations);
}

void	solve_up_to_five(t_stacks *stacks, t_list **operations)
{
	int	top_a;

	if (check_ordered_not_sorted(stacks))
		return (rotate_to_pos(stacks, 1, operations));
	while (stacks->a->size > 3 && !check_ordered_not_sorted(stacks))
		push_stack(stacks, 'B', operations);
	if (!check_ordered_not_sorted(stacks))
		solve_three(stacks, operations);
	while (stacks->b->size > 0)
	{
		top_a = required_top(stacks);
		rotate_to_pos(stacks, top_a, operations);
		push_stack(stacks, 'A', operations);
	}
	return (rotate_to_pos(stacks, 1, operations));
}

void	solve_up_to_one_hundred(t_stacks *stacks, t_list **operations)
{
	
}
