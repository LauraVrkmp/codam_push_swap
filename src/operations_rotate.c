/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 22:13:16 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 18:02:58 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stacks *stacks, char id, char *count_id, \
t_list **operations)
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
		if (count_id[0] == '1' && count_id[1] == 'P')
			add_operation(stacks, "rotate", id, operations);
	}
}

void	reverse_rotate_stack(t_stacks *stacks, char id, char *count_id, \
t_list **operations)
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
		if (count_id[0] == '1' && count_id[1] == 'P')
			add_operation(stacks, "reverse rotate", id, operations);
	}
}

void	rotate_both(t_stacks *stacks, char *count_id, t_list **operations)
{
	rotate_stack(stacks, 'A', count_id, operations);
	rotate_stack(stacks, 'B', count_id, operations);
	if (count_id[1] == 'P')
		add_operation(stacks, "rotate both", 'b', operations);
}

void	reverse_rotate_both(t_stacks *stacks, char *count_id, \
t_list **operations)
{
	reverse_rotate_stack(stacks, 'A', count_id, operations);
	reverse_rotate_stack(stacks, 'B', count_id, operations);
	if (count_id[1] == 'P')
		add_operation(stacks, "reverse rotate both", 'b', operations);
}
