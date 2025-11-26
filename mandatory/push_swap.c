/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/26 12:58:11 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
