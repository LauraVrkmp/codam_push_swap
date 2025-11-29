/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 20:51:46 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/29 20:56:29 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_required(t_stacks *stacks, int required)
{
	int		pos_one;
	t_item	*current;

	current = stacks->a->first;
	while (current->rank != required)
		current = current->next;
	pos_one = current->position;
	if (pos_one <= (stacks->a->size / 2 + 1))
		return (pos_one - 1);
	else
		return (-(stacks->a->size - pos_one + 1));
}

void	rotate_to_pos(t_stacks *stacks, int required, t_list **operations)
{
	int	rotation;

	rotation = rotation_required(stacks, required);
	while (rotation > 0)
	{
		rotate_stack(stacks, 'A', 1, operations);
		rotation--;
	}
	while (rotation < 0)
	{
		reverse_rotate_stack(stacks, 'A', 1, operations);
		rotation++;
	}
}

int	required_top(t_stacks *stacks)
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
