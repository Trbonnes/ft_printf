/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/25 17:05:59 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_schlag(size_t **flag)
{
//	printf("flag[0][0]: %zu\n", flag[0][0]);
	printf("flag[1][0]: %zu\n", flag[1][0]);
//	printf("flag[2][0]: %zu\n", flag[2][0]);
//	printf("flag[3][0]: %zu\n", flag[3][0]);
//	printf("flag[4][0]: %zu\n", flag[4][0]);
	printf("flag[5][0]: %zu\n", flag[5][0]);
//	printf("flag[0][1]: %zu\n", flag[0][1]);
	printf("flag[1][1]: %zu\n", flag[1][1]);
//	printf("flag[2][1]: %zu\n", flag[2][1]);
//	printf("flag[3][1]: %zu\n", flag[3][1]);
//	printf("flag[4][1]: %zu\n", flag[4][1]);
	printf("flag[5][1]: %zu\n", flag[5][1]);
}

int	ft_flag(va_list *ap, int r_value, const char *str, int *i)
{
	size_t	**flag;

	if (!(flag = ft_flaglock()))
		return (-1);
	(*i)++;
	flag[0][0] = ft_flagspace(str, i);
	flag[1][0] = ft_flagz(str, i);
	flag[2][0] = ft_flagpre(str, i);
	flag[3][0] = ft_flaghash(str, i);
	flag[4][0] = ft_flagmoins(str, i);
	flag[5][0] = ft_flagplus(str, i);
	flag[0][1] = ft_flagspacesize(ap, str, i, flag[0][0]);
	flag[1][1] = ft_flagzsize(ap, str, i, flag[1][0]);
	flag[2][1] = ft_flagpresize(ap, str, i, flag[2][0]);
	flag[3][1] = 0;
	flag[4][1] = 0;
	flag[5][1] = 0;
	//ft_schlag(flag);
	while (!ft_isalpha(str[*i]))
		(*i)++;
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
		(*i)++;
	if ((str[*i] == 'l' && str[(*i) + 1] == 'l') ||
	(str[*i] == 'h' && str[(*i) + 1] == 'h'))
		(*i)++;
	if (str[*i] == 'l' || str[*i] == 'h')
		return (r_value = ft_indiclong(ap, r_value, str[++(*i)], flag));
	return (r_value = ft_indicconvert(ap, r_value, str[*i], flag));
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
	else if (c == 'n')
		r_value = ft_println(ap, r_value);
	return (r_value);
}

int	ft_indicconvert(va_list *ap, int r_value, char c, size_t **flag)
{
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
	return (r_value);
}

int	ft_printf(const char *str, ...)
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
			if ((str[i + 1]) == '%')
				r_value = ft_standisplay(str, &i, r_value);
			else
				r_value = ft_flag(&ap, r_value, str, &i);
			i++;
		}
		else
			r_value = ft_standisplay(str, &i, r_value);
	}
	va_end(ap);
	return (r_value);
}
