/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 18:41:34 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 19:22:47 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_tranfer(t_stack *from_stack, t_stack *to_stack, t_item *transfer)
{
	if (from_stack->size == 0)
	{
		from_stack->first = NULL;
		from_stack->last = NULL;
	}
	else
	{
		from_stack->first = transfer->next;
		from_stack->last->next = transfer->next;
		transfer->next->prev = from_stack->last;
	}
	from_stack->size--;
	if (to_stack->size == 0)
		insert_item(to_stack, transfer);
	else
	{
		transfer->prev = to_stack->last;
		to_stack->last->next = transfer;
		transfer->next = to_stack->first;
		to_stack->first->prev = transfer;
		to_stack->first = transfer;
	}
	to_stack->size++;
}

void	push_stack(t_stacks *stacks, char to_id)
{
	t_stack	*from_stack;
	t_stack	*to_stack;
	t_item	*transfer;

	if (to_id == 'A')
	{
		from_stack = stacks->b;
		to_stack = stacks->a;
	}
	else
	{
		from_stack = stacks->a;
		to_stack = stacks->b;
	}
	if (from_stack->size == 0)
		return;
	transfer = from_stack->first;
	push_tranfer(from_stack, to_stack, transfer);
}
