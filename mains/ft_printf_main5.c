/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainxcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroccol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:14:06 by ebroccol          #+#    #+#             */
/*   Updated: 2025/01/09 13:14:17 by ebroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../ft_printf.h"

int	main()
{
	char	*str;
	void	*pointer;
	int		count;

	str = "miaooooo";
	pointer = NULL;
/*
	count = 120;
	ft_printf("\"%10c\"\n", 'm');
	ft_printf("\"%10.3s\"\n", str);
	ft_printf("Printf mio scrive: \"%10.3s\"\n", "miaooo");
	ft_printf("%i\n", count);
*/
	ft_printf("Mio Printf\n");
	count = ft_printf(" %c %c %c ", '0', 0, '1');
	ft_printf("\n%d\n", count);
	ft_printf("OG Printf\n");
	fflush(stdout); 
	count = printf(" %c %c %c ", '0', 0, '1');
	fflush(stdout); 
	ft_printf("\n%d\n", count);

	ft_printf("Mio Printf\n");
	count = ft_printf(" NULL %s NULL ", NULL);
	ft_printf("\n%d\n", count);
	ft_printf("OG Printf\n");
	fflush(stdout); 
	count = printf(" NULL %s NULL ", NULL);
	fflush(stdout); 
	ft_printf("\n%d\n", count);

	ft_printf("Mio Printf\n");
	count = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("\n%d\n", count);
	ft_printf("OG Printf\n");
	fflush(stdout); 
	count = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	fflush(stdout); 
	ft_printf("\n%d\n", count);

	ft_printf("Mio Printf\n");
	count = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
	ft_printf("\n%d\n", count);
	ft_printf("OG Printf\n");
	fflush(stdout); 
	count = printf(" %-1c %-2c %-3c ", '0', 0, '1');
	fflush(stdout); 
	ft_printf("\n%d\n", count);

	ft_printf("Mio Printf\n");
	count = ft_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("\n%d\n", count);
	ft_printf("OG Printf\n");
	fflush(stdout); 
	count = printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout); 
	ft_printf("\n%d\n", count);

	ft_printf("Mio Printf\n");
	count = ft_printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("\n%d\n", count);
	ft_printf("OG Printf\n");
	fflush(stdout); 
	count = printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	fflush(stdout); 
	ft_printf("\n%d\n", count);
	return(0);
}

