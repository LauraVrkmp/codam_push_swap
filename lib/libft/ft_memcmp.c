/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 13:46:18 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 20:01:36 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
		i++;
	}
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_memcmp("ABC", "ABc", 3));
	printf("%d\n", ft_memcmp("ABC", "ABC", 3));
	printf("%d\n", ft_memcmp("ABC", "ABc", 3));
	return (0);
} */