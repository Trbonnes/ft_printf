/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indiclong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:59:19 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 10:06:22 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printlc(va_list *ap, int r_value, size_t **flag)
{
	wchar_t	c;
	wchar_t str[2];
	char	*cpy;
	size_t	length;
	size_t	i;

	c = va_arg(*ap, wchar_t);
	str[0] = c;
	str[1] = '\0';
	if (str[0] < 0 || (str[0] > 55295 && str[0] < 57344) || str[0] > 1114111)
		return (-1);
	cpy = ft_wchartochar(str);
	i = ft_strlen(cpy);
	ft_fielddisplay(flag, i, 0, 0);
	ft_putstr_fd(cpy, 1);
	ft_fielddisplay(flag, i, 1, 0);
	if (c == 0 && !flag[0][0])
		i = 1;
	length = ft_length(flag, 0, cpy);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int		ft_printls(va_list *ap, int r_value, size_t **flag)
{
	wchar_t	*str;
	char	*cpy;
	size_t	i;
	size_t	length;

	i = -1;
	str = va_arg(*ap, wchar_t *);
	while (str[++i])
		if (str[i] < 0 || (str[i] > 55295 && str[i] < 57344)
		|| str[i] > 1114111)
			return (-1);
	cpy = ft_wchartochar(str);
	if (!flag[2][0])
		i = ft_strlen(cpy);
	else
	{
		i = flag[2][1];
		cpy[i] = '\0';
	}
	ft_fielddisplay(flag, i, 0, 0);
	ft_putstr_fd(cpy, 1);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag, 0, cpy);
	return (r_value + (length > i ? (int)length : (int)i));
}

int		ft_printldli(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;
	size_t	length;
	int		neg;

	n = ft_longitoa(va_arg(*ap, long long int));
	i = ft_strlen(n);
	if (flag[2][0] && flag[2][1] == 0 && n[0] == '0' && i--)
		n[0] = '\0';
	neg = 0;
	if (n[0] == '-' && (flag[1][0] || flag[2][0]))
	{
		i--;
		neg = 1;
		n++;
		r_value++;
	}
	ft_fielddisplay(flag, i, 0, neg);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1, neg);
	length = (neg ? ft_length(flag, neg, --n) : ft_length(flag, neg, n));
	return (r_value + (length > i ? (int)length : (int)i));
}

int		ft_printlu(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;
	size_t	length;

	n = ft_unsigneditoa(va_arg(*ap, unsigned long long int));
	i = ft_strlen(n);
	if (flag[2][0] && flag[2][1] == 0 && n[0] == '0' && i--)
		n[0] = '\0';
	ft_fielddisplay(flag, i, 0, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag, 0, n);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}
