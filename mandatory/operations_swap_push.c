/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 18:41:34 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 22:11:39 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_tranfer(t_stack *from_stack, t_stack *to_stack, \
t_item *transfer)
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
		return ;
	transfer = from_stack->first;
	push_tranfer(from_stack, to_stack, transfer);
	position_update(from_stack, 'F');
	position_update(to_stack, 'F');
}

static void	swap_transfer(t_stack *stack, t_item *first_to_second, \
t_item *second_to_first)
{
	first_to_second->next = second_to_first->next;
	second_to_first->next->prev = first_to_second;
	first_to_second->prev = second_to_first;
	second_to_first->next = first_to_second;
	second_to_first->prev = stack->last;
	stack->last->next = second_to_first;
	stack->first = second_to_first;
}

void	swap_stack(t_stacks *stacks, char id)
{
	t_stack	*stack;
	t_item	*first_to_second;
	t_item	*second_to_first;

	if (id == 'A')
		stack = stacks->a;
	else
		stack = stacks->b;
	if (stack->size < 2)
		return ;
	first_to_second = stack->first;
	second_to_first = stack->first->next;
	if (stack->size == 2)
	{
		stack->first = second_to_first;
		stack->last = first_to_second;
	}
	else
		swap_transfer(stack, first_to_second, second_to_first);
	position_update(stack, 'S');
}

void	swap_both(t_stacks *stacks)
{
	swap_stack(stacks, 'A');
	swap_stack(stacks, 'B');
}
