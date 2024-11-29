/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:21:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/28 22:27:11 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal_base(long n, t_flags *flags, int is_recursive)
{
	unsigned int	count;

	count = 0;
	if (n == 0 && flags && flags->precision == 0)
		return (count);
	if (n == -2147483648)
	{
		if (!is_recursive)
		{
			n = -(n + 1);
			count += ft_print_decimal_base(n / 10, flags, 1);
			count += ft_putchar('8');
			return (count);
		}
	}
	else if (n < 0 && !is_recursive)
		n = -n;
	if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_print_decimal_base(n / 10, flags, 1);
		count += ft_putchar((n % 10) + '0');
	}
	return (count);
}

int	ft_print_decimal(long n, t_flags *flags)
{
	unsigned int	count;
	int				has_sign;

	count = 0;
	has_sign = 0;
	if (n < 0 || flags->plus || flags->space)
		has_sign = 1;
	if (!flags)
		return (ft_print_decimal_base(n, NULL, 0));
	if (flags->precision == 0 && n == 0)
		return (ft_handle_zero_precision(flags));
	if (!flags->minus)
		ft_handle_dec_flags(n, flags, has_sign, &count);
	if (n < 0 && flags->zero && flags->precision == -1 && !flags->minus)
		n = -n;
	count += ft_print_decimal_base(n, flags, 0);
	if (flags->minus && flags->width > (int)count)
		ft_put_spaces(flags->width - count, &count);
	return (count);
}

int	ft_print_pointer(size_t ptr, t_flags *flags)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_print_hex(ptr, flags, 0);
	return (count);
}

static int	ft_format_basic(const char *format, unsigned int *i,
		va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	else if (format[*i] == 's')
	{
		if (flags->minus)
			count += ft_print_str_left(va_arg(args, char *), flags);
		else
			count += ft_print_str(va_arg(args, char *), flags);
	}
	else if (format[*i] == 'p')
		count += ft_print_pointer(va_arg(args, size_t), flags);
	else if (format[*i] == 'd' || format[*i] == 'i')
	{
		if (flags->minus)
			count += ft_print_left_dec(flags, va_arg(args, int));
		else
			count += ft_print_decimal(va_arg(args, int), flags);
	}
	return (count);
}

int	ft_format(const char *format, unsigned int *i, va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p'
		|| format[*i] == 'd' || format[*i] == 'i')
		count += ft_format_basic(format, i, args, flags);
	else if (format[*i] == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
	{
		flags->type = format[*i];
		if (flags->minus)
			count += ft_print_left_hex(flags, va_arg(args, unsigned int));
		else
			count += ft_print_hex(va_arg(args, unsigned int), flags, 0);
	}
	else if (format[*i] == '%')
		count += ft_putchar('%');
	(*i)++;
	return (count);
}
