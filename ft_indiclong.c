/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indiclong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:59:19 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/29 09:46:10 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printlc(va_list *ap, int r_value, size_t **flag)
{
	char	c;
	size_t	length;

	c = (char)va_arg(*ap, wint_t);
	ft_fielddisplay(flag, 1, 0, 0);
	write(1, &c, 1);
	ft_fielddisplay(flag, 1, 1, 0);
	r_value++;
	length = ft_length(flag, 0);
	if (length > 1)
		return (r_value + (int)((length - 1)));
	return (r_value);
}

int		ft_printls(va_list *ap, int r_value, size_t **flag)
{
	wchar_t	*str;
	wchar_t	*cpy;
	size_t	i;
	size_t	length;

	i = 0;
	str = va_arg(*ap, wchar_t *);
	if (!flag[2][0])
		while (str[i])
			i++;
	else
		i = flag[2][1];
	ft_fielddisplay(flag, i, 0, 0);
	if (!(cpy = malloc(sizeof(char) * i + 1)))
		return (-1);
	ft_strllcpy(cpy, str, i + 1);
	ft_longputstr(cpy);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag, 0);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int		ft_printldli(va_list *ap, int r_value, size_t **flag)
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
		ft_plusdisplay(&i, flag, neg);
	if (!flag[5][0] || !flag[0][0])
		ft_fielddisplay(flag, i, 0, neg);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1, neg);
	length = ft_length(flag, neg);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int		ft_printlu(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;
	size_t	length;

	n = ft_unsigneditoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	ft_fielddisplay(flag, i, 0, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag, 0);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int	ft_printlx(va_list *ap, int r_value, int maj, size_t **flag)
{
	char	*str;
	size_t	nb;
	size_t	i;
	size_t	length;

	i = -1;
	nb = (size_t)va_arg(*ap, unsigned long int);
	str = ft_convert_base(nb);
	if (maj == 1)
		while (str[++i])
			str[i] = ft_toupper((int)str[i]);
	i = ft_strlen(str);
	ft_fielddisplay(flag, i, 0, 0);
	if (flag[3][0] && i++ && i++)
		ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	ft_fielddisplay(flag, i, 1, 0);
	length = ft_length(flag, 0);
	if (length > i)
		return (r_value + (int)length);
	return (r_value + (int)i);
}

int		ft_println(va_list *ap, int r_value)
{
	long long int *n;

	n = va_arg(*ap, long long int *);
	*n = r_value;
	return (r_value);
}
