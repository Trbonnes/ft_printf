/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/11 09:14:47 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

size_t		**ft_checkflag(va_list *ap, const char *str, int *i)
{
	size_t	**flag;

	if (!(flag = ft_flaglock()))
		return (0);
	(*i)++;
	flag[0][0] = ft_flagspace(str, i);
	flag[1][0] = ft_flagz(str, i);
	flag[2][0] = ft_flagpre(str, i);
	flag[3][0] = ft_flaghash(str, i);
	flag[4][0] = ft_flagmoins(str, i);
	flag[5][0] = ft_flagplus(str, i);
	flag[6][0] = ft_flagcomma(str, i);
	flag[7][0] = ft_flagvoid(str, i);
	flag[0][1] = ft_flagspacesize(ap, str, i, flag[0][0]);
	flag[1][1] = ft_flagzsize(ap, str, i, flag[1][0]);
	flag[2][1] = ft_flagpresize(ap, str, i, flag[2][0]);
	flag[3][1] = 0;
	flag[4][1] = 0;
	flag[5][1] = 0;
	flag[6][1] = 0;
	flag[7][1] = 0;
	return (flag);
}

int			ft_flag(va_list *ap, int r_value, const char *str, int *i)
{
	size_t	**flag;

	if (!(flag = ft_checkflag(ap, str, i)))
		return (0);
	while ((!ft_isalpha(str[*i]) && str[*i] != '%') ||
	ft_isdigit(str[*i]) || str[*i] == '*')
		(*i)++;
	if (str[*i] == 'h' && str[(*i) + 1] == 'h')
	{
		(*i)++;
		return (r_value = ft_indichh(ap, r_value, str[++(*i)], flag));
	}
	else if (str[*i] == 'h')
		return (r_value = ft_indich(ap, r_value, str[++(*i)], flag));
	else if (str[*i] == 'l' && str[(*i) + 1] == 'l')
		(*i)++;
	if (str[*i] == 'l')
		return (r_value = ft_indiclong(ap, r_value, str[++(*i)], flag));
	return (r_value = ft_indicconvert(ap, r_value, str[*i], flag));
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		r_value;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	r_value = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			r_value = ft_flag(&ap, r_value, str, &i);
			i++;
		}
		else
			r_value = ft_standisplay(str, &i, r_value);
	}
	va_end(ap);
	return (r_value);
}
