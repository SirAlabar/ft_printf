/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:10:23 by hluiz-ma         ###   ########.fr       */
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
   int	pad_len;

   width = flags->width - len;
   if (flags->hash && nb != 0)
       width = width - 2;
   pad_len = 0;
   if (flags->precision > len)
       pad_len = flags->precision - len;
   if (!flags->minus)
   {
       if (flags->zero && flags->precision == -1)
       {
           if (flags->hash && nb != 0)
               ft_put_prefix(flags->type, count);
           ft_put_width(width - pad_len, '0', count);
       }
       else
           ft_put_width(width - pad_len, ' ', count);
   }
   if (flags->hash && nb != 0 && !flags->zero)
       ft_put_prefix(flags->type, count);
   ft_put_width(pad_len, '0', count);
}

unsigned int	ft_print_hex(unsigned long nb, t_flags *flags, int is_recursive)
{
   unsigned int	count;
   char		*symbols;
   int			len;
   int			prefix_len;

   count = 0;
   if (flags->type == 'X')
       symbols = "0123456789ABCDEF";
   else
       symbols = "0123456789abcdef";
   len = ft_hex_len(nb);
   if (!is_recursive)
       ft_handle_hex_flags(nb, len, flags, &count);
   if (nb == 0 && flags->precision == 0)
       return (count);
   if (nb < 16)
       count += ft_putchar(symbols[nb]);
   else
   {
       count += ft_print_hex(nb / 16, flags, 1);
       count += ft_putchar(symbols[nb % 16]);
   }
   if (!is_recursive && flags->minus)
   {
       prefix_len = 0;
       if (flags->hash && nb != 0)
           prefix_len = 2;
       ft_put_width(flags->width - len - prefix_len, ' ', &count);
   }
   return (count);
}
