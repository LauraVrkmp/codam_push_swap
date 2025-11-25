/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   position_operations.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 21:51:33 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 22:08:32 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_update(t_stack *stack, char update)
{
	int		pos;
	int		i;
	t_item	*item;

	pos = 1;	
	if (update == 'F')
	{
		i = 0;
		item = stack->first;
		while (i < stack->size)
		{
			item->position = pos;
			item = item->next;
			pos++;
			i++;
		}
	}
	else if (update == 'S')
	{
		stack->first->position = 1;
		stack->first->next->position = 2;
	}
}
