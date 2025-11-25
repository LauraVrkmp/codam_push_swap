/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 13:45:02 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 20:56:51 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_length;
	char	*result;

	s_length = ft_strlen(s);
	if (start >= s_length)
		return (ft_strdup(""));
	if (((size_t)start + len) > s_length)
		len = s_length - start;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

/* int	main(void)
{
	char	complete[] = "Take a piece of me";
	char	*sub;
	
	sub = ft_substr(complete, 5, 20);
	printf("%s\n", sub);
	return (0);
} */
