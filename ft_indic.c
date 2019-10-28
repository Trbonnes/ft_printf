/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:46:39 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 09:14:36 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printc(va_list *ap, int r_value, size_t **flag)
{
	size_t	length;

	ft_fielddisplay(flag, 1, 0);
	ft_putchar_fd(va_arg(*ap, int), 1);
	r_value++;
	ft_fielddisplay(flag, 1, 1);
	length = ft_length(flag);
	if (length > 1)
		return (r_value + (int)((length - 1)));
	return (r_value);
}

int	ft_prints(va_list *ap, int r_value, size_t **flag)
{
	char	*str;
	char	*cpy;
	size_t	i;
	size_t	length;

	str = va_arg(*ap, char *);
	i = ft_strlen(str);
	if (!flag[2][0])
	{
		ft_fielddisplay(flag, i, 0);
		ft_putstr_fd(str, 1);
	}
	else
	{
		i = flag[2][1];
		ft_fielddisplay(flag, i, 0);
		if (!(cpy = malloc(sizeof(char) * i + 1)))
			return (-1);
		ft_strlcpy(cpy, str, i + 1);
		ft_putstr_fd(cpy, 1);
	}
	ft_fielddisplay(flag, i, 1);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printdi(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	length;
	size_t	i;

	n = ft_itoa(va_arg(*ap, int));
	i = ft_strlen(n);
	if (n[0] == '-' && (flag[1][0] || flag[2][0]))
	{
		i--;
		ft_putchar_fd('-', 1);
		n++;
		r_value++;
	}
	else if (n[0] != '-' && flag[5][0])
	{
		if (++i >= 0 && flag[0][0] && !flag[1][0])
			ft_fielddisplay(flag, i, 0);
		ft_putchar_fd('+', 1);
		if (flag[1][0])
			ft_fielddisplay(flag, i, 0);
	}
	if (!flag[5][0] || !flag[0][0])
		ft_fielddisplay(flag, i, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printp(va_list *ap, int r_value, size_t **flag)
{
	char	*str;
	void	*ptr;
	size_t	add;
	size_t	i;
	size_t	length;

	ptr = va_arg(*ap, void *);
	add = (size_t)ptr;
	str = ft_convert_base(add);
	i = ft_strlen(str) + 2;
	ft_fielddisplay(flag, i, 0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	ft_fielddisplay(flag, i, 1);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printu(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;
	size_t	length;

	n = ft_unsigneditoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	ft_fielddisplay(flag, i, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}
