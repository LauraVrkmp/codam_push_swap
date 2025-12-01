/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/01 14:37:25 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top_a(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	ft_printf("section sorted: %d\n", section_sorted(stacks, stacks->a->first->rank, stacks->a->size - 1));
	while (!section_sorted(stacks, stacks->a->first->rank, stacks->a->size - 1) && max_op < (chunk.high_max - chunk.low_min + 1) && stacks->a->size > 2 && chunk.low_min != chunk.high_max)
	{
		
		if (rotate_to_order(stacks, operations))
			return ;
		if ((stacks->a->first->rank >= chunk.high_min && stacks->a->first->rank <= chunk.high_max) || (stacks->a->first->rank == chunk.mid_max && chunk.mid_max + 1 == chunk.high_max) || (stacks->a->first->rank == chunk.low_max && chunk.low_max + 1 == chunk.high_max))
		{
			ft_printf("from top A rotate A\n");
			rotate_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
		}
		else if ((stacks->a->first->rank >= chunk.low_min && stacks->a->first->rank < chunk.mid_max && chunk.low_min + 1 != chunk.high_max) || (stacks->a->first->rank == chunk.mid_max && chunk.mid_max + 1 != chunk.high_max))
		{
			ft_printf("from top A push to B\n");
			push_stack(stacks, 'B', operations);
			print_stacks(stacks);
			if (stacks->b->first->rank <= chunk.low_max && stacks->b->size > 1 && stacks->b->first->next->rank > chunk.low_max)
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
		/* if (stacks->a->size > 2 && stacks->a->first->rank - 1 == stacks->a->first->next->rank)
		{
			ft_printf("from top B swap A\n");
			swap_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
			return ;
		} */
		if (rotate_to_order(stacks, operations))
			return ;
		if (stacks->b->size == 2 && stacks->b->first->rank == 1 && stacks->b->first->next->rank == 2)
		{
			ft_printf("from top B swap B\n");
			swap_stack(stacks, 'B', 1, operations);
			print_stacks(stacks);
			while (stacks->b->size)
			{
				ft_printf("from top B push to A\n");
				push_stack(stacks, 'B', operations);
				print_stacks(stacks);
			}
		}
		else if (stacks->b->first->rank >= chunk.high_min && stacks->b->first->rank <= chunk.high_max)
		{
			ft_printf("from top B push to A\n");
			push_stack(stacks, 'A', operations);
			print_stacks(stacks);
			/* if (stacks->a->first->rank + 1 != stacks->a->first->next->rank)
			{
				ft_printf("from top B rotate A\n");
				rotate_stack(stacks, 'A', 1, operations);
				print_stacks(stacks);
			} */
		}
		else if ((stacks->b->first->rank >= chunk.mid_min && stacks->b->first->rank <= chunk.mid_max) || chunk.low_min + 1 == chunk.high_max)
		{
			ft_printf("from top B push to A\n");
			push_stack(stacks, 'A', operations);
			print_stacks(stacks);
			if (stacks->a->first->rank + 1 != stacks->a->first->next->rank)
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
	int	max_op;

	max_op = 0;
	if (rotate_to_order(stacks, operations))
			return ;
	while (!section_sorted(stacks, chunk.low_min, chunk.high_max - chunk.low_min) && max_op < (chunk.high_max - chunk.low_min + 1))
	{
		if (stacks->a->last->rank >= chunk.low_min && stacks->a->last->rank <= chunk.high_max && stacks->a->size > 2)
		{
			ft_printf("from bottom A reverse rotate A\n");
			reverse_rotate_stack(stacks, 'A', 1, operations);
			print_stacks(stacks);
			if (stacks->a->first->rank >= chunk.low_min && stacks->a->first->rank <= chunk.mid_max && chunk.low_min != chunk.high_max)
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
		max_op++;
	}	
}

void	move_from_bottom_b(t_stacks *stacks, t_chunk chunk, t_list **operations)
{
	int	max_op;

	max_op = 0;
	if (rotate_to_order(stacks, operations))
		return ;
	while (max_op < (chunk.high_max - chunk.low_min + 1))
	{
		if (stacks->b->last->rank >= chunk.low_min && stacks->b->last->rank <= chunk.high_max)
		{
			ft_printf("from bottom B reverse rotate B\n");
			reverse_rotate_stack(stacks, 'B', 1, operations);
			print_stacks(stacks);
			if (stacks->b->first->rank >= chunk.mid_min)
			{
				ft_printf("from bottom B push to A\n");
				push_stack(stacks, 'A', operations);
				print_stacks(stacks);
				if (stacks->a->first->rank <= chunk.mid_max && !section_sorted(stacks, stacks->a->first->rank, stacks->a->size - 1))
				{
					ft_printf("from bottom B rotate A\n");
					rotate_stack(stacks, 'A', 1, operations);
					print_stacks(stacks);
				}
			}
		}
		max_op++;
	}	
}
