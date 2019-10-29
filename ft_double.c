/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:35:37 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/29 17:24:09 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_doublef(va_list *ap, int r_value, size_t **flag)
{
	char		*str;
	double		f;
	double		tmp;
	long long	conv;
	long long	conv_tmp;
	int			i;
	int 		j;
	int			neg;

	f = va_arg(*ap, double);
	tmp = f;
	i = 0;
	conv = 0;
	conv_tmp = 1;
	neg = 0;
	(void)flag;
	while (tmp > 1)
	{
		tmp = tmp / 10;
		i++;
	}
	while (conv_tmp % 10 > 0)
	{
		tmp = tmp * 10;
		conv_tmp = (long long)tmp;
		conv = conv * 10 + (conv_tmp % 10);
	}
	conv = conv / 10;
	if (conv < 0)
	{
		neg = 1;
		conv *= -1;
	}
	str = ft_dtos(conv, i);
	ft_putstr_fd(str, 1);
	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i + j])
		j++;
	if (j <= 6)
		while (j++ <= 6)
			ft_putchar_fd('0', 1);
	r_value = ft_strlen(str);
	return (r_value);
}
