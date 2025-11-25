/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 09:04:39 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:54:02 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	char	content[] = "Content of the node.";
	char	insert[] = "This should come first.";
	t_list	*first;
	t_list	*ins;

	first = ft_lstnew(content);
	ins = ft_lstnew(insert);
	ft_lstadd_front(&first, ins);
	while (ins)
	{
		printf("%s\n", (char *)ins->content);
		ins = ins->next;
	}
	return (0);
} */
