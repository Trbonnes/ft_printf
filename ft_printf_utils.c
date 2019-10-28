/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:51:27 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 13:50:19 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_plusdisplay(size_t *i, size_t **flag, int neg)
{
	if (++(*i) >= 0 && flag[0][0] && !flag[1][0])
		ft_fielddisplay(flag, *i, 0, neg);
	ft_putchar_fd('+', 1);
	if (flag[1][0])
		ft_fielddisplay(flag, *i, 0, neg);
}

int		ft_standisplay(const char *str, int *i, int r_value)
{
	ft_putchar_fd(str[*i], 1);
	r_value++;
	(*i)++;
	return (r_value);
}

void	ft_displaypres(size_t **flag, size_t i, int bool, int neg)
{
	size_t	l;

	l = 0;
	if (!bool && flag[0][0] && !flag[4][0] && !flag[1][0] &&
	flag[0][1] >= flag[2][1] && flag[0][1] > i)
		while (l++ < (flag[0][1] - flag[2][1] - neg))
			ft_putchar_fd(' ', 1);
	if (!bool && neg)
		ft_putchar_fd('-', 1);
	l = 0;
	if (!bool && flag[1][0] && flag[1][1] >= flag[2][1] && flag[1][1] > i)
		while (l++ < (flag[1][1] - flag[2][1]))
			ft_putchar_fd(' ', 1);
	l = 0;
	if (!bool && flag[2][1] > i)
		while (l++ < (flag[2][1] - i))
			ft_putchar_fd('0', 1);
	l = 0;
	if (bool && flag[4][0] && flag[0][1] > i)
		while (l++ < (flag[0][1] - flag[2][1]))
			ft_putchar_fd(' ', 1);
}

void	ft_fielddisplay(size_t **flag, size_t i, int bool, int neg)
{
	size_t l;

	if (flag[2][0] && flag[2][1] > i)
		ft_displaypres(flag, i, bool, neg);
	else
	{
		l = 0;
		if (!bool && flag[0][0] && !flag[4][0] && !flag[1][0] && flag[0][1] > i)
			while (l++ < (flag[0][1] - i))
				ft_putchar_fd(' ', 1);
		if (!bool && neg)
			ft_putchar_fd('-', 1);
		l = 0;
		if (!bool && flag[1][0] && flag[1][1] > i)
			while (l++ < (flag[1][1] - i))
				ft_putchar_fd('0', 1);
		l = 0;
		if (!bool && flag[2][0] && flag[2][1] > i)
			while (l++ < (flag[2][1] - i))
				ft_putchar_fd('0', 1);
		l = 0;
		if (bool && flag[4][0] && flag[0][1] > i)
			while (l++ < (flag[0][1] - i))
				ft_putchar_fd(' ', 1);
	}
}
