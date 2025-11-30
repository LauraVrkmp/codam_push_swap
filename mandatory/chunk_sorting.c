/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:38:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/30 15:53:53 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	def_min_max(int	*min_max, t_chunk *chunk)
{
	if (!ft_strncmp("HIGH", chunk->current, ft_strlen(chunk->current)))
	{
		min_max[0] = chunk->high_min;
		min_max[1] = chunk->high_max;
	}
	else if (!ft_strncmp("MID", chunk->current, ft_strlen(chunk->current)))
	{
		min_max[0] = chunk->mid_min;
		min_max[1] = chunk->mid_max;
	}
	else
	{
		min_max[0] = chunk->low_min;
		min_max[1] = chunk->low_max;
	}
}

void	move_from_top_a(t_stacks *stacks, t_chunk *chunk, t_list **operations)
{
	int	min_max[2];
	int	max_op;
	
	def_min_max(min_max, chunk);
	ft_printf("min: %d, max: %d\n", chunk->low_min, chunk->low_max);
	ft_printf("min: %d, max: %d\n", chunk->mid_min, chunk->mid_max);
	ft_printf("min: %d, max: %d\n", chunk->high_min, chunk->high_max);
	ft_printf("chunk size: %d\n", test_chunk_size(stacks, chunk));
	max_op = 0;
	ft_printf("max rot smaller than: %d\n", min_max[1] - min_max[0] + 1);
	while (max_op < (chunk->high_max - chunk->low_min + 1) && stacks->a->size > 2)
	{
		if (stacks->a->first->rank >= chunk->high_min)
			rotate_stack(stacks, 'A', 1, operations);
		else
		{
			push_stack(stacks, 'B', operations);
			ft_printf("rank pushed: %d\n", stacks->b->first->rank);
			if (stacks->b->size > 1)
				ft_printf("next rank: %d\n", stacks->b->first->next->rank);
			ft_printf("low_max: %d\n", chunk->low_max);
			if (stacks->b->first->rank <= chunk->low_max && stacks->b->size > 1 && stacks->b->first->next->rank > chunk->low_max)
				ft_printf("here\n");
			if (stacks->b->first->rank <= chunk->low_max && stacks->b->size > 1 && stacks->b->first->next->rank > chunk->low_max)
				rotate_stack(stacks, 'B', 1, operations);
		}
		max_op++;
	}	
}

void	move_from_top_b(t_stacks *stacks, t_chunk *chunk, t_list **operations)
{
	int	min_max[2];
	
	def_min_max(min_max, chunk);
	while (test_chunk_size(stacks, chunk) != (min_max[1] - min_max[0] + 1))
	{
		if (stacks->b->first->rank >= chunk->high_min)
			push_stack(stacks, 'A', operations);
		else if (stacks->a->first->rank >= chunk->mid_min)
		{
			push_stack(stacks, 'B', operations);
			rotate_stack(stacks, 'A', 1, operations);
		}
		else
			rotate_stack(stacks, 'B', 1, operations);
	}	
}

void	move_from_bottom_a(t_stacks *stacks, t_chunk *chunk, t_list **operations)
{
	int	min_max[2];
	
	def_min_max(min_max, chunk);
	while (test_chunk_size(stacks, chunk) != (min_max[1] - min_max[0] + 1))
	{
		if (stacks->a->last->rank >= chunk->high_min)
			reverse_rotate_stack(stacks, 'A', 1, operations);
		else
		{
			push_stack(stacks, 'B', operations);
			if (stacks->a->last->rank < chunk->mid_min)
				rotate_stack(stacks, 'B', 1, operations);
		}
	}	
}

void	move_from_bottom_b(t_stacks *stacks, t_chunk *chunk, t_list **operations)
{
	int	min_max[2];
	
	def_min_max(min_max, chunk);
	while (test_chunk_size(stacks, chunk) != (min_max[1] - min_max[0] + 1))
	{
		reverse_rotate_stack(stacks, 'B', 1, operations);
		if (stacks->b->first->rank >= chunk->mid_min)
		{
			push_stack(stacks, 'A', operations);
			if (stacks->a->first->rank <= chunk->mid_max)
				rotate_stack(stacks, 'A', 1, operations);
		}
	}	
}
