/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 11:30:38 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/14 11:40:02 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			length;
	char			*result;
	unsigned int	i;

	i = 0;
	length = ft_strlen(s);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* static char	ft_upgrade(unsigned int index, char c)
{
	(void)index;
	
	return (c + 1);
}

int	main(void)
{
	char	initial[] = "Upgrade by 1.";
	char	*result;

	result = ft_strmapi(initial, ft_upgrade);
	printf("%s\n", result);
	free(result);
	return (0);
} */
