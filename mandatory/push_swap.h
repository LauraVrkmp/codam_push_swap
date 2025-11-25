/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:19 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 18:55:50 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/ft_printf_bonus.h"
#include "../lib/libft/libft.h"

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;	
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

long long	ft_atoi_long_long(const char *nptr);
void		check_dup(t_stacks *stacks);
void		cleanup(t_stacks *stacks);
void		init_exit(char *message, t_stacks *stacks);
void		insert_item(t_stack *stack, t_item *item);
void		input_check_create(int amount, char **arguments, t_stacks *stacks);
void		push_stack(t_stacks *stacks, char to_stack);
void		print_stacks(t_stacks *stacks);
