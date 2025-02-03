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
#include "ft_printf.h"

int	main()
{
	char	*str;
	void	*pointer;
	int		count;

	str = NULL;
	pointer = NULL;
	count = 0;
	printf("---Test c---\n");
	count = ft_printf("Printf mio scrive: %c\n", 'm');
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %c\n", 'm');
	printf("Counter: %d\n\n", count);
	ft_printf("Printf mio scrive: %c%c%c%c\n", 'm', 'i', 'a', 'o');
	printf("Printf ogl scrive: %c%c%c%c\n\n", 'm', 'i', 'a', 'o');
	ft_printf("Printf mio scrive: %10c\n", 'm');
	printf("Printf ogl scrive: %10c\n\n", 'm');
	ft_printf("Printf mio scrive: %*c\n", 8, 'm');
	printf("Printf ogl scrive: %*c\n\n", 8, 'm');
	ft_printf("Printf mio scrive: %-10c\n", 'm');
	printf("Printf ogl scrive: %-10c\n\n", 'm');

	printf("---Test %%---\n");
	count = ft_printf("Printf mio scrive: %%\n");
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %%\n");
	printf("Counter: %d\n\n", count);

	printf("---Test s---\n");
	count = ft_printf("Printf mio scrive: %s\n", "miaooo");
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %s\n", "miaooo");
	printf("Counter: %d\n\n", count);
	count = ft_printf("Printf mio scrive: %s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("Counter: %d\n\n", count);
	ft_printf("Printf mio scrive: %10s\n", "miaooo");
	printf("Printf ogl scrive: %10s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %-10s\n", "miaooo");
	printf("Printf ogl scrive: %-10s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %3s\n", "miaooo");
	printf("Printf ogl scrive: %3s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %s\n", str);
	printf("Printf ogl scrive: %s\n\n", str);
	ft_printf("Printf mio scrive: %-10.3s\n", "miaooo");
	printf("Printf ogl scrive: %-10.3s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %10.3s\n", "miaooo");
	printf("Printf ogl scrive: %10.3s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %s\n", "");
	printf("Printf ogl scrive: %s\n\n", "");
	ft_printf("Printf mio scrive: %10s\n", "");
	printf("Printf ogl scrive: %10s\n\n", "");
	ft_printf("Printf mio scrive: %.3s\n", "miaooo");
	printf("Printf ogl scrive: %.3s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %10.3s\n", "miaooo");
	printf("Printf ogl scrive: %10.3s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %3.10s\n", "miaooo");
	printf("Printf ogl scrive: %3.10s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %5.3s\n", "miaooo");
	printf("Printf ogl scrive: %5.3s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %5.s\n", "miaooo");
	printf("Printf ogl scrive: %5.s\n\n", "miaooo");
	ft_printf("Printf mio scrive: %*.*s\n", 5, 3, "miaooo");
	printf("Printf ogl scrive: %*.*s\n\n", 5, 3, "miaooo");
	count = ft_printf("Printf mio scrive: %s\n", "Hello\tWorld\n");
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %s\n", "Hello\tWorld\n");
	printf("Counter: %d\n\n", count);

	printf("---Test p---\n");
	ft_printf("Printf mio scrive: %p\n", "ppp");
	printf("Printf ogl scrive: %p\n\n", "ppp");
	ft_printf("Printf mio scrive: %7p\n", "ppp");
	printf("Printf ogl scrive: %7p\n\n", "ppp");
	count = ft_printf("Printf mio scrive: %15p\n", "ppp");
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %15p\n", "ppp");
	printf("Counter: %d\n\n", count);
	count = ft_printf("Printf mio scrive: %-15p\n", "ppp");
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %-15p\n", "ppp");
	printf("Counter: %d\n\n", count);
	count = ft_printf("Printf mio scrive: %p\n", pointer);
	printf("Counter: %d\n", count);
	count = printf("Printf ogl scrive: %p\n", pointer);
	printf("Counter: %d\n\n", count);
	ft_printf("Printf mio scrive: %p%p\n", "0", "0");
	printf("Printf ogl scrive: %p%p\n\n", "0", "0");

	printf("---Test di---\n");
	printf("Printf ogl scrive: %i\n", 12);
	ft_printf("Printf mio scrive: %i\n\n", 12);
	printf("Printf ogl scrive: %i\n", 123456);
	ft_printf("Printf mio scrive: %i\n\n", 123456);
	printf("Printf ogl scrive: %i\n", 2147483647);
	ft_printf("Printf mio scrive: %i\n\n", 2147483647);
	count = printf("Printf ogl scrive: %i\n", -2147483647);
	printf("Counter: %d\n", count);
	count = ft_printf("Printf mio scrive: %i\n", -2147483647);
	printf("Counter: %d\n\n", count);
	printf("Printf ogl scrive: %i\n", -123456);
	ft_printf("Printf mio scrive: %i\n\n", -123456);
	printf("Printf ogl scrive: %i\n", 0);
	ft_printf("Printf mio scrive: %i\n\n", 0);
	printf("Printf ogl scrive: %i\n", 1000000000);
	ft_printf("Printf mio scrive: %i\n\n", 1000000000);

	printf("Printf ogl scrive: %+i\n", 123456);
	ft_printf("Printf mio scrive: %+i\n\n", 123456);
	printf("Printf ogl scrive: %+i\n", -123456);
	ft_printf("Printf mio scrive: %+i\n\n", -123456);
	printf("Printf ogl scrive: %+i\n", 0);
	ft_printf("Printf mio scrive: %+i\n\n", 0);

	printf("Printf ogl scrive: % i\n", 123456);
	ft_printf("Printf mio scrive: % i\n\n", 123456);
	printf("Printf ogl scrive: % i\n", -123456);
	ft_printf("Printf mio scrive: % i\n\n", -123456);
	printf("Printf ogl scrive: % i\n", 0);
	ft_printf("Printf mio scrive: % i\n\n", 0);

	printf("Printf ogl scrive: %5i\n", 123456);
	ft_printf("Printf mio scrive: %5i\n\n", 123456);
	printf("Printf ogl scrive: %15i\n", 123456);
	ft_printf("Printf mio scrive: %15i\n\n", 123456);
	printf("Printf ogl scrive: %15i\n", -123456);
	ft_printf("Printf mio scrive: %15i\n\n", -123456);
	printf("Printf ogl scrive: %5i\n", 0);
	ft_printf("Printf mio scrive: %5i\n\n", 0);

	printf("Printf ogl scrive: %05i\n", 123456);
	ft_printf("Printf mio scrive: %05i\n\n", 123456);
	printf("Printf ogl scrive: %015i\n", 123456);
	ft_printf("Printf mio scrive: %015i\n\n", 123456);
	printf("Printf ogl scrive: %015i\n", -123456);
	ft_printf("Printf mio scrive: %015i\n\n", -123456);
	printf("Printf ogl scrive: %05i\n", 0);
	ft_printf("Printf mio scrive: %05i\n\n", 0);

	printf("Printf ogl scrive: %-+15i\n", 123456);
	ft_printf("Printf mio scrive: %-+15i\n\n", 123456);
	printf("Printf ogl scrive: %+15i\n", 123456);
	ft_printf("Printf mio scrive: %+15i\n\n", 123456);
	printf("Printf ogl scrive: %+015i\n", -123456);
	ft_printf("Printf mio scrive: %+015i\n\n", -123456);
	printf("Printf ogl scrive: %-15i\n", -123456);
	ft_printf("Printf mio scrive: %-15i\n\n", -123456);

	printf("Printf ogl scrive: %.10i\n", 123456);
	ft_printf("Printf mio scrive: %.10i\n\n", 123456);
	printf("Printf ogl scrive: %.i\n", 0);
	ft_printf("Printf mio scrive: %.i\n\n", 0);
	printf("Printf ogl scrive: %.3i\n", 0);
	ft_printf("Printf mio scrive: %.3i\n\n", 0);

	printf("Printf ogl scrive: %5.3i\n", 123456);
	ft_printf("Printf mio scrive: %5.3i\n\n", 123456);
	printf("Printf ogl scrive: %10.7i\n", 123456);
	ft_printf("Printf mio scrive: %10.7i\n\n", 123456);
	printf("Printf ogl scrive: %-10.7i\n", 123456);
	ft_printf("Printf mio scrive: %-10.7i\n\n", 123456);
	printf("Printf ogl scrive: %+.i\n", 0);
	ft_printf("Printf mio scrive: %+.i\n\n", 0);

	printf("---Test u---\n");
	printf("Printf ogl scrive: %u\n", 12);
	ft_printf("Printf mio scrive: %u\n\n", 12);
	printf("Printf ogl scrive: %u\n", 123456);
	ft_printf("Printf mio scrive: %u\n\n", 123456);
	printf("Printf ogl scrive: %u\n", 2147483647);
	ft_printf("Printf mio scrive: %u\n\n", 2147483647);
	printf("Printf ogl scrive: %u\n", 0);
	ft_printf("Printf mio scrive: %u\n\n", 0);
	printf("Printf ogl scrive: %u\n", 1000000000);
	ft_printf("Printf mio scrive: %u\n\n", 1000000000);

	printf("Printf ogl scrive: %5u\n", 123456);
	ft_printf("Printf mio scrive: %5i\n\n", 123456);
	printf("Printf ogl scrive: %15u\n", 123456);
	ft_printf("Printf mio scrive: %15u\n\n", 123456);
	printf("Printf ogl scrive: %5u\n", 0);
	ft_printf("Printf mio scrive: %5u\n\n", 0);

	printf("Printf ogl scrive: %05u\n", 123456);
	ft_printf("Printf mio scrive: %05u\n\n", 123456);
	printf("Printf ogl scrive: %015u\n", 123456);
	ft_printf("Printf mio scrive: %015u\n\n", 123456);
	printf("Printf ogl scrive: %05u\n", 0);
	ft_printf("Printf mio scrive: %05u\n\n", 0);

	printf("Printf ogl scrive: %-15u\n", 123456);
	ft_printf("Printf mio scrive: %-15u\n\n", 123456);

	printf("Printf ogl scrive: %.10u\n", 123456);
	ft_printf("Printf mio scrive: %.10u\n\n", 123456);
	printf("Printf ogl scrive: %.u\n", 0);
	ft_printf("Printf mio scrive: %.u\n\n", 0);
	printf("Printf ogl scrive: %.3u\n", 0);
	ft_printf("Printf mio scrive: %.3u\n\n", 0);

	printf("Printf ogl scrive: %5.3u\n", 123456);
	ft_printf("Printf mio scrive: %5.3u\n\n", 123456);
	printf("Printf ogl scrive: %10.7u\n", 123456);
	ft_printf("Printf mio scrive: %10.7u\n\n", 123456);
	printf("Printf ogl scrive: %-10.7u\n", 123456);
	ft_printf("Printf mio scrive: %-10.7u\n\n", 123456);

	printf("---Test xX---\n");
	printf("Printf ogl scrive: %x\n", 12);
	ft_printf("Printf mio scrive: %x\n\n", 12);
	printf("Printf ogl scrive: %x\n", 123456);
	ft_printf("Printf mio scrive: %x\n\n", 123456);
	printf("Printf ogl scrive: %x\n", 2147483647);
	ft_printf("Printf mio scrive: %x\n\n", 2147483647);
	printf("Printf ogl scrive: %X\n", 2147483647);
	ft_printf("Printf mio scrive: %X\n\n", 2147483647);
	printf("Printf ogl scrive: %x\n", -2147483647);
	ft_printf("Printf mio scrive: %x\n\n", -2147483647);
	printf("Printf ogl scrive: %x\n", 0);
	ft_printf("Printf mio scrive: %x\n\n", 0);

	printf("Printf ogl scrive: %-15x\n", 12);
	ft_printf("Printf mio scrive: %-15x\n\n", 12);
	printf("Printf ogl scrive: %-15.10x\n", 12);
	ft_printf("Printf mio scrive: %-15.10x\n\n", 12);
	printf("Printf ogl scrive: %-x\n", 123456);
	ft_printf("Printf mio scrive: %-x\n\n", 123456);
	printf("Printf ogl scrive: %-x\n", 2147483647);
	ft_printf("Printf mio scrive: %-x\n\n", 2147483647);
	printf("Printf ogl scrive: %-X\n", 2147483647);
	ft_printf("Printf mio scrive: %-X\n\n", 2147483647);
	printf("Printf ogl scrive: %-x\n", 0);
	ft_printf("Printf mio scrive: %-x\n\n", 0);
	printf("Printf ogl scrive: %-.x\n", 0);
	ft_printf("Printf mio scrive: %-.x\n\n", 0);

	printf("Printf ogl scrive: %015x\n", 12);
	ft_printf("Printf mio scrive: %015x\n\n", 12);
	printf("Printf ogl scrive: %0x\n", 123456);
	ft_printf("Printf mio scrive: %0x\n\n", 123456);
	printf("Printf ogl scrive: %0x\n", 2147483647);
	ft_printf("Printf mio scrive: %0x\n\n", 2147483647);
	printf("Printf ogl scrive: %0X\n", 2147483647);
	ft_printf("Printf mio scrive: %0X\n\n", 2147483647);
	printf("Printf ogl scrive: %0x\n", 0);
	ft_printf("Printf mio scrive: %0x\n\n", 0);

	printf("Printf ogl scrive: %#x\n", 12);
	ft_printf("Printf mio scrive: %#x\n\n", 12);
	printf("Printf ogl scrive: %#x\n", 123456);
	ft_printf("Printf mio scrive: %#x\n\n", 123456);
	printf("Printf ogl scrive: %#x\n", 2147483647);
	ft_printf("Printf mio scrive: %#x\n\n", 2147483647);
	count = printf("Printf ogl scrive: %#X\n", 2147483647);
	printf("Counter: %d\n", count);
	count = ft_printf("Printf mio scrive: %#X\n", 2147483647);
	printf("Counter: %d\n\n", count);
	printf("Printf ogl scrive: %#x\n", 0);
	ft_printf("Printf mio scrive: %#x\n\n", 0);

	return(0);
}

