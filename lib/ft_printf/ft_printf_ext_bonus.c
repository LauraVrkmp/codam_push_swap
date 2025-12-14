/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ext_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 14:18:10 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/26 14:31:19 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_ext(const char *format, va_list args)
{
	int		char_count;
	int		length;
	t_flags	*type;

	char_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format = read_format(&type, ++format);
			if (type == NULL)
				return (-1);
			length = print_id(type, args);
			if (length == -1)
				return (-1);
			char_count += length;
			free(type);
		}
		else
			char_count += write(1, format++, 1);
	}
	return (char_count);
}
