/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:35:27 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_sign(t_flags *flags, long number)
{
    if (number < 0)
        return (ft_putchar('-'));
    if (flags->plus)
        return (ft_putchar('+'));
    if (flags->space)
        return (ft_putchar(' '));
    return (0);
}

int ft_decimal_len(long n)
{
    int len;

    len = 1;
    if (n < 0)
        n = -n;
    while (n >= 10)
    {
        n /= 10;
        len++;
    }
    return (len);
}

int ft_print_left_dec(t_flags *flags, long number)
{
    unsigned int count;
    int width;
    int len;

    count = 0;
    len = ft_decimal_len(number);
    
    count += ft_print_sign(flags, number);
    
    if (number < 0)
        number = -number;

    if (flags->precision > len)
    {
        width = flags->precision - len;
        ft_put_width(width, '0', &count);
    }

    if (!(number == 0 && flags->precision == 0))
        count += ft_print_decimal_base(number, flags, 0);

    if (flags->width > (int)count)
    {
        width = flags->width - count;
        ft_put_width(width, ' ', &count);
    }
    return (count);
}

int ft_print_left_hex(t_flags *flags, unsigned long number)
{
    unsigned int count;
    int len;
    int width;

    count = 0;
    len = ft_hex_len(number);
    
    if (flags->hash && number != 0)
        ft_put_prefix(flags->type, &count);

    if (flags->precision > len)
    {
        width = flags->precision - len;
        ft_put_width(width, '0', &count);
    }

    if (!(number == 0 && flags->precision == 0))
        count += ft_print_hex(number, flags, 1);

    if (flags->width > (int)count)
    {
        width = flags->width - count;
        ft_put_width(width, ' ', &count);
    }
    return (count);
}

int ft_print_str_left(char *str, t_flags *flags)
{
    int count;
    int len;
    int width;

    count = 0;
    if (!str)
        str = "(null)";
    len = ft_strlen(str);
    if (flags->precision >= 0 && flags->precision < len)
        len = flags->precision;
        
    write(1, str, len);
    count += len;
    
    width = flags->width - len;
    while (width > 0)
    {
        count += ft_putchar(' ');
        width--;
    }
    return (count);
}