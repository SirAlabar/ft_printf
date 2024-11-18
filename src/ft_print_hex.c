/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 20:23:46 by hluiz-ma         ###   ########.fr       */
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

unsigned int	ft_print_hex(unsigned int nb, char flag, t_flags *flags)
{
   unsigned int	count;
   char		*symbols;
   int			len;
   int			width;

   count = 0;
   if (flag == 'X')
       symbols = "0123456789ABCDEF";
   else
       symbols = "0123456789abcdef";
   len = ft_hex_len(nb);
   width = flags->width - len;
   if (flags->hash && nb != 0)
   {
       width -= 2;
       ft_put_prefix(flag, &count);
   }
   if (!flags->minus && width > 0)
       ft_put_width(width, ' ', &count);
   if (nb < 16)
       count += ft_putchar(symbols[nb]);
   else
   {
       count += ft_print_hex(nb / 16, flag, flags);
       count += ft_print_hex(nb % 16, flag, flags);
   }
   if (flags->minus && width > 0)
       ft_put_width(width, ' ', &count);
   return (count);
}
