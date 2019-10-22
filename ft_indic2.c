/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:26:47 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/22 12:28:37 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printx(va_list *ap, int r_value, int maj, size_t *length)
{
	char	*str;
	size_t	nb;
	size_t	i;
	size_t	l;

	l = 0;
	i = -1;
	nb = (size_t)va_arg(*ap, unsigned int);
	str = ft_convert_base(nb);
	if (maj == 1)
		while (str[++i])
			str[i] = ft_toupper((int)str[i]);
	i = ft_strlen(str);
	ft_fielddisplay(l, length, i, 0);
	ft_putstr_fd(str, 1);
	ft_fielddisplay(l, length, i, 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printn(va_list *ap, int r_value)
{
	int *n;

	n = va_arg(*ap, int *);
	*n = r_value;
	return (r_value);
}
