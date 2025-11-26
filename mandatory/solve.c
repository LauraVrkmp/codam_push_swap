/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 10:45:45 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/26 10:46:01 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_pos(t_stacks *stacks, int required)
{
	int	rotation;

	rotation = rotation_required(stacks, required);
	while (rotation > 0)
	{
		rotate_stack(stacks, 'A', 1);
		rotation--;
	}
	while (rotation < 0)
	{
		reverse_rotate_stack(stacks, 'A', 1);
		rotation++;
	}
}

static int	required_top(t_stacks *stacks)
{
	if (stacks->b->size > 1)
	{
		if (stacks->b->first->rank == stacks->total || (stacks->b->first->rank == stacks->total - 1 && stacks->b->first->next->rank == stacks->total))
			return (1 + (stacks->b->first->next->rank == 1));
		else
			return (stacks->b->first->rank + 1 + (stacks->b->first->next->rank == stacks->b->first->rank + 1));
	}
	if (stacks->b->first->rank == stacks->total)
		return (1);
	else
		return (stacks->b->first->rank + 1);
}

void	solve_three(t_stacks *stacks)
{
	if (check_solved(stacks))
		return ;
	else if (stacks->a->first->rank > stacks->a->first->next->rank && stacks->a->first->rank < stacks->a->last->rank)
		swap_stack(stacks, 'A', 1);
	else if (stacks->a->first->rank > stacks->a->first->next->rank && stacks->a->first->next->rank > stacks->a->last->rank)
	{
		swap_stack(stacks, 'A', 1);
		reverse_rotate_stack(stacks, 'A', 1);
	}
	else if (stacks->a->first->rank > stacks->a->last->rank && stacks->a->first->next->rank < stacks->a->last->rank)
		rotate_stack(stacks, 'A', 1);
	else if (stacks->a->first->rank < stacks->a->first->next->rank && stacks->a->first->next->rank < stacks->a->last->rank)
	{
		swap_stack(stacks, 'A', 1);
		rotate_stack(stacks, 'A', 1);
	}
	else
		reverse_rotate_stack(stacks, 'A', 1);
}

void	solve_up_to_five(t_stacks *stacks)
{
	int	top_a;

	if (check_ordered_not_sorted(stacks))
		return (rotate_to_pos(stacks, 1));
	while (stacks->a->size > 3 && !check_ordered_not_sorted(stacks))
		push_stack(stacks, 'B');
	if (!check_ordered_not_sorted(stacks))
		solve_three(stacks);
	while (stacks->b->size > 0)
	{
		top_a = required_top(stacks);
		rotate_to_pos(stacks, top_a);
		push_stack(stacks, 'A');
	}
	return (rotate_to_pos(stacks, 1));
}
