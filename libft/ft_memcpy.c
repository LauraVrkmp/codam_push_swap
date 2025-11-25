/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 13:56:20 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 21:04:50 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (dest == NULL && src == NULL && n)
		return (NULL);
	p_dest = dest;
	p_src = (const unsigned char *)src;
	while (n--)
		*p_dest++ = *p_src++;
	return (dest);
}

/* int	main(void)
{
	const char	src[] = "Source string\n";
	char		dest[] = "Destiny\n";

	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);
	return (0);
} */
