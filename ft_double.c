/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:35:37 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/29 17:55:13 by trbonnes         ###   ########.fr       */
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
	size_t		i;
	size_t		j;
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
	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i + j])
		j++;
	if (flag[2][0])
	{
		if (j <= flag[2][1])
		{
			i = ft_strlen(str);
			ft_putstr_fd(str, 1);
			while (j++ <= flag[2][1] && i++)
				ft_putchar_fd('0', 1);
		}
		else
		{
			j = flag[2][1];
			if (str[i + j + 1] >= 5)
				str[i + j]++;
			str[i + j + 1] = '\0';
			ft_putstr_fd(str, 1);
		}
	}
	else
	{
		i = ft_strlen(str);
		ft_putstr_fd(str, 1);
		if (j <= 6)
			while (j++ <= 6 && i++)
				ft_putchar_fd('0', 1);
	}
	return (r_value + i);
}
