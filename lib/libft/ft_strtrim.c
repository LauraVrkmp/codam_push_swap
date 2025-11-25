/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 14:47:54 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/14 11:30:07 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test_set(int c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = 0;
	while (s1[start] && ft_test_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_test_set(s1[end], set) && end >= start)
		end--;
	result = ft_substr(s1, (unsigned int)start, end - start + 1);
	if (result == NULL)
		return (NULL);
	return (result);
}

/* int	main(void)
{
	char	*test;
	
	test = ft_strtrim("4s3Trim this string54433", "345s");
	printf("%s\n", test);
	return (0);
} */
