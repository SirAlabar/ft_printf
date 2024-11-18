/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:21:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:11:21 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_decimal(long n, t_flags *flags)
{
    int	count;

    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        n = -n;
    }
    else if (flags->plus)
        count += ft_putchar('+');
    else if (flags->space)
        count += ft_putchar(' ');
    if (n < 10)
        count += ft_putchar(n + '0');
    else
    {
        count += ft_print_decimal(n / 10, flags);
        count += ft_putchar((n % 10) + '0');
    }
    return (count);
}

int ft_handle_width(int width, int minus, int has_zero)
{
    int     count;
    char    c;

    count = 0;
    if (has_zero && !minus)
        c = '0';
    else
        c = ' ';
    while (width > 0)
    {
        count += write(1, &c, 1);
        width--;
    }
    return (count);
}

int ft_print_pointer(size_t ptr, t_flags *flags)
{
   int	count;

   count = 0;
   if (!ptr)
       return (ft_putstr("(nil)"));
   count += ft_putstr("0x");
   count += ft_print_hex(ptr, flags, 0);
   return (count);
}
int ft_format(const char *format, unsigned int *i, va_list args, t_flags *flags)
{
    int     count;

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
   else if (format[*i] == 'x' || format[*i] == 'X')
   {
       flags->type = format[*i];
       count += ft_print_hex(va_arg(args, unsigned int), flags, 0);
   }
    else if (format[*i] == '%')
        count += ft_putchar('%');
    (*i)++;
    return (count);
}
