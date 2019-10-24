/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:46:39 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/24 17:51:15 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printc(va_list *ap, int r_value, size_t *length)
{
	ft_fielddisplay(length, 1, 0);
	ft_putchar_fd(va_arg(*ap, int), 1);
	ft_fielddisplay(length, 1, 1);
	r_value++;
	if (length[1] > 1)
		return (r_value + (int)((length[1] - 1)));
	return (r_value);
}

int	ft_prints(va_list *ap, int r_value, size_t *length)
{
	char	*str;
	size_t	i;

	str = va_arg(*ap, char *);
	i = ft_strlen(str);
	ft_fielddisplay(length, i, 0);
	ft_putstr_fd(str, 1);
	ft_fielddisplay(length, i, 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printdi(va_list *ap, int r_value, size_t *length)
{
	char	*n;
	size_t	i;

	n = ft_itoa(va_arg(*ap, int));
	i = ft_strlen(n);
	if (n[0] == '-' && (length[0] == 1 || length[0] == 3))
	{
		i--;
		ft_putchar_fd('-', 1);
		n++;
		r_value++;
	}
	else if (n[0] != '-' && length[2] == 1)
	{
		if (++i >= 0 && length[0] == 0)
			ft_fielddisplay(length, i, 0);
		ft_putchar_fd('+', 1);
	}
	if (length[2] != 1 || length[0] != 0)
		ft_fielddisplay(length, i, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(length, i, 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printp(va_list *ap, int r_value, size_t *length)
{
	char	*str;
	void	*ptr;
	size_t	add;
	size_t	i;

	ptr = va_arg(*ap, void *);
	add = (size_t)ptr;
	str = ft_convert_base(add);
	i = ft_strlen(str) + 2;
	ft_fielddisplay(length, i, 0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	ft_fielddisplay(length, i, 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printu(va_list *ap, int r_value, size_t *length)
{
	char	*n;
	size_t	i;

	n = ft_itoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	ft_fielddisplay(length, i, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(length, i, 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}
