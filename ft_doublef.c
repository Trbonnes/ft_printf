/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublef.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:35:37 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/13 14:55:20 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_doublepres(char *str, size_t **flag, size_t *i, size_t *j)
{
	size_t limite;

	limite = flag[2][1];
	if ((*j) < flag[2][1] && (*i)--)
	{
		ft_fielddisplay(flag, (*i) + limite + 2, 0, 0);
		ft_putstr_fd(str, 1);
		while ((*j)++ < limite)
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
	double		f;
	char		*str;
	size_t		i;
	size_t		j;
	size_t		length;

	f = va_arg(*ap, double);
	if ((i = ft_isdouble(f, flag)))
		return (r_value + i);
	str = ft_dtos(f);
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
	length = ft_length(flag, 0, str);
	if (length > i + j + 1)
		return (r_value + (int)length);
	return (r_value + i + j + 1);
}
