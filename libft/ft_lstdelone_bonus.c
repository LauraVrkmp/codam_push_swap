/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 15:47:12 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:55:50 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/* static void	ft_delete(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*new;
	char	*content;

	content = ft_strdup("This is the content");
	new = ft_lstnew(content);
	ft_lstdelone(new, ft_delete);
	return (0);
} */
