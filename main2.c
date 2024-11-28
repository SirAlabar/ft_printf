/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:13:58 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/28 22:29:09 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int output_OG;
    int output_FT;

/////////////////////////////////
//  PRECISION WITH ZERO CASES   //
/////////////////////////////////
    ft_printf("----------------PRECISION ZERO TESTS---------------\n");
    output_OG = printf("OG -> [%.0d]\n", 0);
    output_FT = ft_printf("FT -> [%.0d]\n", 0);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%.0d]\n", 42);
    output_FT = ft_printf("FT -> [%.0d]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//  WIDTH WITH PRECISION ZERO   //
/////////////////////////////////
    ft_printf("----------------WIDTH WITH PRECISION ZERO---------------\n");
    output_OG = printf("OG -> [%5.0d]\n", 0);
    output_FT = ft_printf("FT -> [%5.0d]\n", 0);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%5.0d]\n", 42);
    output_FT = ft_printf("FT -> [%5.0d]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//  PLUS WITH PRECISION ZERO    //
/////////////////////////////////
    ft_printf("----------------PLUS WITH PRECISION ZERO---------------\n");
    output_OG = printf("OG -> [%+.0d]\n", 0);
    output_FT = ft_printf("FT -> [%+.0d]\n", 0);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%+.0d]\n", 42);
    output_FT = ft_printf("FT -> [%+.0d]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//  HASH WITH PRECISION ZERO    //
/////////////////////////////////
    ft_printf("----------------HASH WITH PRECISION ZERO---------------\n");
    output_OG = printf("OG -> [%#.0x]\n", 0);
    output_FT = ft_printf("FT -> [%#.0x]\n", 0);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%#.0x]\n", 42);
    output_FT = ft_printf("FT -> [%#.0x]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//  SPACE WITH PRECISION ZERO   //
/////////////////////////////////
    ft_printf("----------------SPACE WITH PRECISION ZERO---------------\n");
    output_OG = printf("OG -> [% .0d]\n", 0);
    output_FT = ft_printf("FT -> [% .0d]\n", 0);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [% .0d]\n", 42);
    output_FT = ft_printf("FT -> [% .0d]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     MIXED COMBINATIONS      //
/////////////////////////////////
    ft_printf("----------------MIXED COMBINATIONS---------------\n");
    output_OG = printf("OG -> [%+5.0d]\n", 0);
    output_FT = ft_printf("FT -> [%+5.0d]\n", 0);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [% 5.0d]\n", 42);
    output_FT = ft_printf("FT -> [% 5.0d]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     EXTREME CASES           //
/////////////////////////////////
    ft_printf("----------------EXTREME CASES---------------\n");
    output_OG = printf("OG -> [%+20.15d]\n", INT_MAX);
    output_FT = ft_printf("FT -> [%+20.15d]\n", INT_MAX);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%+20.15d]\n", INT_MIN);
    output_FT = ft_printf("FT -> [%+20.15d]\n", INT_MIN);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     STRING PRECISION        //
/////////////////////////////////
    ft_printf("----------------STRING PRECISION---------------\n");
    output_OG = printf("OG -> [%20.5s]\n", "Hello World");
    output_FT = ft_printf("FT -> [%20.5s]\n", "Hello World");
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%-20.5s]\n", "Hello World");
    output_FT = ft_printf("FT -> [%-20.5s]\n", "Hello World");
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     MIXED ALL FLAGS         //
/////////////////////////////////
    ft_printf("----------------MIXED ALL FLAGS---------------\n");
    output_OG = printf("OG -> [%+-20.10d]\n", 42);
    output_FT = ft_printf("FT -> [%+-20.10d]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%#-20.10x]\n", 42);
    output_FT = ft_printf("FT -> [%#-20.10x]\n", 42);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    /////////////////////////////////
//     PRECISION AND WIDTH     //
/////////////////////////////////
    ft_printf("----------------PRECISION AND WIDTH---------------\n");
    output_OG = printf("OG -> [%25.10d]\n", 123456);
    output_FT = ft_printf("FT -> [%25.10d]\n", 123456);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%10.15d]\n", -987654);
    output_FT = ft_printf("FT -> [%10.15d]\n", -987654);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     ZERO FLAG TESTS         //
/////////////////////////////////
    ft_printf("----------------ZERO FLAG TESTS---------------\n");
    output_OG = printf("OG -> [%030d]\n", -789123);
    output_FT = ft_printf("FT -> [%030d]\n", -789123);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%20d]\n", 456789);
    output_FT = ft_printf("FT -> [%20d]\n", 456789);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     HEX SPECIAL CASES      //
/////////////////////////////////
    ft_printf("----------------HEX SPECIAL CASES---------------\n");
    output_OG = printf("OG -> [%#15x]\n", 52845);
    output_FT = ft_printf("FT -> [%#15x]\n", 52845);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%#15X]\n", 998244353);
    output_FT = ft_printf("FT -> [%#15X]\n", 998244353);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     SIGN HANDLING          //
/////////////////////////////////
    ft_printf("----------------SIGN HANDLING---------------\n");
    output_OG = printf("OG -> [%+15d]\n", 9876543);
    output_FT = ft_printf("FT -> [%+15d]\n", 9876543);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [% 15d]\n", -424242);
    output_FT = ft_printf("FT -> [% 15d]\n", -424242);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     STRING EDGE CASES      //
/////////////////////////////////
    ft_printf("----------------STRING EDGE CASES---------------\n");
    output_OG = printf("OG -> [%15.5s]\n", "Testing 123!");
    output_FT = ft_printf("FT -> [%15.5s]\n", "Testing 123!");
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%-15s]\n", "Hello, World 42!");
    output_FT = ft_printf("FT -> [%-15s]\n", "Hello, World 42!");
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     MIXED WIDTH TESTS      //
/////////////////////////////////
    ft_printf("----------------MIXED WIDTH TESTS---------------\n");
    output_OG = printf("OG -> [%+15d|%-15d]\n", 123987, 456654);
    output_FT = ft_printf("FT -> [%+15d|%-15d]\n", 123987, 456654);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%15.10d|%15d]\n", -789456, -321987);
    output_FT = ft_printf("FT -> [%15.10d|%15d]\n", -789456, -321987);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//     PRECISION EDGE CASES   //
/////////////////////////////////
    ft_printf("----------------PRECISION EDGE CASES---------------\n");
    output_OG = printf("OG -> [%.0d|%.d]\n", 789456, 123789);
    output_FT = ft_printf("FT -> [%.0d|%.d]\n", 789456, 123789);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    ft_printf("\n");

    output_OG = printf("OG -> [%.15d|%.0d]\n", 987654321, 123456789);
    output_FT = ft_printf("FT -> [%.15d|%.0d]\n", 987654321, 123456789);
    printf("OUTPUT OG = %d\n", output_OG);
    ft_printf("OUTPUT FT = %d\n", output_FT);

    return (0);
}