/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 20:29:05 by hluiz-ma         ###   ########.fr       */
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

int    ft_handle_zero_precision(t_flags *flags)
{
    unsigned int    count;

    count = 0;
    while (count < (unsigned int)flags->width)
        count += write(1, " ", 1);
    return (count);
}

void    ft_put_precision_zeros(int len, unsigned int *count)
{
    while (len-- > 0)
        *count += write(1, "0", 1);
}

void    ft_put_spaces(int len, unsigned int *count)
{
    while (len-- > 0)
        *count += write(1, " ", 1);
}

int    ft_print_left_dec(t_flags *flags, long number)
{
	unsigned int	count;
	int		len;
	int		pad_len;

	count = 0;
	if (flags->precision == 0 && number == 0)
		return (ft_handle_zero_precision(flags));
	len = ft_decimal_len(number);
	if (flags->precision > len)
	{
		count += ft_print_sign(flags, number);
		if (number < 0)
			number = -number;
		pad_len = flags->precision - len;
		ft_put_precision_zeros(pad_len, &count);
		count += ft_print_decimal_base(number, NULL, 1);
	}
	else
	{
		count += ft_print_sign(flags, number);
		if (number < 0)
			number = -number;
		count += ft_print_decimal_base(number, NULL, 1);
	}
	ft_put_spaces(flags->width - count, &count);
	return (count);
}

int    ft_print_left_hex(t_flags *flags, unsigned int number)
{
    unsigned int    count;
    int             len;
    int             pad_len;

    count = 0;
    if (flags->precision == 0 && number == 0)
        return (ft_handle_zero_precision(flags));
    len = ft_hex_len(number);
    if (flags->hash && number != 0)
    {
        if (flags->type == 'X')
            count += write(1, "0X", 2);
        else
            count += write(1, "0x", 2);
    }
    pad_len = flags->precision > len ? flags->precision - len : 0;
    ft_put_precision_zeros(pad_len, &count);
    count += ft_print_hex(number, flags, 1);
    ft_put_spaces(flags->width - count, &count);
    return (count);
}

int    ft_print_str_left(char *str, t_flags *flags)
{
    unsigned int    count;
    int             len;

    count = 0;
    if (!str)
        str = "(null)";
    len = ft_strlen(str);
    if (flags->precision >= 0 && flags->precision < len)
        len = flags->precision;
    write(1, str, len);
    count = len;
    ft_put_spaces(flags->width - count, &count);
    return (count);
}