/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 13:24:31 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 18:40:21 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = s;
	while (i < n)
		p[i++] = c;
	return (s);
}

/* int	main(void)
{
	int		i;
	char	s[] = "First string, replace me\n";

	i = 0;
	ft_memset((void *)s, 't', 16);
	ft_memset((void *)s, 'r', 5);
	while (i < 26)
		printf("%c", s[i++]);
	return (0);
} */
