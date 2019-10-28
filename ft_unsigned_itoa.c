/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:24:06 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 08:10:31 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	ft_size(unsigned long long int tmp,
unsigned long long int size)
{
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

static char						*ft_zero(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char						*ft_fullup(unsigned long long int tmp,
unsigned long long int size, unsigned long long int n)
{
	char	*str;
	int		i;

	if (n == 0)
		str = ft_zero();
	else
	{
		if (!(str = malloc(sizeof(char) * size + 1)))
			return (NULL);
		i = size - 1;
		while (tmp > 0)
		{
			str[i--] = ((tmp % 10) + '0');
			tmp = tmp / 10;
		}
		str[size] = '\0';
	}
	return (str);
}

char							*ft_unsigneditoa(unsigned long long int n)
{
	char						*str;
	unsigned long long int		size;
	unsigned long long int		tmp;

	size = 0;
	tmp = n;
	size = ft_size(tmp, size);
	str = ft_fullup(tmp, size, n);
	return (str);
}
