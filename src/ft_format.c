/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:21:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/13 18:54:08 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_decimal(long n, t_flags *flags)
{
    int count;

    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        return (ft_print_decimal(-n, flags) + 1);
    }
    else if (n >= 0 && flags->plus)
        count += ft_putchar('+');
    else if (n >= 0 && flags->space)
        count += ft_putchar(' ');
    if (n < 10)
        return (count + ft_putchar(n + '0'));
    else
    {
        count += ft_print_decimal(n / 10, flags);
        return (count + ft_print_decimal(n % 10, flags));
    }
}

int ft_print_unsigned(unsigned int n)
{
    int count;

    count = 0;
    if (n < 10)
        return (ft_putchar(n + '0'));
    else
    {
        count += ft_print_unsigned(n / 10);
        return (count + ft_print_unsigned(n % 10));
    }
}

static unsigned int	ft_print_p(size_t nb, size_t base, char flag)
{
	unsigned int	count;
	char			*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (nb < base)
		return (ft_putchar(symbols[nb]));
	else
	{
		count += ft_print_decimal(nb / base, base, flag);
		return (count + ft_print_decimal(nb % base, base, flag));
	}
	return (count);
}

int	ft_format(const char *format, unsigned int *i, va_list args, t_flags *flags)
{
	unsigned int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	else if (format[*i] == 's')
		count += ft_print_str(va_arg(args, char *), flags);
	else if (format[*i] == 'p')
		count += ft_print_pointer(va_arg(args, size_t), flags);		
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_print_decimal(va_arg(args, int), flags);
	else if (format[*i] == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));		
	else if (format[*i] == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 16, 'x');
	else if (format[*i] == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 16, 'X');
	else if (format[*i] == '%')
    {
		count += ft_print_char('%', flags);
		if (format[*i + 1] == '%' && format[*i + 2] == '\0')
            return(-1); 
	}
	(*i)++;
	return (count);
}
