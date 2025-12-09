/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/09 12:40:35 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top_a(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	while (max_op < (chunk.high_max - chunk.low_min + 1) && stacks->a->size > 2 && chunk.low_min != chunk.high_max)
	{
		if (rotate_to_order(stacks, operations))
			return ;
		ft_printf("chunk iteration: %d, low_min: %d\n", chunk.iteration, chunk.low_min);
		ft_printf("calc iteration: %d\n", calc_iteration(stacks->a->first->rank, stacks->total));
		if (section_sorted(stacks, stacks->a->first->rank, stacks->total, stacks->a->size - 1) && chunk.iteration >= calc_iteration(stacks->a->first->rank, stacks->total))
			return ;
		if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && stacks->a->first->rank + 1 == stacks->a->first->next->next->rank && section_sorted(stacks, stacks->a->first->next->next->rank, stacks->total, stacks->a->size - 1))
		{
			ft_printf("from top A swap A\n");
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		else if (stacks->a->first->rank >= chunk.high_min && stacks->a->first->rank <= chunk.high_max && !section_sorted(stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1))
		{
			ft_printf("from top A rotate A\n");
			rotate_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		else if (stacks->a->first->rank <= chunk.mid_max && !section_sorted(stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1))
		{
			ft_printf("from top A push to B\n");
			push_stack(stacks, 'B', operations);
			print_stacks(stacks);
			if (stacks->b->first->rank <= chunk.low_max && stacks->b->size > 1)
			{
				ft_printf("from top A rotate B\n");
				rotate_stack(stacks, 'B', 1, operations);
				print_stacks(stacks);
			}
		}
		max_op++;
	}	
}

void	move_from_top_b(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;
	
	max_op = 0;
	while (max_op < (chunk.high_max - chunk.low_min + 1) && stacks->b->size > 0)
	{
		rotate_to_order(stacks, operations);
		if (stacks->a->last->rank + 1 == stacks->a->last->prev->rank && stacks->a->last->rank + 2 == stacks->a->first->rank && section_sorted(stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1))
		{
			ft_printf("from top B reverse rotate A twice\n");
			reverse_rotate_stack(stacks, 'A', 1, operations);
			reverse_rotate_stack(stacks, 'A', 1, operations);
			continue ;
		}
		else if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && stacks->a->first->rank + 1 == stacks->a->first->next->next->rank && section_sorted(stacks, stacks->a->first->next->next->rank, stacks->total, stacks->a->size - 1))
		{
			ft_printf("from top B swap A\n");
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
			continue ;
		}
		else if (stacks->b->size == 2 && stacks->b->first->rank == 1 && stacks->b->first->next->rank == 2)
		{
			ft_printf("from top B swap B\n");
			swap_stack(stacks, 'B', 1, operations);
			print_stacks(stacks);
			while (stacks->b->size)
			{
				ft_printf("1 from top B push to A\n");
				push_stack(stacks, 'A', operations);
				print_stacks(stacks);
			}
		}
		else if (stacks->b->first->rank + 2 == stacks->a->first->rank && stacks->b->first->next->rank + 1 == stacks->a->first->rank && section_sorted(stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1))
		{
			ft_printf("double push to A and swap\n");
			push_stack(stacks, 'A', operations);
			push_stack(stacks, 'A', operations);
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
			max_op++;
		}
		else if ((stacks->b->first->rank >= chunk.high_min && stacks->b->first->rank <= chunk.high_max) || stacks->b->first->rank + 1 == stacks->a->first->rank && section_sorted(stacks, stacks->a->first->rank, stacks->total, stacks->a->size - 1))
		{
			ft_printf("2 from top B push to A\n");
			push_stack(stacks, 'A', operations);
			print_stacks(stacks);
		}
		else if (stacks->b->first->rank >= chunk.mid_min && stacks->b->first->rank <= chunk.mid_max)
		{
			ft_printf("3 from top B push to A\n");
			push_stack(stacks, 'A', operations);
			print_stacks(stacks);
			if (!section_sorted(stacks, stacks->a->first->rank, stacks->total, stacks->a->size - 1))
			{
				ft_printf("from top B rotate A\n");
				rotate_stack(stacks, 'A', 1, operations);
				print_stacks(stacks);
			}
		}
		else if (stacks->b->first->rank >= chunk.low_min && stacks->b->first->rank <= chunk.low_max && stacks->b->size > 2)
		{
			ft_printf("from top B rotate B\n");
			rotate_stack(stacks, 'B', 1, operations);
			print_stacks(stacks);
		}
		max_op++;
	}	
}

