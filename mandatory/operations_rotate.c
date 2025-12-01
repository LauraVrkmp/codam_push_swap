/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 22:13:16 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/30 23:40:17 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stacks *stacks, char id, int count, t_list **operations)
{
	t_stack	*stack;

	if (id == 'A')
		stack = stacks->a;
	else
		stack = stacks->b;
	if (stack->size > 1)
	{
		stack->first = stack->first->next;
		stack->last = stack->last->next;
		position_update(stack, 'F');
		if (count == 1)
			add_operation(stacks, "rotate", id, operations);
		else
			add_operation(stacks, "rotate both", 'b', operations);
	}
}

void	reverse_rotate_stack(t_stacks *stacks, char id, int count, t_list **operations)
{
	t_stack	*stack;

	if (id == 'A')
		stack = stacks->a;
	else
		stack = stacks->b;
	if (stack->size > 1)
	{
		stack->first = stack->first->prev;
		stack->last = stack->last->prev;
		position_update(stack, 'F');
		if (count == 1)
			add_operation(stacks, "reverse rotate", id, operations);
		else
			add_operation(stacks, "reverse rotate both", 'b', operations);
	}
}

void rotate_both(t_stacks *stacks, t_list **operations)
{
	rotate_stack(stacks, 'A', 2, operations);
	rotate_stack(stacks, 'B', 2, operations);
}

void reverse_rotate_both(t_stacks *stacks, t_list **operations)
{
	reverse_rotate_stack(stacks, 'A', 2, operations);
	reverse_rotate_stack(stacks, 'B', 2, operations);
}
