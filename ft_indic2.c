/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:26:47 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/22 08:27:46 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printx(va_list *ap, int r_value, int maj, size_t *length)
{
	char	*str;
	size_t	nb;
	size_t	i;
	size_t	l;

	l = 0;
	i = -1;
	nb = (size_t)va_arg(*ap, unsigned int);
	str = ft_convert_base(nb);
	if (maj == 1)
		while (str[++i])
			str[i] = ft_toupper((int)str[i]);
	i = ft_strlen(str);
	if (length[1] > i)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		if (length[0] == 1)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	if (length[1] > i)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i)
		return (r_value + (int)((length[1] - i) + i));
	return (r_value + (int)i);
}
