/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:21:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/13 18:54:08 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags *ft_init_flags(void)
{
    t_flags	*flags;

    flags = (t_flags *)malloc(sizeof(t_flags));
    if (!flags)
        return (NULL);
    ft_reset_flags(flags);
    return (flags);
}

void    ft_reset_flags(t_flags *flags)
{
    flags->width = 0;
    flags->precision = -1;
    flags->minus = 0;
    flags->zero = 0;
    flags->hash = 0;
    flags->space = 0;
    flags->plus = 0;
    flags->type = 0;
}

static int ft_is_flag(char c)
{
    return (c == '-' || c == '0' || c == '.' || c == '#' || 
            c == ' ' || c == '+' || ft_isdigit(c));
}

int ft_parse_flags(char *format, unsigned int *i, t_flags *flags)
{
    ft_reset_flags(flags);
    while(format[*i] && ft_is_flag(format[*i]))
    {
        if (format[*i] == '-')
            flags->minus = 1;
        else if (format[*i] == '0' && !flags->width && !flags->minus)
            flags->zero = 1;
        else if (format[*i] == '#')
            flags->hash = 1;
        else if (format[*i] == ' ' && !flags->plus)
            flags->space = 1;
        else if (format[*i] == '+')
            flags->plus = 1;
        else if ((format[*i] == '.'))
        {
            (*i)++;
            flags->precision = ft_atoi(format + *i);
            while (ft_isdigit(format[*i]))
                (*i)++;
            continue;
        }
        else if (ft_isdigit(format[*i]))
            flags->width = ft_atoi(format + *i);
        (*i)++;
    }
    flags->type = format[*i];
    return (1);
}
