/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_parsing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:05 by gmarra            #+#    #+#             */
/*   Updated: 2024/12/22 16:33:38 by gmarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc_bitmask(unsigned int *flgmask, int format_type)
{
	if (format_type == TYPE_C)
		*flgmask = *flgmask & CHR;
	else if (format_type == TYPE_S)
		*flgmask = *flgmask & STR;
	else if (format_type == TYPE_P)
		*flgmask = *flgmask & PTR;
	else if (format_type == TYPE_D)
		*flgmask = *flgmask & DEC;
	else if (format_type == TYPE_I)
		*flgmask = *flgmask & INT;
	else if (format_type == TYPE_U)
		*flgmask = *flgmask & UINT;
	else if (format_type == TYPE_X || format_type == TYPE_XX)
		*flgmask = *flgmask & HEX;
}

static void	format_precision(t_placeholder *data)
{
	ssize_t	act_dim;
	ssize_t	char2add;

	act_dim = ftpf_strlen(data->str);
	char2add = data->precision - act_dim;
	if (char2add <= 0 && data->format_type == TYPE_S)
		data->str = ft_strshrink(data->str, act_dim, data->precision);
	else if (char2add > 0 && data->format_type > TYPE_S)
		while (char2add--)
			data->str = ft_stradd("0", data->str, 0);
}

static void	format_width(t_placeholder *data)
{
	ssize_t	act_dim;
	ssize_t	char2add;

	if (data->format_type == TYPE_C && !data->str[0])
		set_bit(&data->flgmask, IS_ZERO);
	act_dim = ftpf_strlen(data->str) + get_bit(data->flgmask, IS_ZERO);
	char2add = data->width - act_dim;
	if (get_bit(data->flgmask, MINUS))
	{
		while (char2add--)
			data->str = ft_stradd(" ", data->str, 1);
	}
	else
	{
		while (char2add--)
		{
			if (get_bit(data->flgmask, ZERO))
				data->str = ft_stradd("0", data->str, 0);
			else
				data->str = ft_stradd(" ", data->str, 0);
		}
	}
	check_sign_zero(data);
}

static void	evaluate_flags(t_placeholder *data)
{
	if (get_bit(data->flgmask, DOT))
		format_precision(data);
	if (data->str[0] == '0' && get_bit(data->flgmask, DOT)
		&& !data->precision && !get_bit(data->flgmask, HASHTAG))
	{
		free(data->str);
		data->str = ftpf_strdup("");
	}
	if (get_bit(data->flgmask, IS_NEG))
		data->str = ft_stradd("-", data->str, 0);
	else if (get_bit(data->flgmask, PLUS))
		data->str = ft_stradd("+", data->str, 0);
	else if (get_bit(data->flgmask, SPACE))
		data->str = ft_stradd(" ", data->str, 0);
	if ((get_bit(data->flgmask, HASHTAG) && data->str[0] != '0')
		|| data->format_type == TYPE_P)
		data->str = ft_stradd("0x", data->str, 0);
	if (get_bit(data->flgmask, WIDTH)
		&& (int)ftpf_strlen(data->str) < data->width)
		format_width(data);
	if (data->format_type == TYPE_XX)
		ftpf_toupper_str(data->str);
}

void	format_str(t_placeholder *data2process)
{
	if (data2process->str == NULL)
	{
		data2process->str = ftpf_strdup("(null)");
		return ;
	}
	else if (data2process->format_type == TYPE_P && data2process->str[0] == '0')
	{
		free (data2process->str);
		data2process->str = ftpf_strdup("(nil)");
		return ;
	}
	calc_bitmask(&data2process->flgmask, data2process->format_type);
	evaluate_flags(data2process);
}
