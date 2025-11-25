/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 13:16:11 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:06:59 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* int	main(void)
{
	t_list	*list;
	
	printf("%d\n", ft_lstsize(NULL));
	list = ft_lstnew("Last");
	ft_lstadd_front(&list, ft_lstnew("Middle"));
	ft_lstadd_front(&list, ft_lstnew("First"));
	printf("%d\n", ft_lstsize(list));
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	return (0);
} */
