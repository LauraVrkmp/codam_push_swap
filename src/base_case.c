/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_case.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/11 11:05:21 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	base_case_ext(t_stacks *stacks, t_chunk chunk, t_list **operations, int test_base)
{
	if (chunk.location == BOTTOM_A)
	{
		while (stacks->a->first->rank != chunk.high_max)
		{
			ft_printf("base case BOTTOM_A reverse rotate A\n");
			reverse_rotate_stack(stacks, 'A', "1P", operations);
			print_stacks(stacks);
			if (stacks->a->first->rank != chunk.high_max)
			{
				ft_printf("base case BOTTOM_A push to B\n");
				push_stack(stacks, "BP", operations);
				print_stacks(stacks);
			}
		}
		if (test_base == 2 && stacks->a->first->rank - 1 == stacks->a->first->next->rank)
		{
			ft_printf("base case BOTTOM_A swap A\n");
			swap_stack(stacks, 'A', "1P", operations);
			print_stacks(stacks);
		}
	}
	else if (chunk.location == BOTTOM_B)
	{
		while (stacks->b->size > 1 && stacks->b->first->rank != chunk.low_min)
		{
			ft_printf("base case BOTTOM_B reverse rotate B\n");
			reverse_rotate_stack(stacks, 'B', "1P", operations);
			print_stacks(stacks);
		}
		if (test_base == 2 && stacks->b->first->rank + 1 == stacks->b->first->next->rank)
		{
			ft_printf("base case BOTTOM_B swap B\n");
			swap_stack(stacks, 'B', "1P", operations);
			print_stacks(stacks);
		}
		while (stacks->b->first && stacks->b->first->rank + 1 == stacks->a->first->rank)
		{
			ft_printf("base case BOTTOM_B push to A\n");
			push_stack(stacks, "AP", operations);
			print_stacks(stacks);
		}
	}
}

void	base_case(t_stacks *stacks, t_chunk chunk, t_list **operations, int test_base)
{
	if (chunk.location == TOP_A)
		ft_printf("base case TOP_A\n");
	else if (chunk.location == BOTTOM_A)
		ft_printf("base case BOTTOM_A\n");
	else if (chunk.location == TOP_B)
		ft_printf("base case TOP_B\n");
	else
		ft_printf("base case BOTTOM_B\n");
	ft_printf("base, test base: %d\n", test_base);
	if (chunk.low_min >= stacks->smallest_sorted && stacks->smallest_sorted != stacks->total && chunk.iteration >= calc_iteration(stacks->smallest_sorted, stacks->total))
		return ;
	if (stacks->a->size == 3 && !section_sorted(stacks, stacks->a->first->rank, stacks->total, stacks->a->size - 1))
	{
		ft_printf("base case TOP_A sort three A\n");
		solve_three(stacks, operations);
		print_stacks(stacks);
	}
	else if (chunk.location == TOP_A && stacks->a->first->rank - 1 == stacks->a->first->next->rank)
	{
		ft_printf("base case TOP_A swap A\n");
		swap_stack(stacks, 'A', "1P", operations);
		print_stacks(stacks);
	}
	else if (chunk.location == TOP_B && stacks->b->size > 0)
	{
		if (test_base == 2 && stacks->b->first->rank + 1 == stacks->b->first->next->rank)
		{
			ft_printf("base case TOP_B swap B\n");
			swap_stack(stacks, 'B', "1P", operations);
			print_stacks(stacks);
		}
		while (test_base--)
		{
			ft_printf("base case TOP_B push to A\n");
			push_stack(stacks, "AP", operations);
			print_stacks(stacks);
		}
		while (chunk.low_min + 1 == stacks->a->first->rank && stacks->b->first->rank != chunk.low_min)
		{
			ft_printf("base case TOP_B rotate B\n");
			rotate_stack(stacks, 'B', "1P", operations);
			print_stacks(stacks);
		}
		if (stacks->b->first && stacks->b->first->rank + 1 == stacks->a->first->rank)
		{
			ft_printf("base case TOP_B push to A\n");
			push_stack(stacks, "AP", operations);
			print_stacks(stacks);
		}
	}
	else
		base_case_ext(stacks, chunk, operations, test_base);
	stacks->smallest_sorted = find_smallest_sorted(stacks);
}

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
