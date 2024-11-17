/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:48:39 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/13 19:47:50 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			args;
	t_flags			*flags;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	flags = ft_init_flags();
	if(!flags)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if(ft_parse_flags(format, &i, flags) == -1)
				count = -1;
			else
				count += ft_format(format, &i, args, flags);
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(args);
	free(flags);
	return (count);
}
