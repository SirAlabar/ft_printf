/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/28 22:27:08 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_width(int width, int minus, int has_zero)
{
	int		count;
	char	c;

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

int	ft_handle_zero_precision(t_flags *flags)
{
	unsigned int	count;
	int				i;

	count = 0;
	i = flags->width;
	if (flags->plus)
	{
		i--;
		if (i > 0)
			count += ft_handle_width(i, 0, 0);
		count += write(1, "+", 1);
	}
	else if (flags->space)
	{
		i--;
		if (i > 0)
			count += ft_handle_width(i, 0, 0);
		count += write(1, " ", 1);
	}
	else
		count += ft_handle_width(i, 0, 0);
	return (count);
}

void	ft_handle_dec_flags(long n, t_flags *flags, int has_sign,
		unsigned int *count)
{
	int		width;
	int		len;
	char	pad;
	long	num;

	num = n;
	if (n < 0)
		num = -n;
	len = ft_decimal_len(num);
	if (flags->precision > len)
	{
		width = flags->width - (flags->precision + has_sign);
		if (width > 0)
			ft_put_width(width, ' ', count);
		*count += ft_print_sign(flags, n);
		ft_put_width(flags->precision - len, '0', count);
	}
	else if (flags->width > len + has_sign)
	{
		width = flags->width - (len + has_sign);
		pad = ' ';
		if (flags->zero && flags->precision == -1)
		{
			pad = '0';
			*count += ft_print_sign(flags, n);
		}
		if (!flags->minus)
			ft_put_width(width, pad, count);
		if (pad == ' ')
			*count += ft_print_sign(flags, n);
	}
	else
		*count += ft_print_sign(flags, n);
}

void	ft_handle_hex_flags(unsigned long nb, int len, t_flags *flags,
		unsigned int *count)
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
