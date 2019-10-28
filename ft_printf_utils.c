/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:51:27 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 12:01:42 by trbonnes         ###   ########.fr       */
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

void	ft_displaypres(size_t **flag, size_t i, int bool, int neg)
{
	size_t	l;

	l = 0;
	if (!bool && flag[0][0] && !flag[4][0] && !flag[1][0] && flag[0][1] >= flag[2][1] && flag[0][1] > i)
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
		if (! bool && neg)
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

size_t		ft_strllcpy(wchar_t *dest, wchar_t *src, size_t n)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	if (!dest || !src)
		return (0);
	while (src[count] != '\0')
		count++;
	if (n == 0)
		return (count);
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 1)
		dest[i] = '\0';
	return (count);
}