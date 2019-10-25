/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:51:27 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/25 11:48:13 by trbonnes         ###   ########.fr       */
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

void	ft_fielddisplay(size_t **flag, size_t i, int bool)
{
	size_t l;

	l = 0;
	if (flag[1] > i && bool == 0 && flag[0] == 0)
		while (l++ < (flag[1] - i))
			ft_putchar_fd(' ', 1);
	if (flag[1] > i && bool == 0 && flag[0] == 1)
		while (l++ < (flag[1] - i))
			ft_putchar_fd('0', 1);
	if (flag[1] > i && bool == 0 && flag[0] == 3)
		while (l++ < (flag[1] - i))
			ft_putchar_fd('0', 1);
	if (flag[1] > i && bool == 1 && flag[0] == 2)
		while (l++ < (flag[1] - i))
			ft_putchar_fd(' ', 1);
}
