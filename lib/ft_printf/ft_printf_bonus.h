/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: laveerka <laveerka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/22 13:54:36 by laveerka      #+#    #+#                 */
/*   Updated: 2025/11/25 17:08:05 by laveerka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		period;
	int		hash;
	int		space;
	int		plus;
	char	type;
	int		width;
	int		precision;
	int		neg;
	int		num_zero;
}	t_flags;

int		fill_str(char **str, char format, unsigned long long addr, \
unsigned int number);
void	ft_bzero(void *s, size_t n);
size_t	ft_intlen(int n);
char	*ft_itoa_printf(int signednum, unsigned int unsignednum, char type);
int		ft_printf(const char *format, ...);
size_t	ft_strlen_gnl(const char *s);
int		parse_width_prec(t_flags *type, const char *format);
int		print_char(t_flags *type, va_list arg);
int		print_hex(t_flags *type, va_list arg);
int		print_number(t_flags *type, va_list arg);
int		print_pointer(t_flags *type, va_list arg);
int		print_string(t_flags *type, va_list arg);
int		spacing_zeros(int *spacing, char filler);