/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/12 16:04:55 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flagspacesize(va_list *ap, const char *str, int *i, size_t **check)
{
	int j;
	int r;

	j = 0;
	r = 0;
	if (!check[0][0])
		return (0);
	while ((str[(*i) + j] <= '0' || str[(*i) + j] > '9')
	&& !isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '*')
		{
			r = va_arg(*ap, int);
			if (r < 0)
			{
				check[4][0] = 1;
				r = r * -1;
			}
			return (r);
		}
		j++;
	}
	return (ft_atoi(str + *i + j));
}

void	ft_minuszero(size_t **check, int r)
{
	check[4][0] = 1;
	check[1][0] = 0;
	check[0][0] = 1;
	check[0][1] = r;
}

int		ft_flagzsize(va_list *ap, const char *str, int *i, size_t **check)
{
	int j;
	int r;

	j = 0;
	r = 0;
	if (!check[1][0])
		return (0);
	while (str[(*i) + j] != '0')
		j++;
	while ((str[(*i) + j] <= '0' || str[(*i) + j] > '9')
	&& !isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '*')
		{
			if ((r = va_arg(*ap, int)) < 0)
			{
				r = r * -1;
				ft_minuszero(check, r);
			}
			return (r);
		}
		j++;
	}
	return (ft_atoi(str + *i + j));
}

int		ft_flagpresize(va_list *ap, const char *str, int *i, int check)
{
	int j;
	int r_value;

	j = 0;
	if (!check)
		return (0);
	while (str[(*i) + j] != '.')
		j++;
	j++;
	if (str[(*i) + j] == '*')
		r_value = va_arg(*ap, int);
	else
		r_value = ft_atoi(str + *i + j);
	if (r_value < 0)
		return (0);
	return (r_value);
}
