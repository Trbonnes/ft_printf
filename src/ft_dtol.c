/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:10:26 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 10:52:09 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_dtolten(double tmp, int bool, size_t *i)
{
	long long	conv;
	long long	conv_tmp;
	size_t		j;

	conv_tmp = 1;
	conv = 0;
	j = 0;
	while (bool || conv_tmp % 10 > 0 || j <= *i)
	{
		tmp = tmp * 10;
		conv_tmp = (long long)tmp;
		conv = conv * 10 + (conv_tmp % 10);
		if (conv_tmp % 10 == 0 && (long long)(tmp * 10) % 10 == 0)
			bool = 0;
		j++;
	}
	return (conv);
}

double		ft_doublereduce(double tmp, size_t *i, int *bool)
{
	long long conv_tmp;

	while (tmp >= 1)
	{
		conv_tmp = (long long)tmp;
		if (conv_tmp % 10 == 0)
			*bool = 1;
		tmp = tmp / 10;
		(*i)++;
	}
	return (tmp);
}

long long	ft_dtol(double f, size_t *i)
{
	double		tmp;
	long long	conv;
	long long	conv_tmp;
	int			bool;

	tmp = f;
	if (f < 0)
		tmp *= -1;
	conv_tmp = 1;
	conv = 0;
	bool = 0;
	tmp = ft_doublereduce(tmp, i, &bool);
	if (bool)
		conv = ft_dtolten(tmp, bool, i);
	else
		while (conv_tmp % 10 > 0)
		{
			tmp = tmp * 10;
			conv_tmp = (long long)tmp;
			conv = conv * 10 + (conv_tmp % 10);
		}
	if (f < 0)
		return ((conv / 10) * -1);
	return (conv / 10);
}
