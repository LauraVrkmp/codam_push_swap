/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 22:13:16 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 22:33:23 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stacks *stacks, char id)
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
	}
	position_update(stack, 'F');
}

void	reverse_rotate_stack(t_stacks *stacks, char id)
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
	}
	position_update(stack, 'F');
}

void rotate_both(t_stacks *stacks)
{
	rotate_stack(stacks, 'A');
	rotate_stack(stacks, 'B');
}

void reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_stack(stacks, 'A');
	reverse_rotate_stack(stacks, 'B');
}
