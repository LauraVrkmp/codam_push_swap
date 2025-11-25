/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 13:10:52 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 21:10:05 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	int				length;

	ch = (unsigned char)c;
	length = ft_strlen(s);
	s += length;
	while (length >= 0)
	{
		if (*s == ch)
			return ((char *)s);
		length--;
		s--;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	s[] = "Find the character\n";
	int			c = 'P';
	char		*result;

	result = ft_strrchr(s, c);
	printf("%s\n", result);
	return (0);
} */
