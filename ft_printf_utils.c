/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:51:27 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/25 16:58:27 by trbonnes         ###   ########.fr       */
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
	if (!bool && flag[0][0] && !flag[4][0] && !flag[1][0] && flag[0][1] > i)
		while (l++ < (flag[0][1] - i))
			ft_putchar_fd(' ', 1);
	if (!bool && flag[1][0] && flag[1][1] > i)
		while (l++ < (flag[1][1] - i))
			ft_putchar_fd('0', 1);
	if (!bool && flag[2][0] && flag[2][1] > i)
		while (l++ < (flag[2][1] - i))
			ft_putchar_fd('0', 1);
	if (bool && flag[4][0] && flag[0][1] > i)
		while (l++ < (flag[0][1] - i))
			ft_putchar_fd(' ', 1);
}

size_t	**ft_flaglock(void)
{
	size_t	**flag;
	size_t	i;

	i = 0;
	if (!(flag = malloc(sizeof(size_t *) * 6)))
		return (NULL);
	while (i < 6)
	{
		if (!(flag[i++] = malloc(sizeof(size_t) * 2)))
			return (NULL);
	}
	return (flag);
}

size_t	ft_length(size_t **flag)
{
	size_t length;

	length = 0;
	if (flag[0][1])
		length = length + flag[0][1];
	if (flag[1][1])
		length = length + flag[1][1];
	if (flag[2][1])
		length = length + flag[2][1];
	return (length);
}