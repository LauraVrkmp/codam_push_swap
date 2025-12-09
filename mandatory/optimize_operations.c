/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_operations.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 20:05:45 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/09 08:17:49 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*substitute_operations(t_list *operations, char *id_first, char *id_second)
{
	t_list	*save_op;
	int		save_first;
	int		save_second;
	
	save_op = operations;
	save_first = 0;
	while (save_op && ft_strncmp(save_op->content, id_first, ft_strlen(id_first)))
	{
		save_op = save_op->next;
		save_first++;
	}
	save_second = 0;
	while (save_op && !ft_strncmp(save_op->content, id_second, ft_strlen(id_second)))
	{
		save_op = save_op->next;
		save_second++;
	}
	save_first *= 2;
	save_second *= 2;
	while (save_first-- && save_second--)
	{
		if (save_first % 2 == 0)
		{
			if (!ft_strncmp(id_first, "ra", ft_strlen("ra")) || !ft_strncmp(id_first, "rb", ft_strlen("rb")))
				ft_printf("rr\n");
			else if (!ft_strncmp(id_first, "rra", ft_strlen("rra")) || !ft_strncmp(id_first, "rrb", ft_strlen("rrb")))
				ft_printf("rrr\n");
			else if ((!ft_strncmp(id_first, "sa", ft_strlen("sa")) || !ft_strncmp(id_first, "sb", ft_strlen("sb"))))
				ft_printf("ss\n");
			ft_printf("substitution\n");
		}
		operations = operations->next;
	}
	return (operations);
}

static t_list	*skip_operations(t_list *operations, char *id_first, char *id_second)
{
	t_list	*save_op;
	int		save_first;
	int		save_second;
	
	save_op = operations;
	save_first = 0;
	while (save_op && !ft_strncmp(save_op->content, id_first, ft_strlen(id_first)))
	{
		save_op = save_op->next;
		save_first++;
	}
	save_second = 0;
	while (save_op && !ft_strncmp(save_op->content, id_second, ft_strlen(id_second)))
	{
		save_op = save_op->next;
		save_second++;
	}
	save_first *= 2;
	save_second *= 2;
	while (save_first-- && save_second--)
	{
		ft_printf("%s to %s optimization\n", id_first, id_second);
		operations = operations->next;
	}
	return (operations);
}

void	print_operations(t_list *operations)
{
	while (operations)
	{
		/* operations = skip_operations(operations, "ra", "rra");
		operations = skip_operations(operations, "rra", "ra");
		operations = skip_operations(operations, "rb", "rrb");
		operations = skip_operations(operations, "rrb", "rb");
		operations = skip_operations(operations, "pa", "pb");
		operations = skip_operations(operations, "pb", "pa");
		operations = skip_operations(operations, "sa", "sa");
		operations = skip_operations(operations, "sb", "sb");
		operations = substitute_operations(operations, "sa", "sb");
		operations = substitute_operations(operations, "sb", "sa");
		operations = substitute_operations(operations, "ra", "rb");
		operations = substitute_operations(operations, "rb", "ra");
		operations = substitute_operations(operations, "rra", "rrb");
		operations = substitute_operations(operations, "rrb", "rra"); */
		ft_printf("%s\n", operations->content);
		operations = operations->next;
	}
}
