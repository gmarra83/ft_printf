/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:05 by gmarra            #+#    #+#             */
/*   Updated: 2024/12/22 16:33:38 by gmarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*conv_chr(char charnum)
{
	char	*return_char;

	return_char = (char *) malloc(2 * sizeof(char));
	if (!return_char)
		return (NULL);
	return_char[0] = charnum;
	return_char[1] = '\0';
	return (return_char);
}

static int	num_digit(uintptr_t n, unsigned int base)
{
	unsigned int	digits;

	digits = 0;
	while (n)
	{
		digits++;
		n = n / base;
	}
	return (digits);
}

static char	*ftpf_itoa(t_convtypenum n, unsigned int base,
		unsigned int *flgmask, int format_type)
{
	char			*str_num;
	unsigned int	digits;
	uintptr_t		u_num;

	if (!(n.u))
		return (ftpf_strdup("0"));
	u_num = n.u;
	if (n.i < 0 && (format_type == TYPE_D || format_type == TYPE_I))
	{
		u_num = (uintptr_t) ~ n.i + 1;
		set_bit(flgmask, IS_NEG);
	}
	digits = num_digit(u_num, base);
	str_num = (char *) malloc ((digits + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	ftpf_memset(str_num, 0, digits + 1);
	while (digits--)
	{
		str_num[digits] = u_num % base + '0';
		if (str_num[digits] > '9')
			str_num[digits] += ('a' - '9' - 1);
		u_num = u_num / base;
	}
	return (str_num);
}

char	*convert_arg(int format_type, va_list args, unsigned int *flgmask)
{
	char			*conv_str;
	t_convtypenum	value;
	unsigned int	base;

	value.u = 0;
	conv_str = NULL;
	base = 10;
	if (format_type == TYPE_C)
		conv_str = conv_chr((char) va_arg(args, int));
	else if (format_type == TYPE_S)
		conv_str = ftpf_strdup(va_arg(args, char *));
	else if (format_type == TYPE_P)
		value.u = (uintptr_t)va_arg(args, void *);
	else if (format_type == TYPE_D || format_type == TYPE_I)
		value.i = va_arg(args, int);
	else if (format_type >= TYPE_U)
		value.u = (uintptr_t) va_arg(args, unsigned int);
	if (format_type == TYPE_P || format_type >= TYPE_X)
		base = 16;
	if (format_type >= TYPE_P)
		conv_str = ftpf_itoa(value, base, flgmask, format_type);
	return (conv_str);
}
