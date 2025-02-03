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

	str = "miaooooo";
	pointer = NULL;
	count = 0;
	//ft_printf("\"%10c\"\n", 'm');
	ft_printf("\"%10.3s\"\n", str);
	ft_printf("Printf mio scrive: \"%10.3s\"\n", "miaooo");
	ft_printf("Printf mio scrive: %.i\n\n", 0);
	return(0);
}

