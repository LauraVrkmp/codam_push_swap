/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 13:24:37 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/14 15:57:39 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*dup;
	char	*start;

	length = ft_strlen(s);
	dup = malloc((sizeof(char) * (length + 1)));
	if (dup == NULL)
		return (NULL);
	start = dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (start);
}

/* int	main(void)
{
	char	orig[] = "Copy this";
	char	*copy;

	copy = ft_strdup(orig);
	printf("%s\n", copy);
	free(copy);
	return (0);
} */
