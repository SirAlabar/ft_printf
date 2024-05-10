/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:21:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/10 21:14:32 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_format(char *format, int *i, va_list args)
{
    unsigned int count;        

    count = 0;
    if(format[*i] == 'c')
    {
        count += ft_putchar(va_arg(args, int));  
    }
    if(format[*i] == 's')
    {
        count += ft_putstr(va_arg(args, char *));
    }
    (*i)++;
    return(count);     
}