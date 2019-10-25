/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indiclong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:59:19 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/25 11:18:30 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printlc(va_list *ap, int r_value, size_t **flag)
{
	char	c;

	c = (char)va_arg(*ap, wint_t);
	ft_fielddisplay(flag, 1, 0);
	write(1, &c, 1);
	ft_fielddisplay(flag, 1, 1);
	r_value++;
	if (flag[1] > 1)
		return (r_value + (int)((flag[1] - 1)));
	return (r_value);
}

int	ft_printls(va_list *ap, int r_value, size_t **flag)
{
	wchar_t	*str;
	char	c;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	str = va_arg(*ap, wchar_t *);
	while (str[i])
		i++;
	ft_fielddisplay(flag, i, 0);
	while (str[k])
	{
		c = str[k++];
		write(1, &c, 1);
	}
	ft_fielddisplay(flag, i, 1);
	if (flag[1] > i)
		return (r_value + (int)((flag[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printldli(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;

	n = ft_longitoa(va_arg(*ap, long long int));
	i = ft_strlen(n);
	if (n[0] == '-' && (flag[0] == 1 || flag[0] == 3))
	{
		i--;
		ft_putchar_fd('-', 1);
		n++;
		r_value++;
	}
	else if (n[0] != '-' && flag[2] == 1)
	{
		if (++i >= 0 && flag[0] == 0)
			ft_fielddisplay(flag, i, 0);
		ft_putchar_fd('+', 1);
	}
	if (flag[2] != 1 || flag[0] != 0)
		ft_fielddisplay(flag, i, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1);
	if (flag[1] > i)
		return (r_value + (int)((flag[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_printlu(va_list *ap, int r_value, size_t **flag)
{
	char	*n;
	size_t	i;

	n = ft_unsigneditoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	ft_fielddisplay(flag, i, 0);
	ft_putstr_fd(n, 1);
	ft_fielddisplay(flag, i, 1);
	if (flag[1] > i)
		return (r_value + (int)((flag[1] - i) + i));
	return (r_value + (int)i);
}

int	ft_println(va_list *ap, int r_value)
{
	long long int *n;

	n = va_arg(*ap, long long int *);
	*n = r_value;
	return (r_value);
}
