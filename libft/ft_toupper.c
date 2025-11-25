/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 12:59:13 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/09 13:03:06 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* int	main(void)
{
	printf("%c, %c, %c\n", ft_toupper('T'), ft_toupper('c'), ft_toupper('&'));
	return (0);
} */
