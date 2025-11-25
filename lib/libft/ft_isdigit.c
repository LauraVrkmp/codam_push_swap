/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:53:53 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/06 12:59:49 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n%d\n%d\n", ft_isdigit('6'), ft_isdigit('T'), ft_isdigit('h'));
	return (0);
} */
