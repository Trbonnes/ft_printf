/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indicshort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:22:04 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/29 12:12:56 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printhx(va_list *ap, int r_value, int maj, size_t **flag)
{
	char			*str;
	unsigned short	nb;
	size_t			i;
	size_t			length;

	i = -1;
	nb = va_arg(*ap, int);
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
	length = ft_length(flag, 0);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int		ft_printhhx(va_list *ap, int r_value, int maj, size_t **flag)
{
	int		a;
	char	*str;
	size_t	nb;
	size_t	i;
	size_t	length;

	i = -1;
	if ((a = va_arg(*ap, int)) < 0)
		nb = 256 + a;
	else
		nb = a;
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
	length = ft_length(flag, 0);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int		ft_printhn(va_list *ap, int r_value)
{
	short int *n;

	n = va_arg(*ap, short int *);
	*n = r_value;
	return (r_value);
}

int		ft_printhhn(va_list *ap, int r_value)
{
	char *n;

	n = va_arg(*ap, char *);
	*n = r_value;
	return (r_value);
}
