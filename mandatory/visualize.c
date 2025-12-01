/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 17:32:25 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/01 04:49:02 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_length(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	print_stacks(t_stacks *stacks)
{
	t_item	*item_a;
	t_item	*item_b;
	int		i;
	int		largest;
	int		left_a;
	int		left_b;
	int		decr;

	i = 0;
	if (stacks->a && stacks->b && stacks->a->size < stacks->b->size)
		largest = stacks->b->size;
	else
		largest = stacks->a->size;
	item_a = stacks->a->first;
	item_b = stacks->b->first;
	left_a = stacks->a->size;
	left_b = stacks->b->size;
	ft_printf("\n");
	while (i < largest)
	{
		decr = 40;
		if (stacks->a && left_a + i == largest)
		{
			ft_printf("%d %d %d", item_a->number, item_a->position, item_a->rank);
			decr -= num_length(item_a->number) + num_length(item_a->position) + num_length(item_a->rank) + 2;
			while (decr--)
				ft_printf(" ");
			if (stacks->b && left_b + i != largest)
				ft_printf("\n");
			item_a = item_a->next;
			left_a--;
		}
		if (stacks->b && left_b + i == largest)
		{
			if (stacks->a && left_a + i != largest)
			{
				while (decr-- > 0)
					ft_printf(" ");
			}
			ft_printf("%d %d %d\n", item_b->number, item_b->position, item_b->rank);
			item_b = item_b->next;
			left_b--;
		}
		i++;
	}
	ft_printf("\nA");
	decr = 39;
	while (decr--)
		ft_printf(" ");
	ft_printf("B\n\n");
}
