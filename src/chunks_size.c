/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunks_size.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/12 20:36:57 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 20:47:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_chunk(t_chunk *chunk, int start, int end)
{
	chunk->low_min = start;
	chunk->low_max = start + (end - start + 1) / 3 + \
((end - start + 1) % 3 > 0) - 1;
	chunk->mid_min = chunk->low_max + (chunk->low_max < end);
	chunk->mid_max = chunk->low_max + (end - start + 1) / 3 + \
((end - start + 1) % 3 > 1);
	chunk->high_min = chunk->mid_max + (chunk->mid_max < end);
	chunk->high_max = end;
}

static int	top_side(t_chunk chunk, t_stack *item_stack)
{
	t_item	*item;
	int		save;
	int		i;

	i = 0;
	item = item_stack->first;
	save = item->rank;
	while (item->rank >= chunk.low_min && item->rank <= chunk.high_max)
	{
		item = item->next;
		i++;
		if (item->rank == save)
			break ;
	}
	return (i);
}

static int	bottom_side(t_chunk chunk, t_stack *item_stack)
{
	t_item	*item;
	int		save;
	int		i;

	i = 0;
	item = item_stack->last;
	save = item->rank;
	while (item->rank >= chunk.low_min && item->rank <= chunk.high_max)
	{
		item = item->prev;
		i++;
		if (item->rank == save)
			break ;
	}
	return (i);
}

static int	number_in_chunk(t_chunk chunk, t_stack *item_stack)
{
	int		i;

	if (chunk.location == TOP_A || chunk.location == TOP_B)
		i = top_side(chunk, item_stack);
	else
		i = bottom_side(chunk, item_stack);
	return (i);
}

int	test_chunk_size(t_stacks *stacks, t_chunk chunk)
{
	t_stack	*item_stack;

	if (chunk.location == TOP_A || chunk.location == BOTTOM_A)
		item_stack = stacks->a;
	else
		item_stack = stacks->b;
	if (item_stack->size > 0)
		return (number_in_chunk(chunk, item_stack));
	return (0);
}
