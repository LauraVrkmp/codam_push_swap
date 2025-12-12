/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/11 10:05:15 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 13:38:13 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	invalid_instruction(t_stacks *stacks, char *instr)
{
	free(instr);
	cleanup(stacks, NULL);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	exec_instruction(t_stacks *stacks, char *instr)
{
	if (!ft_strncmp(instr, "sa\n", 3))
		swap_stack(stacks, 'A', "1C", NULL);
	else if (!ft_strncmp(instr, "sb\n", 3))
		swap_stack(stacks, 'B', "1C", NULL);
	else if (!ft_strncmp(instr, "ss\n", 3))
		swap_both(stacks, "2C", NULL);
	else if (!ft_strncmp(instr, "pa\n", 3))
		push_stack(stacks, "AC", NULL);
	else if (!ft_strncmp(instr, "pb\n", 3))
		push_stack(stacks, "BC", NULL);
	else if (!ft_strncmp(instr, "ra\n", 3))
		rotate_stack(stacks, 'A', "1C", NULL);
	else if (!ft_strncmp(instr, "rb\n", 3))
		rotate_stack(stacks, 'B', "1C", NULL);
	else if (!ft_strncmp(instr, "rr\n", 3))
		rotate_both(stacks, "2C", NULL);
	else if (!ft_strncmp(instr, "rra\n", 4))
		reverse_rotate_stack(stacks, 'A', "1C", NULL);
	else if (!ft_strncmp(instr, "rrb\n", 4))
		reverse_rotate_stack(stacks, 'B', "1C", NULL);
	else if (!ft_strncmp(instr, "rrr\n", 4))
		reverse_rotate_both(stacks, "2C", NULL);
	else
		invalid_instruction(stacks, instr);
}

static void	read_instructions(t_stacks *stacks)
{
	char	*instr;

	instr = get_next_line(STDIN_FILENO);
	while (instr != NULL)
	{
		exec_instruction(stacks, instr);
		free(instr);
		instr = get_next_line(STDIN_FILENO);
	}
	if (check_solved(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = malloc(sizeof(t_stacks));
		if (stacks == NULL)
			init_exit("Malloc failed", NULL, NULL);
		stacks->a = NULL;
		stacks->b = NULL;
		input_check_create(argc, argv, stacks);
		check_dup(stacks);
		assign_ranks(stacks);
		read_instructions(stacks);
		cleanup(stacks, NULL);
	}
	return (0);
}