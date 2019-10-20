/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/20 12:48:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printc(va_list *ap, int r_value)
{
	ft_putchar_fd(va_arg(*ap, int), 1);
	r_value++;
	return (r_value);
}

int	ft_prints(va_list *ap, int r_value)
{
	char	*str;
	size_t	i;

	str = va_arg(*ap, char *);
	i = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (r_value + (int)i);
}

int	ft_printdi(va_list *ap, int r_value)
{
	char	*n;
	size_t	i;

	n = ft_itoa(va_arg(*ap, int));
	i = ft_strlen(n);
	ft_putstr_fd(n, 1);
	return (r_value + (int)i);
}

int	ft_printp(va_list *ap, int r_value)
{
	char	*str;
	void	*ptr;
	size_t	add;
	size_t	i;

	ptr = va_arg(*ap, void *);
	add = (size_t)ptr;
	str = ft_convert_base(add);
	i = ft_strlen(str) + 2;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	return (r_value + (int)i);
}

int	ft_printu(va_list *ap, int r_value)
{
	char	*n;
	size_t	i;

	n = ft_itoa(va_arg(*ap, unsigned int));
	i = ft_strlen(n);
	ft_putstr_fd(n, 1);
	return (r_value + (int)i);
}

int	ft_printx(va_list *ap, int r_value, int maj)
{
	char	*str;
	size_t	nb;
	size_t	i;

	i = -1;
	nb = (size_t)va_arg(*ap, unsigned int);
	str = ft_convert_base(nb);
	if (maj == 1)
		while (str[++i])
			str[i] = ft_toupper((int)str[i]);
	i = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (r_value + (int)i);
}

int	ft_indicconvert(va_list *ap, int r_value, char c)
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
				r_value = ft_indicconvert(&ap, r_value, str[i + 1]);
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
	true = printf("pf: %09d %p %x %X\n", 999, ptr, 256, 216);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	return (0);
}
