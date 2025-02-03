/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarra <gmarra@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:05 by gmarra            #+#    #+#             */
/*   Updated: 2024/12/22 16:33:38 by gmarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ftpf_strdup(const char *s)
{
	size_t	strlen;
	char	*s_copy;

	if (!s)
		return (NULL);
	strlen = ftpf_strlen(s);
	s_copy = (char *) malloc ((strlen + 1) * sizeof(char));
	if (!s_copy)
		return (NULL);
	s_copy[strlen] = '\0';
	while (strlen--)
		s_copy[strlen] = s[strlen];
	return (s_copy);
}

size_t	ftpf_strlen(const char *str)
{
	size_t	lenstr;

	lenstr = 0;
	while (*str)
	{
		lenstr++;
		str++;
	}
	return (lenstr);
}

void	ftpf_toupper_str(char *str)
{
	int	offset;

	offset = 'A' - 'a';
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str += offset;
		str++;
	}
}

char	*ft_stradd(const char *str1, char *str2, unsigned int i)
{
	char		*str_join;
	const char	*s1;
	const char	*s2;
	size_t		strlen;

	str_join = NULL;
	s1 = str1;
	s2 = str2;
	if (i)
	{
		s1 = str2;
		s2 = str1;
	}
	strlen = ftpf_strlen(s1) + ftpf_strlen(s2);
	str_join = (char *) malloc ((strlen + 1) * sizeof (char));
	if (!str_join)
		return (NULL);
	str_join [strlen] = '\0';
	while (*s1)
		*str_join++ = *s1++;
	while (*s2)
		*str_join++ = *s2++;
	free (str2);
	return (str_join - strlen);
}

char	*ftpf_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (!str || !c)
		return ((char *)str);
	return (NULL);
}
