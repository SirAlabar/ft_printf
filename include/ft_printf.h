/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:19 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/18 20:00:22 by hluiz-ma         ###   ########.fr       */
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
    int     width;
    int     precision;
    int     minus;
    int     zero;
    int     hash;
    int     space;
    int     plus;
    int     type;
}	t_flags;

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
unsigned int	ft_print_hex(unsigned int nb, char flag, t_flags *flags);
int         ft_print_decimal(long n, t_flags *flags);
int         ft_print_unsigned(unsigned int n);
int         ft_print_pointer(size_t ptr, t_flags *flags);

#endif