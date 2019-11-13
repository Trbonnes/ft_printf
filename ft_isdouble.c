/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:40:25 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/13 14:56:09 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	**ft_flagreset(size_t **flag)
{
	flag[2][0] = 0;
	flag[2][1] = 0;
	if (flag[1][0])
	{
		flag[1][0] = 0;
		flag[0][0] = 1;
		flag[0][1] = flag[1][1];
	}
	return (flag);
}

size_t	ft_isnotdouble(size_t **flag, double dbl)
{
	if (ft_isnan(dbl))
	{
		flag = ft_flagreset(flag);
		ft_fielddisplay(flag, 3, 0, 0);
		ft_putstr_fd("nan", 1);
		return (3);
	}
	else if (ft_ispinf(dbl))
	{
		flag = ft_flagreset(flag);
		ft_fielddisplay(flag, 3, 0, 0);
		ft_putstr_fd("inf", 1);
		return (3);
	}
	else if (ft_isninf(dbl))
	{
		flag = ft_flagreset(flag);
		ft_fielddisplay(flag, 4, 0, 0);
		ft_putstr_fd("-inf", 1);
		return (4);
	}
	return (0);
}

size_t	ft_isdouble(double f, size_t **flag)
{
	double	dbl;
	size_t	length;
	size_t	r_value;

	dbl = f;
	if (!(r_value = ft_isnotdouble(flag, dbl)))
		return (0);
	ft_fielddisplay(flag, r_value, 1, 0);
	length = ft_length(flag, 0, NULL);
	if (length > r_value)
		return (length);
	return (r_value);
}
