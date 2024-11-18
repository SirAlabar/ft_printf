/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:21:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:42:34 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_dec_flags(long n, t_flags *flags, int has_sign, unsigned int *count)
{
   int	width;
   int	len;

   len = 1;
   while (n >= 10)
   {
       n /= 10;
       len++;
   }
   if (flags->precision > len)
   {
       width = flags->precision - len;
       ft_put_width(width, '0', count);
   }
   else if (flags->width > len + has_sign)
   {
       width = flags->width - (len + has_sign);
       if (flags->minus)
           ft_put_width(width, ' ', count);
       else if (flags->zero && flags->precision == -1)
           ft_put_width(width, '0', count);
       else
           ft_put_width(width, ' ', count);
   }
}
static int	ft_print_decimal_base(long n)
{
    unsigned int	count;

    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        n = -n;
    }
    if (n < 10)
        count += ft_putchar(n + '0');
    else
    {
        count += ft_print_decimal_base(n / 10);
        count += ft_putchar((n % 10) + '0');
    }
    return (count);
}

int	ft_print_decimal(long n, t_flags *flags)
{
    unsigned int	count;
    int	has_sign;

    count = 0;
    has_sign = 0;
    if (flags)
    {
        if (n < 0 || flags->plus || flags->space)
            has_sign = 1;
        if (!flags->minus)
            ft_handle_dec_flags(n, flags, has_sign, &count);
        count += ft_print_decimal_base(n);
        if (flags->minus)
            ft_handle_dec_flags(n, flags, has_sign, &count);
    }
    else
        count += ft_print_decimal_base(n);
    return ((int)count);
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
