/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 13:55:36 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 18:20:24 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	char	*start;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	start = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (start);
}

/* int	main(void)
{
	const char	s1[] = "Appending this ";
	const char	s2[] = "to that.";
	char		*result;

	result = ft_strjoin(s1, s2);
	printf("%s\n", result);
	return (0);
} */
