/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 13:41:01 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/06 13:55:14 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = s;
	while (i < n)
		p[i++] = '\0';
}

/* int	main(void)
{
	char	string[] = "String here\n";
	printf("%s\n", string);
	ft_bzero(string, 3);
	printf("%s\n", string);
	return (0);
} */
