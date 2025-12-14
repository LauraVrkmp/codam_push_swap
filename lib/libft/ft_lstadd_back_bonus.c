/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 09:04:18 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/14 17:52:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/* int	main(void)
{
	t_list	*list;
	
	list = ft_lstnew("Last");
	ft_lstadd_front(&list, ft_lstnew("Middle"));
	ft_lstadd_front(&list, ft_lstnew("First"));
	ft_lstadd_back(&list, ft_lstnew("Ultimate"));
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	return (0);
} */
