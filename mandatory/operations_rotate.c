/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 22:13:16 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/26 03:47:00 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stacks *stacks, char id, int count)
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
	if (count == 1)
		ft_printf("r%c\n", ft_tolower(id));
}

void	reverse_rotate_stack(t_stacks *stacks, char id, int count)
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
	if (count == 1)
		ft_printf("rr%c\n", ft_tolower(id));
}

void rotate_both(t_stacks *stacks)
{
	rotate_stack(stacks, 'A', 2);
	rotate_stack(stacks, 'B', 2);
	ft_printf("rr\n");
}

void reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_stack(stacks, 'A', 2);
	reverse_rotate_stack(stacks, 'B', 2);
	ft_printf("rrr\n");
}
