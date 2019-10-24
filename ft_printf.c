/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/24 13:32:40 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_flag(va_list *ap, int r_value, const char *str, int *i)
{
	size_t	length[3];

	(*i)++;
	length[2] = ft_flagplus(str, i, 0);
	if (!(length[0] = ft_flagz(str, i)) && str[(*i)] == '-')
		length[0] = 2;
	else if (str[(*i)] == '.')
		length[0] = 3;
	else if (str[*i] == '#')
		length[0] = 4;
	if (length[0] > 1)
		(*i)++;
	length[2] = ft_flagplus(str, i, length[2]);
	if (str[(*i)] == '*')
		length[1] = (size_t)va_arg(*ap, int);
	else
		length[1] = ft_atoi(str + *i);
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
		(*i)++;
	return (r_value = ft_indicconvert(ap, r_value, str[*i], length));
}

int	ft_indicconvert(va_list *ap, int r_value, char c, size_t *length)
{
	if (c == 'c')
		r_value = ft_printc(ap, r_value, length);
	else if (c == 's')
		r_value = ft_prints(ap, r_value, length);
	else if (c == 'p')
		r_value = ft_printp(ap, r_value, length);
	else if (c == 'd')
		r_value = ft_printdi(ap, r_value, length);
	else if (c == 'i')
		r_value = ft_printdi(ap, r_value, length);
	else if (c == 'u')
		r_value = ft_printu(ap, r_value, length);
	else if (c == 'x')
		r_value = ft_printx(ap, r_value, 0, length);
	else if (c == 'X')
		r_value = ft_printx(ap, r_value, 1, length);
	else if (c == 'n')
		r_value = ft_printn(ap, r_value);
	return (r_value);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		r_value;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	r_value = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if ((str[i + 1]) == '%')
				r_value = ft_standisplay(str, &i, r_value);
			else
				r_value = ft_flag(&ap, r_value, str, &i);
			i++;
		}
		else
			r_value = ft_standisplay(str, &i, r_value);
	}
	va_end(ap);
	return (r_value);
}
