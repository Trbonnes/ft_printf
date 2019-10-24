/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:51:27 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/24 17:45:33 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_standisplay(const char *str, int *i, int r_value)
{
	ft_putchar_fd(str[*i], 1);
	r_value++;
	(*i)++;
	return (r_value);
}

void	ft_fielddisplay(size_t *length, size_t i, int bool)
{
	size_t l;

	l = 0;
	if (length[1] > i && bool == 0)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i && bool == 0)
		if (length[0] == 1)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	if (length[1] > i && bool == 0)
		if (length[0] == 3)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	if (length[1] > i && bool == 1)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
}

int		ft_flagplus(const char *str, int *i, int check)
{
	if (str[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	if (check == 1)
		return (1);
	return (0);
}

int		ft_flagz(const char *str, int *i)
{
	if (str[*i] == '0')
	{
		while (str[*i] == '0')
			(*i)++;
		return (1);
	}
	return (0);
}
