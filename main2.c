/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:13:58 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/19 19:08:18 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int og;
    int ft;

    /* Complex combinations */
    printf("\n=== Complex Flag Combinations ===\n");
    og = printf("[%+10.5d]", 42);
    ft = ft_printf("[%+10.5d]", 42);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%+10.5d]", -42);
    ft = ft_printf("[%+10.5d]", -42);
    printf(" OG: %d | FT: %d\n", og, ft);

    /* Width + precision + flags */
    printf("\n=== Width + Precision + Flags ===\n");
    og = printf("[%#-15.10x]", 12345);
    ft = ft_printf("[%#-15.10x]", 12345);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%.10d]", -12345);
    ft = ft_printf("[%.10d]", -12345);
    printf(" OG: %d | FT: %d\n", og, ft);

    /* Edge cases */
    printf("\n=== Edge Cases ===\n");
    og = printf("[%+.d]", 0);
    ft = ft_printf("[%+.d]", 0);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%#.x]", 0);
    ft = ft_printf("[%#.x]", 0);
    printf(" OG: %d | FT: %d\n", og, ft);

    /* INT_MIN/MAX tests */
    printf("\n=== INT_MIN/MAX with Flags ===\n");
    og = printf("[%+15.10d]", INT_MIN);
    ft = ft_printf("[%+15.10d]", INT_MIN);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%15.10d]", INT_MAX);
    ft = ft_printf("[%15.10d]", INT_MAX);
    printf(" OG: %d | FT: %d\n", og, ft);

    /* Mixed precision tests */
    printf("\n=== Mixed Precision Tests ===\n");
    og = printf("[%8.3d|%.0d|%5.d|%.d]", 42, 42, 42, 42);
    ft = ft_printf("[%8.3d|%.0d|%5.d|%.d]", 42, 42, 42, 42);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%8.3d|%.0d|%5.d|%.d]", 0, 0, 0, 0);
    ft = ft_printf("[%8.3d|%.0d|%5.d|%.d]", 0, 0, 0, 0);
    printf(" OG: %d | FT: %d\n", og, ft);

    /* String precision and width */
    printf("\n=== String Tests ===\n");
    og = printf("[%15.10s]", "Hello World!");
    ft = ft_printf("[%15.10s]", "Hello World!");
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%-15.10s]", "Hello World!");
    ft = ft_printf("[%-15.10s]", "Hello World!");
    printf(" OG: %d | FT: %d\n", og, ft);

    /* Hex special cases */
    printf("\n=== Hex Special Cases ===\n");
    og = printf("[%#-15.10x]", 0);
    ft = ft_printf("[%#-15.10x]", 0);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%#15X]", INT_MIN);
    ft = ft_printf("[%#15X]", INT_MIN);
    printf(" OG: %d | FT: %d\n", og, ft);

    /* Flag precedence tests */
    printf("\n=== Flag Precedence ===\n");
    og = printf("[%+d|%+d]", 42, 42);
    ft = ft_printf("[%+d|%+d]", 42, 42);
    printf(" OG: %d | FT: %d\n", og, ft);

    og = printf("[%.3d|%.5d]", 42, 42);
    ft = ft_printf("[%.3d|%.5d]", 42, 42);
    printf(" OG: %d | FT: %d\n", og, ft);

    return (0);
}