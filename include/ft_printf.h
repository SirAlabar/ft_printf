/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:19 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 21:10:27 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/*
**                              HEADERS
*/
# include "../libft/libft.h"
# include <stdarg.h> // library for args
/*
**                              BOOLEAN
*/
# define TRUE 1
# define FALSE 0
/*
**                              STRUCT DECLARATIONS
*/
typedef struct s_flags
{
   int width;      // Minimum field width - ex: %5d = "   42"
   int precision;  // Precision after decimal - ex: %.5d = "00042"
   int minus;      // Left-align output - ex: %-5d = "42   "
   int zero;       // Pad with zeros (not spaces) - ex: %05d = "00042" 
   int hash;       // Add "0x" or "0X" prefix for hex - ex: %#x = "0x2a"
   int space;      // Add space before positive numbers - ex: % d = " 42"
   int plus;       // Add plus before positive numbers - ex: %+d = "+42"
   int type;       // Conversion type (c,s,p,d,i,u,x,X,%)
} t_flags;

/*
**                              FUNCTION PROTOTYPES
*/

/* Core functions */
int         ft_printf(const char *format, ...);
int         ft_format(const char *format, unsigned int *i, va_list args, t_flags *flags);

/* Format handling */
t_flags     *ft_init_flags(void);
void        ft_reset_flags(t_flags *flags);
int         ft_parse_flags(const char *format, unsigned int *i, t_flags *flags);
int         ft_handle_width(int width, int minus, int has_zero);

/* Output functions */
int         ft_putchar(char c);
int         ft_putstr(const char *s);
int         ft_print_char(char c, t_flags *flags);
int         ft_print_str(char *str, t_flags *flags);
unsigned int	ft_print_hex(unsigned long nb, t_flags *flags, int is_recursive);
int         ft_print_decimal(long n, t_flags *flags);
int         ft_print_unsigned(unsigned int n);
int         ft_print_pointer(size_t ptr, t_flags *flags);

#endif