/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:36:58 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/31 12:08:28 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isnan(double dbl)
{
	long long n;

	n = *((long long *)&dbl);
	return ((n >> 52 & 0x7ff) == 0x7ff &&
			(n & 0xfffffffffffff) != 0);
}

int		ft_ispinf(double dbl)
{
	long long n;

	n = *((long long *)&dbl);
	return ((n >> 52 & 0xfff) == 0x7ff &&
			(n & 0xfffffffffffff) == 0);
}

int		ft_isninf(double dbl)
{
	long long n;

	n = *((long long *)&dbl);
	return ((n >> 52 & 0xfff) == 0xfff &&
			(n & 0xfffffffffffff) == 0);
}
