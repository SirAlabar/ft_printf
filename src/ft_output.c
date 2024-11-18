/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/12 10:53:00 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	unsigned int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_print_char(char c, t_flags *flags)
{
	int count;

	count = 0;
	if (flags->minus)
	{
		count += ft_putchar(c);
		count += ft_handle_width(flags->width, 1, 0);
	}
	else
	{
		count += ft_handle_width(flags->width, 1, 0);
		count += ft_putchar(c);		
	}
	return (count);
}

int ft_print_str(char *str, t_flags *flags)
{
	int count;
	int len;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	if (flags->minus)
	{
		write(1, str, len);
		count += ft_handle_width(flags->width - len, 1 , 0);
	}
	else
	{
		count += ft_handle_width(flags->width - len, 0, flags->zero);
		write(1, str, len);
	}
	count += len;
	return (count);
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