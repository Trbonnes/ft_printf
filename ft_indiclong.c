/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indiclong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:59:19 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 11:59:19 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printlc(va_list *ap, int r_value, size_t **flag)
{
	char	c;
	size_t	length;

	c = (char)va_arg(*ap, wint_t);
	ft_fielddisplay(flag, 1, 0, 0);
	write(1, &c, 1);
	ft_fielddisplay(flag, 1, 1, 0);
	r_value++;
	length = ft_length(flag);
	if (length > 1)
		return (r_value + (int)((length - 1)));
	return (r_value);
}

void	ft_longputstr(wchar_t *str)
{
	char	c;
	size_t	k;

	k = 0;
	while (str[k])
	{
		c = str[k++];
		write(1, &c, 1);
	}
}

int	ft_printls(va_list *ap, int r_value, size_t **flag)
{
	wchar_t	*str;
	wchar_t	*cpy;
	size_t	i;
	size_t	length;

	i = 0;
	str = va_arg(*ap, wchar_t *);
	while (str[i])
		i++;
	if (!flag[2][0])
	{
		ft_fielddisplay(flag, i, 0, 0);
		ft_longputstr(str);
	}
	else
	{
		i = flag[2][1];
		ft_fielddisplay(flag, i, 0, 0);
		if (!(cpy = malloc(sizeof(char) * i + 1)))
			return (-1);
		ft_strllcpy(cpy, str, i + 1);
		ft_longputstr(cpy);
	}
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printldli(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;
	size_t	length;
	int		neg;

	n = ft_longitoa(va_arg(*ap, long long int));
	i = ft_strlen(n);
	neg = 0;
	if (n[0] == '-' && (flag[1][0] || flag[2][0]))
	{
		i--;
		neg = 1;
		n++;
		r_value++;
	}
	else if (n[0] != '-' && flag[5][0])
	{
		if (++i >= 0 && flag[0][0] && !flag[1][0])
			ft_fielddisplay(flag, i, 0, neg);
		ft_putchar_fd('+', 1);
		if (flag[1][0])
			ft_fielddisplay(flag, i, 0, neg);
	}
	if (!flag[5][0] || !flag[0][0])
		ft_fielddisplay(flag, i, 0, neg);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1, neg);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printlu(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;
	size_t	length;

	n = ft_unsigneditoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	ft_fielddisplay(flag, i, 0, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_println(va_list *ap, int r_value)
{
	long long int *n;

	n = va_arg(*ap, long long int *);
	*n = r_value;
	return (r_value);
}
