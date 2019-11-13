/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:07:02 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/13 14:33:04 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_indicconvert(va_list *ap, int r_value, char c, size_t **flag)
{
	if (c == '%')
		r_value = ft_printpour(r_value, flag);
	if (c == 'c')
		r_value = ft_printc(ap, r_value, flag);
	else if (c == 's')
		r_value = ft_prints(ap, r_value, flag);
	else if (c == 'p')
		r_value = ft_printp(ap, r_value, flag);
	else if (c == 'd')
		r_value = ft_printdi(ap, r_value, flag);
	else if (c == 'i')
		r_value = ft_printdi(ap, r_value, flag);
	else if (c == 'u')
		r_value = ft_printu(ap, r_value, flag);
	else if (c == 'x')
		r_value = ft_printx(ap, r_value, 0, flag);
	else if (c == 'X')
		r_value = ft_printx(ap, r_value, 1, flag);
	else if (c == 'n')
		r_value = ft_printn(ap, r_value);
	else if (c == 'f')
		r_value = ft_doublef(ap, r_value, flag);
	return (r_value = ft_freeandreturn(r_value, flag));
}

int	ft_indichh(va_list *ap, int r_value, char c, size_t **flag)
{
	if (c == 'd')
		r_value = ft_printdi(ap, r_value, flag);
	else if (c == 'i')
		r_value = ft_printdi(ap, r_value, flag);
	else if (c == 'u')
		r_value = ft_printu(ap, r_value, flag);
	else if (c == 'x')
		r_value = ft_printhhx(ap, r_value, 0, flag);
	else if (c == 'X')
		r_value = ft_printhhx(ap, r_value, 1, flag);
	else if (c == 'n')
		r_value = ft_printhhn(ap, r_value);
	return (r_value = ft_freeandreturn(r_value, flag));
}

int	ft_indich(va_list *ap, int r_value, char c, size_t **flag)
{
	if (c == 'd')
		r_value = ft_printdi(ap, r_value, flag);
	else if (c == 'i')
		r_value = ft_printdi(ap, r_value, flag);
	else if (c == 'u')
		r_value = ft_printu(ap, r_value, flag);
	else if (c == 'x')
		r_value = ft_printhx(ap, r_value, 0, flag);
	else if (c == 'X')
		r_value = ft_printhx(ap, r_value, 1, flag);
	else if (c == 'n')
		r_value = ft_printhn(ap, r_value);
	return (r_value = ft_freeandreturn(r_value, flag));
}

int	ft_indiclong(va_list *ap, int r_value, char c, size_t **flag)
{
	if (c == 'c')
		r_value = ft_printlc(ap, r_value, flag);
	else if (c == 's')
		r_value = ft_printls(ap, r_value, flag);
	else if (c == 'd')
		r_value = ft_printldli(ap, r_value, flag);
	else if (c == 'i')
		r_value = ft_printldli(ap, r_value, flag);
	else if (c == 'u')
		r_value = ft_printlu(ap, r_value, flag);
	else if (c == 'x')
		r_value = ft_printlx(ap, r_value, 0, flag);
	else if (c == 'X')
		r_value = ft_printlx(ap, r_value, 1, flag);
	else if (c == 'n')
		r_value = ft_println(ap, r_value);
	else if (c == 'f')
		r_value = ft_doublef(ap, r_value, flag);
	return (r_value = ft_freeandreturn(r_value, flag));
}
