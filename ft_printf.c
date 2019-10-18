/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/18 11:41:35 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	char	*s;
	int		i;
	va_list	ap;
	va_start(ap, str);

	if (!(s = malloc(ft_strlen(str)))
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		while (*str != '%')
			s[i++] = *str++;
		if ((*str + 1) == 'c')
		else if ((*str + 1) == 's')
		else if ((*str + 1) == 'p')
		else if ((*str + 1) == 'd')
		else if ((*str + 1) == 'i')
		else if ((*str + 1) == 'u')
		else if ((*str + 1) == 'x')
		else if ((*str + 1) == 'X')
		else 
	}
	va_end(ap);
}
