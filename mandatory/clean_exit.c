/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 16:00:22 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 17:31:26 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_stack(t_stack *stack)
{
	t_item	*item;

	while (stack->size)
	{
		item = stack->first;
		stack->first = stack->first->next;
		free(item);
		stack->size--;
	}
	free(stack);
}

void	init_exit(char *message, t_stacks *stacks)
{
	if (!ft_strncmp(message, "Malloc failed", ft_strlen(message)))
		ft_printf("%s\n", message);
	else if (!ft_strncmp(message, "Error", ft_strlen(message)))
		ft_printf("%s\n", message);
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		free(stacks);
	}
	exit(EXIT_FAILURE);
}

void	cleanup(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		free(stacks);
	}
}