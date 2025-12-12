/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   determine_rank_smallest.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/09 16:55:24 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 18:00:11 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ranks_loop(t_stacks *stacks, int rank, int *ranks_array, \
t_item *current)
{
	int	i;
	int	minimum;

	i = 0;
	minimum = INT_MAX;
	while (i < stacks->a->size)
	{
		if (current->number < minimum && !ranks_array[i])
			minimum = current->number;
		current = current->next;
		i++;
	}
	i = 0;
	current = stacks->a->first;
	while (i < stacks->a->size)
	{
		if (current->number == minimum)
		{
			current->rank = rank;
			ranks_array[i] = 1;
		}
		current = current->next;
		i++;
	}
}

void	assign_ranks(t_stacks *stacks)
{
	int		*ranks_array;
	int		rank;
	t_item	*current;

	ranks_array = ft_calloc(stacks->a->size, sizeof(int));
	if (ranks_array == NULL)
		init_exit("Malloc failed", stacks, NULL);
	rank = 1;
	current = stacks->a->first;
	while (rank < (stacks->a->size + 1))
	{
		ranks_loop(stacks, rank, ranks_array, current);
		rank++;
	}
	free(ranks_array);
}

int	find_smallest_sorted(t_stacks *stacks)
{
	t_item	*item;

	item = stacks->a->first;
	while (item->rank != stacks->total)
		item = item->next;
	while (item->prev->rank + 1 == item->rank && \
item->prev->position + 1 == item->position)
		item = item->prev;
	return (item->rank);
}
