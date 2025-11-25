/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 13:21:03 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 18:09:33 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

/* int	main(void)
{
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", ft_strlen("Trying this string"));
	printf("%zu\n", ft_strlen("Whoaw\n"));
	return (0);
} */
