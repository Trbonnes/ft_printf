/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/18 16:07:48 by trbonnes         ###   ########.fr       */
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
		;
	else if (c == 'x')
		;
	else if (c == 'X')
		;
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
	ft = ft_printf("Bonjour Beaucoup %c %s %d %i %p\n", 54, "Ntm Trostan", 2147483647, 987, ptr);
	true = printf("Bonjour Beaucoup %c %s %d %i %p\n", 54, "Ntm Trostan", 2147483647, 987, ptr);
	printf("ft: %d\n", ft);
	printf("gold standard: %d\n", true);
	return (0);
}
