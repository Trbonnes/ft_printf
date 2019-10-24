/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longitoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:24:20 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/24 15:31:57 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_size(long long int tmp, long long int size)
{
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

static char	*ft_zero(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char				*ft_fullup(long long int tmp, long long int size,
int neg, long long int n)
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
		if (neg == -2)
			str[i--] = '8';
		while (tmp > 0)
		{
			str[i--] = ((tmp % 10) + '0');
			tmp = tmp / 10;
		}
		if (neg < 0)
			str[0] = '-';
		str[size] = '\0';
	}
	return (str);
}

char					*ft_longitoa(long long int n)
{
	char				*str;
	int					neg;
	long long int		size;
	long long int		tmp;

	neg = 1;
	size = 0;
	if (n < 0)
	{
		neg = -1;
		n = -n;
		size++;
	}
	tmp = n;
	size = ft_size(tmp, size);
	str = ft_fullup(tmp, size, neg, n);
	return (str);
}
