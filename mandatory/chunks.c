/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/30 10:37:59 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/30 16:12:10 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_chunk(t_chunk *chunk, int start, int end)
{
	chunk->low_min = start;
	chunk->low_max = start + (end - start + 1) / 3 + ((end - start + 1) % 3 > 0) - 1;
	chunk->mid_min = chunk->low_max + (chunk->low_max < end);
	chunk->mid_max = chunk->low_max + (end - start + 1) / 3 + ((end - start + 1) % 3 > 1);
	chunk->high_min = chunk->mid_max + (chunk->mid_max < end);
	chunk->high_max = end;
}

static int	number_in_chunk(t_chunk *chunk, t_stack *item_stack, int *low_high)
{
	t_item	*item;
	int		save;
	int		i;

	i = 0;
	if (!ft_strncmp("TOP_A", chunk->loc, ft_strlen(chunk->loc)) || !ft_strncmp("TOP_B", chunk->loc, ft_strlen(chunk->loc)))
	{
		item = item_stack->first;
		save = item->rank;
		while (item->rank >= low_high[0] && item->rank <= low_high[1])
		{
			item = item->next;
			i++;
			if (item->rank == save)
				break ;
		}
	}
	else
	{
		item = item_stack->last;
		save = item->rank;
		while (item->rank >= low_high[0] && item->rank <= low_high[1])
		{
			item = item->prev;
			i++;
			if (item->rank == save)
				break ;
		}
	}
	return (i);
}

int	test_chunk_size(t_stacks *stacks, t_chunk *chunk)
{
	int		low_high[2];
	t_stack	*item_stack;

	if (chunk->high_max - chunk->low_min + 1 <= 2)
		return (chunk->high_max - chunk->low_min + 1);
	if (!ft_strncmp("HIGH", chunk->current, ft_strlen(chunk->current)))
	{
		low_high[0] = chunk->high_min;
		low_high[1] = chunk->high_max;
	}
	else if (!ft_strncmp("MID", chunk->current, ft_strlen(chunk->current)))
	{
		low_high[0] = chunk->mid_min;
		low_high[1] = chunk->mid_max;
	}
	else if (!ft_strncmp("LOW", chunk->current, ft_strlen(chunk->current)))
	{
		low_high[0] = chunk->low_min;
		low_high[1] = chunk->low_max;
	}
	if (!ft_strncmp("TOP_A", chunk->loc, ft_strlen(chunk->loc)) || !ft_strncmp("BOTTOM_A", chunk->loc, ft_strlen(chunk->loc)))
		item_stack = stacks->a;
	else
		item_stack = stacks->b;
	return (number_in_chunk(chunk, item_stack, low_high));
}

void	chunk_sorting(t_stacks *stacks, t_chunk *chunk, t_list **operations)
{
	int	test_base;

	if (stacks->a->size == stacks->total)
		calc_chunk(chunk, 1, stacks->total);
	test_base = test_chunk_size(stacks, chunk);
	if (chunk->high_max - chunk->low_min + 1 <= 2)
		return (base_case(stacks, chunk, operations, test_base));
	if (stacks->a->size != stacks->total)
	{
		if (!ft_strncmp("HIGH", chunk->current, ft_strlen(chunk->current)))
			calc_chunk(chunk, chunk->high_min, chunk->high_max);
		else if (!ft_strncmp("MID", chunk->current, ft_strlen(chunk->current)))
			calc_chunk(chunk, chunk->mid_min, chunk->mid_max);
		else
			calc_chunk(chunk, chunk->low_min, chunk->low_max);
	}		
	if (!ft_strncmp("TOP_A", chunk->loc, ft_strlen(chunk->loc)))
		move_from_top_a(stacks, chunk, operations);
	else if (!ft_strncmp("TOP_B", chunk->loc, ft_strlen(chunk->loc)))
		move_from_top_b(stacks, chunk, operations);
	else if (!ft_strncmp("BOTTOM_A", chunk->loc, ft_strlen(chunk->loc)))
		move_from_bottom_a(stacks, chunk, operations);
	else
		move_from_bottom_b(stacks, chunk, operations);
	if (stacks->a->first->rank >= chunk->low_min && stacks->a->first->rank <= chunk->high_max)
		chunk->loc = "TOP_A";
	else if (stacks->a->last->rank >= chunk->low_min && stacks->a->last->rank <= chunk->high_max)
		chunk->loc = "BOTTOM_A";
	else if (stacks->b->first->rank >= chunk->low_min && stacks->b->first->rank <= chunk->high_max)
		chunk->loc = "TOP_B";
	else
		chunk->loc = "BOTTOM_B";
	ft_printf("chunk loc: %s\n", chunk->loc);
/* 	chunk->current = "HIGH";
	chunk_sorting(stacks, chunk, operations);
	print_stacks(stacks);
	chunk->current = "MID";
	chunk_sorting(stacks, chunk, operations);
	print_stacks(stacks);
	chunk->current = "LOW";
	chunk_sorting(stacks, chunk, operations);
	print_stacks(stacks); */
}
