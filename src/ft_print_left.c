/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 18:21:03 by hluiz-ma         ###   ########.fr       */
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
    unsigned int    count;
    int             len;
    int             zeros;
    int             spaces;

    count = 0;
    len = ft_decimal_len(number);
    count += ft_print_sign(flags, number);
    if (number < 0)
        number = -number;
    zeros = (flags->precision > len) ? flags->precision - len : 0;
    while (zeros-- > 0)
        count += write(1, "0", 1);
    if (!(number == 0 && flags->precision == 0))
        count += ft_print_decimal_base(number, NULL, 1);
    spaces = flags->width - count;
    while (spaces-- > 0)
        count += write(1, " ", 1);
    return (count);
}

int ft_print_left_hex(t_flags *flags, unsigned int number)
{
    unsigned int    count;
    unsigned int    len;
    int             zeros;
    int             spaces;

    count = 0;
    len = ft_hex_len(number);
    if (flags->hash && number != 0)
    {
        if (flags->type == 'X')
            count += write(1, "0X", 2);
        else
            count += write(1, "0x", 2);
    }
    zeros = (flags->precision > (int)len) ? flags->precision - len : 0;
    while (zeros-- > 0)
        count += write(1, "0", 1);
    if (!(number == 0 && flags->precision == 0))
        count += ft_print_hex(number, flags, 1);
    spaces = flags->width - count;
    while (spaces-- > 0)
        count += write(1, " ", 1);
    return (count);
}

int ft_print_str_left(char *str, t_flags *flags)
{
    unsigned int    count;
    int             len;
    int             spaces;

    count = 0;
    if (!str)
        str = "(null)";
    len = ft_strlen(str);
    if (flags->precision >= 0 && flags->precision < len)
        len = flags->precision;
    write(1, str, len);
    count += len;
    spaces = flags->width - len;
    while (spaces-- > 0)
        count += write(1, " ", 1);
    return (count);
}