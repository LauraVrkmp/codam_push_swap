/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_operations.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/29 20:05:45 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/29 20:34:44 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_list *operations)
{
	t_list	*op_item;

	while (operations)
	{
		op_item = operations;
		ft_printf("%s\n", op_item->content);
		operations = operations->next;
	}
}