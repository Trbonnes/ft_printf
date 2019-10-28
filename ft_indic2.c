/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:26:47 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 11:57:58 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printx(va_list *ap, int r_value, int maj, size_t **flag)
{
	char	*str;
	size_t	nb;
	size_t	i;
	size_t	length;

	i = -1;
	nb = (size_t)va_arg(*ap, unsigned int);
	str = ft_convert_base(nb);
	if (maj == 1)
		while (str[++i])
			str[i] = ft_toupper((int)str[i]);
	i = ft_strlen(str);
	ft_fielddisplay(flag, i, 0, 0);
	if (flag[3][0] && i++ && i++)
		ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printn(va_list *ap, int r_value)
{
	int *n;

	n = va_arg(*ap, int *);
	*n = r_value;
	return (r_value);
}
