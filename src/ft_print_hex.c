/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:13:18 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/28 22:40:18 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nb)
{
	int	len;

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

static unsigned int	ft_print_hex_recursive(unsigned long nb, char *symbols)
{
	unsigned int	count;

	count = 0;
	if (nb < 16)
		count += ft_putchar(symbols[nb]);
	else
	{
		count += ft_print_hex_recursive(nb / 16, symbols);
		count += ft_putchar(symbols[nb % 16]);
	}
	return (count);
}

unsigned int	ft_print_hex(unsigned long nb, t_flags *flags, int is_recursive)
{
	unsigned int	count;
	char			*symbols;
	int				len;
	int				prefix_len;

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
	count += ft_print_hex_recursive(nb, symbols);
	if (!is_recursive && flags->minus)
	{
		prefix_len = 0;
		if (flags->hash && nb != 0)
			prefix_len = 2;
		ft_put_width(flags->width - len - prefix_len, ' ', &count);
	}
	return (count);
}
