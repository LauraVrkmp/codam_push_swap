/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 12:37:09 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 19:22:54 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *src)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	while (*src++)
		i++;
	return (i);
}

/* int	main(void)
{
	size_t		result;
	char		dst[] = "ABCD";
	const char	src[] = "DEF";

	result = ft_strlcpy(dst, src, 3);
	printf("Length: %zu, dst: %s\n", result, dst);
	return (0);
} */
