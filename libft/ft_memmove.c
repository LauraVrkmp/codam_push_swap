/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 12:47:44 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 21:00:38 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (dest == NULL && src == NULL && n)
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (p_dest < p_src)
	{
		while (n--)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += n;
		p_src += n;
		while (n--)
			*--p_dest = *--p_src;
	}
	return (dest);
}

/* int	main(void)
{
	const char	src[] = "Source string\n";
	char		dest[] = "Destiny\n";
	const char	*dest_two = src + 2;

	ft_memmove(dest, src, 5);
	printf("%s\n", dest);
	ft_memmove((void *)dest_two, src, 5);
	printf("%s\n", dest_two);
	return (0);
} */
