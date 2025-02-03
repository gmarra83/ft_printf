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

// Dichiarazione della tua funzione printf personalizzata
int ft_printf(const char *format, ...);

int main(int argc, char *argv[])
{
    // Variabili per i test
    int i = 42;
    unsigned int u = 4294967295;
    char c = 'A';
    char *s = "Hello, World!";
    char *null_ptr = NULL;
    int min_int = INT_MIN;
    int max_int = INT_MAX;
    int printf_len = 0;
    int ft_len = 0;
    (void) argc;

	if (argv[1][0] == 'c' || argv[1][0] == 'a')
	{
	    // 1. Test conversioni semplici ('c', 's', 'p', 'd', 'i', 'u', 'x', 'X')
    		ft_len = ft_printf("Char: %c %c%%\n", c, c);
    		printf_len = printf("Char: %c %c%%\n", c, c);
    		printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
    	}
	if (argv[1][0] == 's' || argv[1][0] == 'a')
	{	
		ft_len = ft_printf("String: %s\n", s);
    		printf_len = printf("String: %s\n", s);
	    	printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	if (argv[1][0] == 'p' || argv[1][0] == 'a')
	{
	    ft_len = ft_printf("Null pointer: %p\n", null_ptr);
	    printf_len = printf("Null pointer: %p\n", null_ptr);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    	    ft_len = ft_printf("Pointer address: %p is valid.\n", &i);
	    printf_len = printf("Pointer address: %p is valid.\n", &i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	if (argv[1][0] == 'd' || argv[1][0] == 'a')
	{ 
	    ft_len = ft_printf("Decimal: %d\n", i);
	    printf_len = printf("Decimal: %d\n", i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	if (argv[1][0] == 'i' || argv[1][0] == 'a')
	{
	    ft_len = ft_printf("Integer: %i\n", i);
	    printf_len = printf("Integer: %i\n", i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	if (argv[1][0] == 'u' || argv[1][0] == 'a')
	{
	    ft_len = ft_printf("Unsigned: %u\n", u);
	    printf_len = printf("Unsigned: %u\n", u);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	if (argv[1][0] == 'x' || argv[1][0] == 'a')
	{
	    ft_len = ft_printf("Hex lowercase: %x\n", i);
	    printf_len = printf("Hex lowercase: %x\n", i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	if (argv[1][0] == 'X' || argv[1][0] == 'a')
		{
	    ft_len = ft_printf("Hex uppercase: %X\n", i);
	    printf_len = printf("Hex uppercase: %X\n", i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	}
	
    // 2. Test casi speciali (0, INT_MIN, INT_MAX, stringa vuota, puntatore NULL)
	if (argv[1][0] == '+' || argv[1][0] == 'a')
	{
	    ft_len = ft_printf("Special case - zero: %d\n", 0);
	    printf_len = printf("Special case - zero: %d\n", 0);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    ft_len = ft_printf("Special case - min int: %d\n", min_int);
	    printf_len = printf("Special case - min int: %d\n", min_int);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    ft_len = ft_printf("Special case - max int: %d\n", max_int);
	    printf_len = printf("Special case - max int: %d\n", max_int);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);

	    ft_len = ft_printf("Empty string: \"%s\"\n", "");
	    printf_len = printf("Empty string: \"%s\"\n", "");
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    ft_len = ft_printf("Null pointer: %p\n", null_ptr);
	    printf_len = printf("Null pointer: %p\n", null_ptr);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    // 3. Test con più argomenti/conversioni
	    ft_len = ft_printf("Multiple args: char=%c, string=%s, int=%d, hex=%x\n", c, s, i, i);
	    printf_len = printf("Multiple args: char=%c, string=%s, int=%d, hex=%x\n", c, s, i, i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    // 4. Test conversioni nel mezzo di una frase
	    ft_len = ft_printf("Hello %s, your score is %d%%!\n", "Alice", 95);
	    printf_len = printf("Hello %s, your score is %d%%!\n", "Alice", 95);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    ft_len = ft_printf("Pointer address: %p is valid.\n", &i);
	    printf_len = printf("Pointer address: %p is valid.\n", &i);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    // 5. Test con numeri negativi e unsigned
	    ft_len = ft_printf("Negative number: %d\n", -123);
	    printf_len = printf("Negative number: %d\n", -123);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	    ft_len = ft_printf("Unsigned number (should not be negative): %u\n", -123);
	    printf_len = printf("Unsigned number (should not be negative): %u\n", -123);
	    printf("ft_printf printed %d characters, printf printed %d characters\n\n", ft_len, printf_len);
	 }
    return 0;
}

