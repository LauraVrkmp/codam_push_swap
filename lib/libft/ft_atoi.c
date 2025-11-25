/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/13 12:08:30 by laveerka      #+#    #+#                 */
/*   Updated: 2025/10/15 20:16:53 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		if (!(ft_isdigit(*nptr)))
			return (0);
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

/* int	main(void)
{
	printf("%d\n", ft_atoi("1234"));
	printf("%d\n", ft_atoi("-542"));
	printf("%d\n", ft_atoi("abc"));
	printf("%d\n", ft_atoi(""));
	return (0);
} */
