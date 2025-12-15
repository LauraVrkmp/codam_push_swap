/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/15 14:38:17 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_dup(t_stacks *stacks)
{
	int		i;
	int		j;
	t_item	*current;
	t_item	*compare;

	i = 1;
	current = stacks->a->first;
	while (i < stacks->a->size)
	{
		j = i;
		compare = current->next;
		while (j < stacks->a->size)
		{
			if (current->number == compare->number)
				init_exit("Error", stacks, NULL);
			compare = compare->next;
			j++;
		}
		current = current->next;
		i++;
	}
}

static void	solve(t_stacks *stacks, t_list **operations)
{
	if (stacks->a->size <= 2 && !check_solved(stacks))
		swap_stack(stacks, 'A', "1P", operations);
	else if (stacks->a->size == 3)
		solve_three(stacks, operations);
	else if (stacks->a->size <= 5)
		solve_up_to_five(stacks, operations);
	else
		solve_big(stacks, operations);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list		*operations;

	if (argc > 1)
	{
		stacks = malloc(sizeof(t_stacks));
		if (stacks == NULL)
			init_exit("Malloc failed", NULL, NULL);
		stacks->a = NULL;
		stacks->b = NULL;
		operations = NULL;
		input_check_create(argc, argv, stacks);
		check_dup(stacks);
		assign_ranks(stacks);
		solve(stacks, &operations);
		print_operations(operations);
		cleanup(stacks, &operations);
	}
	return (0);
}
