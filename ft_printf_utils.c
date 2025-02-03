/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:05 by gmarra            #+#    #+#             */
/*   Updated: 2024/12/22 16:33:38 by gmarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*mem_addr;
	char	*mem_src;

	mem_addr = (char *)dest;
	mem_src = (char *)src;
	if (!dest || !src)
		return (NULL);
	if (mem_src < mem_addr)
		while (n--)
			*(mem_addr + n) = *(mem_src + n);
	else
		while (n--)
			*mem_addr++ = *mem_src++;
	return (dest);
}

void	ftpf_memset(void *s, int c, size_t n)
{
	unsigned char	byte2set;
	unsigned char	*mem_addr;

	byte2set = (unsigned char) c;
	mem_addr = (unsigned char *)s;
	while (n)
		mem_addr[--n] = byte2set;
}

char	*ft_strshrink(char *str, size_t curr_dim, size_t new_dim)
{
	char	*new_str;

	if (curr_dim == new_dim)
		return (str);
	if (curr_dim > new_dim)
		curr_dim = new_dim;
	new_str = (char *) malloc(new_dim + 1);
	if (!new_str)
		return (str);
	ftpf_memset(new_str, 0, new_dim + 1);
	ft_memmove(new_str, str, curr_dim);
	free (str);
	return (new_str);
}

void	check_sign_zero(t_placeholder *data)
{
	size_t	i;

	i = 0;
	while (data->str[i] && get_bit(data->flgmask, ZERO))
	{
		if ((data->str[i] == '-' || data->str[i] == '+') && i > 0)
		{
			data->str[0] = data->str[i];
			data->str[i] = '0';
		}
		i++;
	}
}

void	write_char_str(const char *str, int *cnt, unsigned int str_flg,
			unsigned int flgmask)
{
	if ((str_flg == TYPE_C && !str[0]) || str_flg == 0)
	{
		write(1, &str[0], 1);
		(*cnt)++;
		return ;
	}
	if (get_bit(flgmask, IS_ZERO) && get_bit(flgmask, MINUS))
	{
		write(1, "\0", 1);
		(*cnt)++;
	}
	while (*str)
	{
		write(1, str++, 1);
		(*cnt)++;
	}
	if (get_bit(flgmask, IS_ZERO) && !get_bit(flgmask, MINUS))
	{
		write(1, "\0", 1);
		(*cnt)++;
	}
}
