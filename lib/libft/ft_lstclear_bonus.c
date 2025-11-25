/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 09:05:17 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:55:33 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/* static void	ft_delete(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*first;
	t_list	*second;
	char	*content_first;
	char	*content_second;

	content_first = ft_strdup("This is the content");
	first = ft_lstnew(content_first);
	content_second = ft_strdup("This comes second");
	second = ft_lstnew(content_second);
	ft_lstadd_back(&first, second);
	ft_lstclear(&first, ft_delete);
	return (0);
} */
