/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:19 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 16:04:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/ft_printf_bonus.h"
#include "../lib/libft/libft.h"

typedef struct s_stacks
{
	struct s_stack	**a;
	struct s_stack	**b;	
}	t_stacks;

typedef struct	s_stack
{
	int				size;
	char			id;
	struct s_item	*first;
	struct s_item	*last;
}	t_stack;

typedef struct s_item
{
	int				number;
	int				rank;
	int				position;
	struct s_item	*next;
	struct s_item	*prev;
}	t_item;

void	init_exit(char *message, t_stacks *stacks);
