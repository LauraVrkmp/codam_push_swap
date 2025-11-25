/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 09:06:15 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:06:16 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* int	main(void)
{
	t_list	*list;

	list = ft_lstnew("Last");
	ft_lstadd_front(&list, ft_lstnew("Middle"));
	ft_lstadd_front(&list, ft_lstnew("First"));
	printf("%s\n", (char *)ft_lstlast(list)->content);
	return (0);
} */
