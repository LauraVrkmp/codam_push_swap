/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/17 09:06:00 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:56:06 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* static void	ft_iterate(void *content)
{
	char	*iterable;

	iterable = (char *)content;
	while (*iterable)
	{
		*iterable += 1;
		iterable++;
	}
}

int	main(void)
{
	t_list	*new_one;
	t_list	*new_two;
	char	*string_one;
	char	*string_two;

	string_one = ft_strdup("Content here");
	new_one = ft_lstnew(string_one);
	string_two = ft_strdup("Also here");
	new_two = ft_lstnew(string_two);
	ft_lstadd_back(&new_one, new_two);
	ft_lstiter(new_one, ft_iterate);
	while (new_one)
	{
		printf("%s\n", (char *)new_one->content);
		new_one = new_one->next;
	}
	return (0);
} */
