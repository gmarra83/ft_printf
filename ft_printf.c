/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:34:30 by gmarra            #+#    #+#             */
/*   Updated: 2024/12/22 16:31:22 by gmarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width_prec_eval(const char **format, t_placeholder *data,
		va_list args)
{
	const char	widthprec_str[] = "0123456789.*";
	int			width_precision;

	width_precision = 0;
	while (ftpf_strchr(widthprec_str, **format) && **format != '\0')
	{
		set_bit(&data->flgmask, WIDTH);
		if (**format == '*')
			width_precision = va_arg(args, int);
		else if (**format == '.')
		{
			data->width = width_precision;
			set_bit(&data->flgmask, DOT);
			width_precision = 0;
		}
		else
			width_precision = width_precision * 10 + **format - '0';
		(*format)++;
	}
	if (!get_bit(data->flgmask, DOT) && !data->width)
		data->width = width_precision;
	if (get_bit(data->flgmask, DOT))
		data->precision = width_precision;
}

static void	flag_eval(const char **format, t_placeholder *data)
{
	const char	flags_str[] = "-+ 0#";

	while (ftpf_strchr(flags_str, **format) && **format != '\0')
	{
		if (**format == '-')
			set_bit(&data->flgmask, MINUS);
		else if (**format == '+')
			set_bit(&data->flgmask, PLUS);
		else if (**format == ' ')
			set_bit(&data->flgmask, SPACE);
		else if (**format == '0')
			set_bit(&data->flgmask, ZERO);
		else if (**format == '#')
			set_bit(&data->flgmask, HASHTAG);
		(*format)++;
	}
}

static void	eval_flg_prio(unsigned int *flgmask, int *width, int *precision)
{
	if (*precision < 0)
		reset_bit(flgmask, DOT);
	if (*width < 0)
	{
		set_bit(flgmask, WIDTH);
		*width *= -1;
	}
	if (get_bit(*flgmask, MINUS) || get_bit(*flgmask, DOT))
		reset_bit(flgmask, ZERO);
	if (get_bit(*flgmask, PLUS))
		reset_bit(flgmask, SPACE);
}

static void	run_format_eval(va_list args, const char **format,
		int *char_printed)
{
	t_placeholder	data2process;
	char			*idx;
	const char		placeholder_str[] = "cspdiuxX";

	data2process = (t_placeholder){0};
	idx = 0;
	flag_eval(format, &data2process);
	width_prec_eval(format, &data2process, args);
	eval_flg_prio(&data2process.flgmask, &data2process.width,
		&data2process.precision);
	if (**format != '\0' && *format != NULL)
		idx = ftpf_strchr(placeholder_str, **format);
	if (idx)
	{
		data2process.format_type = idx - placeholder_str + 1;
		data2process.str = convert_arg(data2process.format_type, args,
				&data2process.flgmask);
	}
	format_str(&data2process);
	write_char_str(data2process.str, char_printed, data2process.format_type,
		data2process.flgmask);
	if (data2process.str)
		free(data2process.str);
}

int	ft_printf(const char *format, ...)
{
	int				char_printed;
	va_list			args;

	va_start(args, format);
	char_printed = 0;
	while (*format)
	{
		if (*format != '%')
			write_char_str(format, &char_printed, 0, 0);
		else
		{
			if (*(++format) == '%')
				write_char_str(format, &char_printed, 0, 0);
			else
				run_format_eval(args, &format, &char_printed);
		}
		format++;
	}
	va_end (args);
	return (char_printed);
}
