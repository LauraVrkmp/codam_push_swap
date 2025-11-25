/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 16:00:22 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 16:04:01 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_exit(char *message, t_stacks *stacks)
{
	if (!ft_strncmp(message, "Malloc failed", ft_strlen(message)))
	{
		if (stacks)
			free(stacks);
		exit(EXIT_FAILURE);
	}
}