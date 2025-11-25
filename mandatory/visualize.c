/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 17:32:25 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 19:47:56 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	num_length(int num)
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
	while (i < largest)
	{
		decr = 40;
		if (stacks->a && left_a + i == largest)
		{
			ft_printf("%d", item_a->number);
			decr -= num_length(item_a->number);
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
				while (decr--> 0)
					ft_printf(" ");
			}
			ft_printf("%d\n", item_b->number);
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
