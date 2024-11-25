/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:44:43 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_put_prefix(char flag, unsigned int *count)
{
    if (flag == 'X')
        *count += ft_putstr("0X");
    else
        *count += ft_putstr("0x");
}

void ft_put_width(int width, char c, unsigned int *count)
{
	while (width > 0)
	{
		*count += write(1, &c, 1);
		width--;
	}
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
