/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 17:47:06 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/26 12:58:20 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_long_long(const char *nptr)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		if (!(ft_isdigit(*nptr)))
			return (0);
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
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

int	check_ordered_not_sorted(t_stacks *stacks)
{
	t_item	*current;
	int		min;
	int		i;

	i = 0;
	min = stacks->total;
	current = stacks->a->first;
	while (i < stacks->a->size)
	{
		if (current->rank < min)
			min = current->rank;
		current = current->next;
		i++;
	}
	while (current->rank != min)
		current = current->next;
	i = 0;
	while (i < stacks->a->size - 1)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
