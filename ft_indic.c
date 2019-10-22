/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:46:39 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/22 08:27:19 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printc(va_list *ap, int r_value, size_t *length)
{
	size_t l;

	l = 0;
	if (length[1] > 1)
		if (length[0] == 0)
			while (l++ < (length[1] - 1))
				ft_putchar_fd(' ', 1);
	ft_putchar_fd(va_arg(*ap, int), 1);
	if (length[1] > 1)
		if (length[0] == 2)
			while (l++ < (length[1] - 1))
				ft_putchar_fd(' ', 1);
	r_value++;
	if (length[1] > 1)
		return (r_value + (int)((length[1] - 1)));
	return (r_value + 1);
}

int	ft_prints(va_list *ap, int r_value, size_t *length)
{
	char	*str;
	size_t	i;
	size_t	l;

	l = 0;
	str = va_arg(*ap, char *);
	i = ft_strlen(str);
	if (length[1] > i)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	if (length[1] > i)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printdi(va_list *ap, int r_value, size_t *length)
{
	char	*n;
	size_t	i;
	size_t	l;

	l = 0;
	n = ft_itoa(va_arg(*ap, int));
	i = ft_strlen(n);
	if (length[1] > i)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		if (length[0] == 1)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	ft_putstr_fd(n, 1);
	if (length[1] > i)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
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
	size_t	l;

	l = 0;
	ptr = va_arg(*ap, void *);
	add = (size_t)ptr;
	str = ft_convert_base(add);
	i = ft_strlen(str) + 2;
	if (length[1] > i)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	if (length[1] > i)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printu(va_list *ap, int r_value, size_t *length)
{
	char	*n;
	size_t	i;
	size_t	l;

	printf("call\n");
	l = 0;
	n = ft_itoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	if (length[1] > i)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		if (length[0] == 1)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	ft_putstr_fd(n, 1);
	if (length[1] > i)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}
