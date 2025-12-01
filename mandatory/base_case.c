/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_case.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/01 11:38:54 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_case_ext(t_stacks *stacks, t_chunk chunk, t_list **operations, int test_base)
{
	int	to_move;

	to_move = test_base;
	if (chunk.location == BOTTOM_A && stacks->a->size > 2)
	{
		while (to_move--)
		{
			ft_printf("base case BOTTOM_A reverse rotate A\n");
			reverse_rotate_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		if (test_base == 2 && stacks->a->first->rank > stacks->a->first->next->rank)
		{
			ft_printf("base case BOTTOM_A swap A\n");
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
	}
	else if (chunk.location == BOTTOM_B && stacks->b->size > 2)
	{
		while (to_move--)
		{
			ft_printf("base case BOTTOM_B reverse rotate B\n");
			reverse_rotate_stack(stacks, 'B', 1, operations);
			print_stacks(stacks);
		}
		if (test_base == 2 && stacks->b->first->rank < stacks->b->first->next->rank)
		{
			ft_printf("base case BOTTOM_B swap B\n");
			swap_stack(stacks, 'B', 1, operations);
			print_stacks(stacks);
		}
		while (test_base--)
		{
			ft_printf("base case BOTTOM_B push to A\n");
			push_stack(stacks, 'A', operations);
			print_stacks(stacks);
		}
	}
}

void	base_case(t_stacks *stacks, t_chunk chunk, t_list **operations, int test_base)
{
	if (chunk.location == TOP_A)
		ft_printf("TOP_A\n");
	else if (chunk.location == BOTTOM_A)
		ft_printf("BOTTOM_A\n");
	else if (chunk.location == TOP_B)
		ft_printf("TOP_B\n");
	else
		ft_printf("BOTTOM_B\n");
	ft_printf("base, test base: %d\n", test_base);
	if (!section_sorted(stacks, stacks->a->first->rank, chunk.high_max - stacks->a->first->rank))
	{
		if (chunk.location == TOP_A && stacks->a->first->rank > stacks->a->first->next->rank)
		{
			ft_printf("base case TOP_A swap A\n");
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		else if (chunk.location == TOP_B && stacks->b->size > 0)
		{
			if (stacks->b->size > 2 && stacks->b->first->rank < stacks->b->first->next->rank)
			{
				ft_printf("base case TOP_B swap B\n");
				swap_stack(stacks, 'B', 1, operations);
				print_stacks(stacks);
			}
			while (test_base--)
			{
				ft_printf("base case TOP_B push to A\n");
				push_stack(stacks, 'A', operations);
				print_stacks(stacks);
			}
		}
		else
			base_case_ext(stacks, chunk, operations, test_base);
	}
}
