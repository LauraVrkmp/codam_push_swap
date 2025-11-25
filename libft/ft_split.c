/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 19:40:49 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/17 09:49:55 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substr_count(const char *s, char c)
{
	size_t	in_substr;
	size_t	counter;

	in_substr = 0;
	counter = 0;
	while (*s)
	{
		if (*s == c && in_substr == 1)
			in_substr = 0;
		else if (*s != c && in_substr == 0)
		{
			in_substr = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static int	ft_find_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_string_fill(char *start, char **array, int counter, char c)
{
	int		i;
	int		end_i;

	i = 0;
	while (i < counter)
	{
		end_i = ft_find_c(start, c);
		array[i] = ft_substr(start, 0, end_i);
		if (array[i] == NULL)
		{
			while (i >= 0)
				free(array[i--]);
			free(array);
			return (NULL);
		}
		start += end_i;
		while (*start == c)
			start++;
		i++;
	}
	return (array);
}

static char	**ft_null_term(const char *s)
{
	char	**array;

	if (*s == '\0')
	{
		array = malloc(sizeof(char *));
		if (array == NULL)
			return (NULL);
		array[0] = NULL;
		return (array);
	}
	array = malloc(sizeof(char *) * 2);
	if (array == NULL)
		return (NULL);
	array[0] = ft_strdup(s);
	if (array[0] == NULL)
	{
		free(array);
		return (NULL);
	}
	array[1] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	int		counter;
	char	*start;
	char	**array;

	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return (ft_null_term(s));
	counter = ft_substr_count(s, c);
	array = malloc(sizeof(char *) * (counter + 1));
	if (array == NULL)
		return (NULL);
	start = (char *)s;
	while (*start == c)
		start++;
	array = ft_string_fill(start, array, counter, c);
	if (array == NULL)
		return (NULL);
	array[counter] = NULL;
	return (array);
}

/* int	main(void)
{
	char	c;
	char	*string;
	char	**result;

	string = "3Split33 this3333 string on threes";
	c = '3';
	result = ft_split(string, c);
	while (*result != NULL)
		printf("%s\n", *result++);
	return (0);
} */
