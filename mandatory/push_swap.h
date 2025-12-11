/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:19 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/11 12:49:42 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/ft_printf_bonus.h"
#include "../lib/libft/libft.h"
#include "../lib/libft/get_next_line_bonus.h"

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				total;
	int				smallest_sorted;
}	t_stacks;

typedef struct s_stack
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

typedef enum e_div
{
	DIV_LOW,
	DIV_MID,
	DIV_HIGH
}	t_div;

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chunk
{
	int		high_min;
	int		high_max;
	int		mid_min;
	int		mid_max;
	int		low_min;
	int		low_max;
	int		iteration;
	int		smallest_sorted;
	t_div	division;
	t_loc	location;
}	t_chunk;

void		add_operation(t_stacks *stacks, char *op, char id, t_list **operations);
void		assign_ranks(t_stacks *stacks);
void		base_case(t_stacks *stacks, t_chunk chunk, t_list **operations, int test_base);
void		calc_chunk(t_chunk *chunk, int start, int end);
int			calc_iteration(int first_a, int total);
void		check_dup(t_stacks *stacks);
int			check_ordered_not_sorted(t_stacks *stacks);
int			check_solved(t_stacks *stacks);
void		chunk_sorting(t_stacks *stacks, t_chunk chunk, t_list **operations);
void		cleanup(t_stacks *stacks, t_list **operations);
void		init_exit(char *message, t_stacks *stacks, t_list **operations);
void		insert_item(t_stack *stack, t_item *item);
void		input_check_create(int amount, char **arguments, t_stacks *stacks);
int			find_smallest_sorted(t_stacks *stacks);
long long	ft_atoi_long_long(const char *nptr);
int			long_long_length(long long number);
t_loc		minimum_rotation(t_stacks *stacks, int *rot_required, t_chunk chunk);
void		move_from_bottom_a(t_stacks *stacks, t_chunk chunk, t_list **operations);
void		move_from_bottom_b(t_stacks *stacks, t_chunk chunk, t_list **operations);
void		move_from_top_a(t_stacks *stacks, t_chunk chunk, t_list **operations);
void		move_from_top_b(t_stacks *stacks, t_chunk chunk, t_list **operations);
void		position_update(t_stack *stack, char update);
void		push_stack(t_stacks *stacks, char *count_id, t_list **operations);
void		print_operations(t_list *operations);
void		print_stacks(t_stacks *stacks);
int			required_top(t_stacks *stacks);
void 		reverse_rotate_both(t_stacks *stacks, char *count_id, t_list **operations);
void		reverse_rotate_stack(t_stacks *stacks, char id, char *count_id, t_list **operations);
void		rotate_both(t_stacks *stacks, char *count_id, t_list **operations);
void		rotate_stack(t_stacks *stacks, char id, char *count_id, t_list **operations);
int			rotate_to_order(t_stacks *stacks, t_list **operations);
void		rotate_to_pos(t_stacks *stacks, int required, t_list **operations);
int			rotation_required(t_stacks *stacks, int required);
int			rotation_required_location(t_stack *stack, int loc, t_chunk chunk);
int			section_sorted(t_stacks *stacks, int start, int end, int length);
void		solve_three(t_stacks *stacks, t_list **operations);
void		solve_up_to_five(t_stacks *stacks, t_list **operations);
void		solve_big(t_stacks *stacks, t_list **operations);
void		swap_both(t_stacks *stacks, char *id, t_list **operations);
void		swap_stack(t_stacks *stacks, char to_id, char *count_id, t_list **operations);
int			test_chunk_size(t_stacks *stacks, t_chunk chunk);
