/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:15:29 by gmarra            #+#    #+#             */
/*   Updated: 2024/12/18 17:30:28 by gmarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

static inline void	set_bit(unsigned int *mask, unsigned int bit_pos)
{
	*mask |= 1U << bit_pos;
}

static inline void	reset_bit(unsigned int *mask, unsigned int bit_pos)
{
	*mask &= ~(1U << bit_pos);
}

static inline unsigned int	get_bit(unsigned int mask, unsigned int bit_pos)
{
	return ((mask >> bit_pos) & 1U);
}

enum e_bitmask
{
	MINUS = 0,
	PLUS = 1,
	SPACE = 2,
	ZERO = 3,
	HASHTAG = 4,
	WIDTH = 5,
	DOT = 6,
	IS_ZERO = 7,
	IS_NEG = 8
};

enum e_typemask
{
	CHR = 0xA1,
	STR = 0x61,
	PTR = 0x61,
	DEC = 0x16F,
	INT = 0x16F,
	UINT = 0x6D,
	HEX = 0x79
};

enum e_typeformat
{
	TYPE_NONE,
	TYPE_C,
	TYPE_S,
	TYPE_P,
	TYPE_D,
	TYPE_I,
	TYPE_U,
	TYPE_X,
	TYPE_XX
};

typedef union u_numbers
{
	int			i;
	uintptr_t	u;
}	t_convtypenum;

typedef struct s_placeholder
{
	unsigned int	flgmask;
	int				width;
	int				precision;
	int				format_type;
	char			*str;
}	t_placeholder;

int		ft_printf(const char *str, ...);
size_t	ftpf_strlen(const char *str);
char	*ftpf_strdup(const char *s);
void	ftpf_toupper_str(char *str);
void	write_char_str(const char *str, int *cnt, unsigned int str_flg,
						unsigned int flgmask);
void	format_str(t_placeholder *data2process);
char	*convert_arg(int format_type, va_list args, unsigned int *flgmask);
char	*ftpf_strchr(const char *str, int c);
char	*ft_stradd(const char *str1, char *str2, unsigned int i);
char	*ft_strshrink(char *str, size_t curr_dim, size_t new_dim);
void	check_sign_zero(t_placeholder *data);
void	ftpf_memset(void *s, int c, size_t n);

#endif
