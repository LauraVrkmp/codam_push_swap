/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/14 10:39:55 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/14 10:39:57 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_find_length_neg(long n, int *is_neg, int *length)
{
	if (n < 0)
	{
		*is_neg = 1;
		(*length)++;
	}
	if (n == 0)
		(*length)++;
	while (n)
	{
		n /= 10;
		(*length)++;
	}
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		length;
	char	*string;
	long	nb;

	is_neg = 0;
	length = 0;
	nb = n;
	ft_find_length_neg(nb, &is_neg, &length);
	if (nb < 0)
		nb = -nb;
	string = malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	while (length-- > 0)
	{
		string[length] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_neg)
		string[0] = '-';
	return (string);
}

/* int	main(void)
{
	printf("%s\n%s\n%s\n", ft_itoa(1234), ft_itoa(-2147483648), ft_itoa(3));
	return (0);
} */