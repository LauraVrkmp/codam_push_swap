/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/26 03:54:54 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_solved(t_stacks *stacks)
{
	int		i;
	t_item	*current;

	i = 0;
	current = stacks->a->first;
	if (stacks->b->size != 0)
		return (0);
	while (i < stacks->a->size)
	{
		if (current->rank != i + 1)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	check_ordered_not_sorted(t_stacks *stacks)
{
	t_item	*current;
	int		min;
	int		i;

	i = 0;
	min = stacks->total;
	current = stacks->a->first;
	while (i < stacks->a->size)
	{
		if (current->rank < min)
			min = current->rank;
		current = current->next;
		i++;
	}
	while (current->rank != min)
		current = current->next;
	i = 0;
	while (i < stacks->a->size - 1)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

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

static void	solve(t_stacks *stacks)
{
	if (stacks->a->size == 2 && !check_solved(stacks))
		swap_stack(stacks, 'A', 1);
	else if (stacks->a->size == 3)
		solve_three(stacks);
	else if (stacks->a->size <= 5)
		solve_up_to_five(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 2)
	{
		stacks = malloc(sizeof(t_stacks));
		if (stacks == NULL)
			init_exit("Malloc failed", NULL);
		stacks->a = NULL;
		stacks->b = NULL;
		input_check_create(argc, argv, stacks);
		check_dup(stacks);
		assign_ranks(stacks);
		solve(stacks);
		cleanup(stacks);
	}
	return (0);
}
