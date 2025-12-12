/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 16:00:22 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 13:34:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_item	*item;

	while (stack->size && stack->first)
	{
		item = stack->first;
		stack->first = stack->first->next;
		free(item);
		stack->size--;
	}
	free(stack);
}

static void	free_operations(t_list **operations)
{
	t_list	*op_item;

	while (*operations)
	{
		op_item = *operations;
		*operations = (*operations)->next;
		ft_lstdelone(op_item, NULL);
	}
}

void	init_exit(char *message, t_stacks *stacks, t_list **operations)
{
	if (!ft_strncmp(message, "Malloc failed", ft_strlen(message)))
		write(2, "Malloc failed\n", ft_strlen("Malloc failed\n"));
	else if (!ft_strncmp(message, "Error", ft_strlen(message)))
		write(2, "Error\n", ft_strlen("Error\n"));
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		free(stacks);
	}
	if (operations)
		free_operations(operations);
	exit(EXIT_FAILURE);
}

void	cleanup(t_stacks *stacks, t_list **operations)
{
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		free(stacks);
	}
	if (operations)
		free_operations(operations);
}
