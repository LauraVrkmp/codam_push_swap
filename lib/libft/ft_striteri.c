/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 11:38:52 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/14 11:55:16 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			length;

	i = 0;
	length = ft_strlen(s);
	while (i < length)
		f(i++, s++);
}

/* static void ft_upgrade(unsigned int index, char *c)
{
	(void)index;
	
	*c += 1;
}

int	main(void)
{
	char	initial[] = "Upgrade by 1.";

	ft_striteri(initial, ft_upgrade);
	printf("%s\n", initial);
	return (0);
} */