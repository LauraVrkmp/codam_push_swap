/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 13:32:04 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 19:44:11 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_strncmp("ABC", "ABc", 2));
	printf("%d\n", ft_strncmp("ABC", "ABC", 3));
	printf("%d\n", ft_strncmp("Abc", "ABc", 1));
	return (0);
} */
