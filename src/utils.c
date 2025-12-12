/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 17:47:06 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/12 18:10:29 by laveerka      ########   odam.nl         */
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

static t_list	*def_operation(t_list *new, char *op, char id)
{
	if (!ft_strncmp(op, "push", ft_strlen(op)) && id == 'A')
		new = ft_lstnew("pa");
	else if (!ft_strncmp(op, "push", ft_strlen(op)) && id == 'B')
		new = ft_lstnew("pb");
	else if (!ft_strncmp(op, "swap", ft_strlen(op)) && id == 'A')
		new = ft_lstnew("sa");
	else if (!ft_strncmp(op, "swap", ft_strlen(op)) && id == 'B')
		new = ft_lstnew("sb");
	else if (!ft_strncmp(op, "swap both", ft_strlen(op)) && id == 'b')
		new = ft_lstnew("ss");
	else if (!ft_strncmp(op, "rotate", ft_strlen(op)) && id == 'A')
		new = ft_lstnew("ra");
	else if (!ft_strncmp(op, "rotate", ft_strlen(op)) && id == 'B')
		new = ft_lstnew("rb");
	else if (!ft_strncmp(op, "rotate both", ft_strlen(op)) && id == 'b')
		new = ft_lstnew("rr");
	else if (!ft_strncmp(op, "reverse rotate", ft_strlen(op)) && id == 'A')
		new = ft_lstnew("rra");
	else if (!ft_strncmp(op, "reverse rotate", ft_strlen(op)) && id == 'B')
		new = ft_lstnew("rrb");
	else if (!ft_strncmp(op, "reverse rotate both", ft_strlen(op)) && id == 'b')
		new = ft_lstnew("rrr");
	return (new);
}

void	add_operation(t_stacks *stacks, char *op, char id, t_list **operations)
{
	t_list	*new;

	new = NULL;
	new = def_operation(new, op, id);
	if (new == NULL)
		init_exit("Malloc failed", stacks, operations);
	ft_lstadd_back(operations, new);
}
