/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 20:51:46 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 21:33:23 by laveerka      ########   odam.nl         */
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
		rotate_stack(stacks, 'A', "1P", operations);
		rotation--;
	}
	while (rotation < 0)
	{
		reverse_rotate_stack(stacks, 'A', "1P", operations);
		rotation++;
	}
}

int	required_top(t_stacks *stacks)
{
	if (stacks->b->size > 1)
	{
		if (stacks->b->first->rank == stacks->total || \
(stacks->b->first->rank == stacks->total - 1 && \
stacks->b->first->next->rank == stacks->total))
			return (1 + (stacks->b->first->next->rank == 1));
		else
			return (stacks->b->first->rank + 1 + \
(stacks->b->first->next->rank == stacks->b->first->rank + 1));
	}
	if (stacks->b->first->rank == stacks->total)
		return (1);
	else
		return (stacks->b->first->rank + 1);
}

int	section_sorted(t_stacks *stacks, int start, int end, int length)
{
	t_item	*item;
	int		i;

	i = 0;
	item = stacks->a->first;
	if (start == end)
		return (0);
	while (item->rank != start && i++ < stacks->a->size - 1)
		item = item->next;
	if (item->rank != start)
		return (0);
	i = 0;
	while (i < length && item->rank != end)
	{
		if (item->rank != (start + i) || item->rank + 1 != item->next->rank)
			return (0);
		item = item->next;
		i++;
	}
	return (1);
}

int	rotate_to_order(t_stacks *stacks, t_list **operations)
{
	t_item	*item;
	int		i;

	if (!section_sorted(stacks, stacks->a->first->rank, 0, \
stacks->a->size - 1))
	{
		i = 0;
		item = stacks->a->first;
		while (item->rank != stacks->total && i++ < stacks->a->size)
			item = item->next;
		i = 0;
		while (item->rank - 1 == item->prev->rank && i++ < stacks->a->size)
			item = item->prev;
		if (i == stacks->a->size - 1)
		{
			rotate_to_pos(stacks, item->rank, operations);
			stacks->smallest_sorted = find_smallest_sorted(stacks);
			return (1);
		}
	}
	return (0);
}
