/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 12:46:33 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 19:32:44 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0 && dst == NULL)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst)
	{
		dst++;
		i++;
	}
	while (i < (size - 1) && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}

/* int	main(void)
{
	char	dst[] = "Start of ";
	const char	src[] = "the string.";
	size_t	size;

	size = ft_strlcat(dst, src, 35);
	printf("Dest: %s, size: %zu\n", dst, size);
	return (0);
} */
