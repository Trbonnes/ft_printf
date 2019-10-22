/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/22 08:35:25 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_flag(va_list *ap, int r_value, const char *str, int *i)
{
	size_t	length[2];

	length[0] = 0;
	(*i)++;
	if (str[*i] == '0')
	{
		length[0] = 1;
		while (str[*i] == '0')
			(*i)++;
	}
	else if (str[(*i)] == '-')
	{
		length[0] = 2;
		(*i)++;
	}
	length[1] = ft_atoi(str + *i);
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	r_value = ft_indicconvert(ap, r_value, str[*i], length);
	return (r_value);
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
	return (r_value);
}

int	ft_standisplay(const char *str, int *i, int r_value)
{
	ft_putchar_fd(str[*i], 1);
	r_value++;
	(*i)++;
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
