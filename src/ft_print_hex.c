/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:02:31 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_hex_len(unsigned int nb)
{
    int len;

    len = 0;
    if (nb == 0)
        return (1);
    while (nb > 0)
    {
        nb /= 16;
        len++;
    }
    return (len);
}

static void ft_put_prefix(char flag, unsigned int *count)
{
    if (flag == 'X')
        *count += ft_putstr("0X");
    else
        *count += ft_putstr("0x");
}

static void ft_put_width(int width, char c, unsigned int *count)
{
    while (width > 0)
    {
        *count += ft_putchar(c);
        width--;
    }
}

static void	ft_handle_hex_flags(unsigned long nb, int len, t_flags *flags, unsigned int *count)
{
    int	width;

    width = flags->width - len;
    if (!flags->minus && width > 0)
    {
        if (flags->zero && flags->precision == -1)
            ft_put_width(width, '0', count);
        else
            ft_put_width(width, ' ', count);
    }
    if (flags->hash && nb != 0)
    {
        width -= 2;
        ft_put_prefix(flags->type, count);
    }
    if (flags->precision > len)
        ft_put_width(flags->precision - len, '0', count);
}

unsigned int	ft_print_hex(unsigned long nb, t_flags *flags)
{
    unsigned int	count;
    char		*symbols;
    int			len;

    count = 0;
    if (flags->type == 'X')
        symbols = "0123456789ABCDEF";
    else
        symbols = "0123456789abcdef";
    len = ft_hex_len(nb);
    ft_handle_hex_flags(nb, len, flags, &count);
    if (nb == 0 && flags->precision == 0)
        return (count);
    if (nb < 16)
        count += ft_putchar(symbols[nb]);
    else
    {
        count += ft_print_hex(nb / 16, flags);
        count += ft_putchar(symbols[nb % 16]);
    }
    return (count);
}
