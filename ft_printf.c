/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/21 11:01:09 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_flag(va_list *ap, int r_value, char c, char *str)
{
	int i;
	int length[2];
	int	zero;

	i = 0;
	length[0] = 0;
	if (str[i] == '0')
	{
		length[0] = 1;
		while (str[i] == '0')
			i++;
	}
	else if (str[i++] == '-')
		length[0] = 2;
	length[1] = ft_atoi(str + i);
	r_value = ft_indicconvert(&ap, r_value, c, length);
	return (r_value);
}

int	ft_indicconvert(va_list *ap, int r_value, char c, int *length)
{
	if (c == 'c')
		r_value = ft_printc(ap, r_value);
	else if (c == 's')
		r_value = ft_prints(ap, r_value);
	else if (c == 'p')
		r_value = ft_printp(ap, r_value);
	else if (c == 'd')
		r_value = ft_printdi(ap, r_value);
	else if (c == 'i')
		r_value = ft_printdi(ap, r_value);
	else if (c == 'u')
		r_value = ft_printu(ap, r_value);
	else if (c == 'x')
		r_value = ft_printx(ap, r_value, 0);
	else if (c == 'X')
		r_value = ft_printx(ap, r_value, 1);
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
			{
				ft_putchar_fd(str[i], 1);
				r_value++;
			}
			else
				r_value = ft_flag(&ap, r_value, str[i + 1], (str + i + 1));
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(str[i++], 1);
			r_value++;
		}
	}
	va_end(ap);
	return (r_value);
}

int	main(void)
{
	int ft;
	int true;
	char *ptr;

	ptr = malloc(1);
	ft = ft_printf("ft: %d %p %x %X\n", 999, ptr, 256, 216);
	true = printf("pf: %9d %p %x %X\n", 999, ptr, 256, 216);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	return (0);
}
