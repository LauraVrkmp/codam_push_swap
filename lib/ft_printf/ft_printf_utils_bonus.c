/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:41 by laveerka      #+#    #+#                 */
/*   Updated: 2025/12/03 10:15:30 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	fill_str(char **str, char format, unsigned long long addr, \
unsigned int number)
{
	char	*hex_values;
	int		i;

	i = 19;
	if (format == 'x' || format == 'p')
		hex_values = "0123456789abcdef";
	else if (format == 'X')
		hex_values = "0123456789ABCDEF";
	if (format == 'x' || format == 'X')
	{
		while (number > 0)
		{
			(*str)[i--] = hex_values[number % 16];
			number /= 16;
		}
	}
	else if (format == 'p')
	{
		while (addr > 0)
		{
			(*str)[i--] = hex_values[addr % 16];
			addr /= 16;
		}
	}
	return (i);
}

size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	spacing_zeros(int *spacing, char filler)
{
	(*spacing)--;
	return (write(1, &filler, 1));
}
