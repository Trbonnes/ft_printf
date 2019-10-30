/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:35:37 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/30 11:17:06 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_dtol(double f, size_t *i)
{
	double		tmp;
	long long	conv;
	long long	conv_tmp;

	tmp = f;
	conv_tmp = 1;
	conv = 0;
	if (f < 0)
		tmp *= -1;
	while (tmp > 1)
	{
		tmp = tmp / 10;
		(*i)++;
	}
	while (conv_tmp % 10 > 0)
	{
		tmp = tmp * 10;
		conv_tmp = (long long)tmp;
		conv = conv * 10 + (conv_tmp % 10);
	}
	conv = conv / 10;
	if (f < 0)
		return (conv * -1);
	return (conv);
}

void		ft_doublepres(char *str, size_t **flag, size_t *i, size_t *j)
{
	if ((*j) < flag[2][1] && --(*i))
	{

		ft_fielddisplay(flag, (*i) + flag[2][1] + 2, 0, 0);
		ft_putstr_fd(str, 1);
		while ((*j)++ < flag[2][1])
			ft_putchar_fd('0', 1);
	}
	else
	{
		(*j) = flag[2][1];
		if (str[(*i) + (*j)] == '.' && (*i)--)
			str[(*i) + (*j) + 1] = str[(*i) + (*j) + 2];
		if (str[(*i) + (*j) + 1] >= '5')
			str[(*i) + (*j)]++;
		str[(*i) + (*j) + 1] = '\0';
		ft_fielddisplay(flag, (*i) + (*j) + 1, 0, 0);
		ft_putstr_fd(str, 1);
	}
}

void		ft_doublestd(char *str, size_t **flag, size_t *i, size_t *j)
{
	if ((*j) > 6)
	{
		(*j) = 6;
		if (str[(*i) + (*j) + 1] >= '5')
			str[(*i) + (*j)]++;
		str[(*i) + (*j) + 1] = '\0';
		ft_fielddisplay(flag, (*i) + (*j) + 1, 0, 0);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_fielddisplay(flag, (*i) + 6 + 1, 0, 0);
		ft_putstr_fd(str, 1);
		if ((*j) < 6 && (*i)--)
			while ((*j)++ < 6)
				ft_putchar_fd('0', 1);
	}
}

int			ft_doublef(va_list *ap, int r_value, size_t **flag)
{
	char		*str;
	long long	conv;
	size_t		i;
	size_t		j;
	size_t		length;

	i = 0;
	conv = ft_dtol(va_arg(*ap, double), &i);
	str = ft_dtos(conv, i);
	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i + j + 1])
		j++;
	if (flag[2][0])
		ft_doublepres(str, flag, &i, &j);
	else
		ft_doublestd(str, flag, &i, &j);
	ft_fielddisplay(flag, i + j + 1, 1, 0);
	length = ft_length(flag, 0);
	if (i + length + 1 > i + j + 1)
		return (r_value + (int)length);
	return (r_value + i + j + 1);
}