void	move_from_bottom_a(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	if (rotate_to_order(stacks, operations))
		return ;
	ft_printf("chunk iteration: %d, low_min: %d\n", chunk.iteration, chunk.low_min);
	ft_printf("calc iteration: %d\n", calc_iteration(stacks->a->first->rank, stacks->total));
	if (section_sorted(stacks, chunk.low_min, stacks->total, stacks->a->size - 1) && chunk.iteration >= calc_iteration(stacks->a->first->rank, stacks->total))
		return ;
	while (stacks->a->last->rank >= chunk.low_min && stacks->a->last->rank <= chunk.high_max)
	{
		ft_printf("from bottom A reverse rotate A\n");
		reverse_rotate_stack(stacks, 'A', 1, operations);
		print_stacks(stacks);
		if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && section_sorted(stacks, stacks->a->first->next->next->rank, 0, stacks->total - chunk.low_min - 1))
		{
			ft_printf("from bottom A swap\n");
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		else if (stacks->a->first->rank + 1 == stacks->a->last->rank && stacks->a->last->rank + 1 == stacks->a->first->next->rank && section_sorted(stacks, stacks->a->first->next->rank, 0, stacks->total - chunk.low_min))
		{
			ft_printf("from bottom A reverse rotate A and swap\n");
			reverse_rotate_stack(stacks, 'A', 1, operations);
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		else if (!section_sorted(stacks, stacks->a->first->rank, 0, stacks->total - chunk.low_min + 1) && stacks->a->first->rank >= chunk.low_min && stacks->a->first->rank <= chunk.mid_max && chunk.low_min + 1 < chunk.high_max)
		{
			ft_printf("from bottom A push to B\n");
			push_stack(stacks, 'B', operations);
			print_stacks(stacks);
			if (stacks->a->first->rank >= chunk.low_min && stacks->b->first->rank <= chunk.low_max)
			{
				ft_printf("from bottom A rotate B\n");
				rotate_stack(stacks, 'B', 1, operations);
				print_stacks(stacks);
			}
		}
	}	
}

void	move_from_bottom_b(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	while (max_op < (chunk.high_max - chunk.low_min + 1) && stacks->b->last->rank >= chunk.low_min && stacks->b->last->rank <= chunk.high_max && stacks->b->size > 2)
	{
		if (rotate_to_order(stacks, operations))
			return ;
		ft_printf("from bottom B reverse rotate B\n");
		reverse_rotate_stack(stacks, 'B', 1, operations);
		print_stacks(stacks);
		if (stacks->b->first->rank >= chunk.mid_min)
		{
			ft_printf("from bottom B push to A\n");
			push_stack(stacks, 'A', operations);
			print_stacks(stacks);
			if (stacks->a->first->rank - 1 == stacks->a->first->next->rank && stacks->a->first->rank + 1 == stacks->a->first->next->next->rank && section_sorted(stacks, stacks->a->first->next->next->rank, stacks->total, stacks->a->size - 1))
			{
				ft_printf("from bottom B swap A\n");
				swap_stack(stacks, 'A', 1, operations);
				print_stacks(stacks);
			}
			else if (stacks->a->first->rank <= chunk.mid_max && chunk.mid_max != chunk.high_max)
			{
				ft_printf("from bottom B rotate A\n");
				rotate_stack(stacks, 'A', 1, operations);
				print_stacks(stacks);
			}
		}
		max_op++;
	}
}
