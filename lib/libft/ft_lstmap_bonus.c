/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 09:06:30 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:56:39 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* static void	*ft_iterate(void *content)
{
	char	*iterable;
	char	*copy;
	char	*ptr;

	iterable = (char *)content;
	copy = ft_strdup(iterable);
	if (copy == NULL)
		return (NULL);
	ptr = copy;
	while (*ptr)
	{
		*ptr += 1;
		ptr++;
	}
	return (copy);
}

static void	ft_delete(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*new_one;
	t_list	*new_two;
	t_list	*new_list;
	char	*string_one;
	char	*string_two;

	string_one = ft_strdup("Content here");
	new_one = ft_lstnew(string_one);
	string_two = ft_strdup("Also here");
	new_two = ft_lstnew(string_two);
	ft_lstadd_back(&new_one, new_two);
	new_list = ft_lstmap(new_one, ft_iterate, ft_delete);
	while (new_list)
	{
		printf("%s\n", (char *)new_list->content);
		new_list = new_list->next;
	}
	return (0);
} */
