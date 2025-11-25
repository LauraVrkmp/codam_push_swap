/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 13:00:42 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/06 13:17:19 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n%d\n%d\n", ft_isascii('^'), ft_isascii('`'), ft_isascii(']'));
	return (0);
} */
