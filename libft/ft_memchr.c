/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 13:38:58 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 19:58:48 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*test;

	test = (unsigned char *)s;
	while (n--)
	{
		if (*test == (unsigned char)c)
			return (test);
		test++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	s[] = "Testing\n";
	char		*result;
	int			c = 'g';

	result = ft_memchr(s, c, 5);
	printf("%s\n", result);
	return (0);
} */
