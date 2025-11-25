/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/25 11:15:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 16:03:30 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	input_check_plus_save(int amount, char **arguments)
{

}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 2)
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks *));
		if (stacks == NULL)
			init_exit("Malloc failed", NULL);
		input_check_plus_save(argc, argv);	
	}
	return (0);
}