/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:55:49 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/06 13:00:06 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n%d\n%d\n", ft_isalnum('$'), ft_isalnum('9'), ft_isalnum('a'));
	return (0);
} */
