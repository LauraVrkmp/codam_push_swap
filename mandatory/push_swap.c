/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/09 08:17:29 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve(t_stacks *stacks, t_list **operations)
{
	if (stacks->a->size == 2 && !check_solved(stacks))
		swap_stack(stacks, 'A', 1, operations);
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

	if (argc > 2)
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
		print_stacks(stacks);
		solve(stacks, &operations);
		print_operations(operations);
		print_stacks(stacks);
		if (section_sorted(stacks, 1, stacks->total, stacks->a->size - 1))
			ft_printf("stack is sorted\n");
		else
			ft_printf("stack is not sorted\n");
		cleanup(stacks, &operations);
	}
	return (0);
}
