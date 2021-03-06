/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:22:28 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 10:52:09 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_size(long long int n, int size)
{
	long long int	tmp;

	tmp = n;
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

	if (!(str = malloc(sizeof(char) * 4)))
		return (NULL);
	str[0] = '0';
	str[1] = '.';
	str[2] = '0';
	str[3] = '\0';
	return (str);
}

static char	*ft_fullup(int size, int neg, long long int n, int point)
{
	char			*str;
	int				i;
	long long int	tmp;

	tmp = n;
	if (n == 0)
		return (str = ft_zero());
	if (!(str = malloc(sizeof(char) * size + 2)))
		return (NULL);
	i = size;
	if (neg == -2)
		str[i--] = '8';
	while (tmp > 0)
	{
		if (i == point)
			str[i--] = '.';
		str[i--] = ((tmp % 10) + '0');
		tmp = tmp / 10;
	}
	if (neg < 0)
		str[0] = '-';
	str[size + 1] = '\0';
	return (str);
}

char		*ft_dtos(double f)
{
	char				*str;
	long long			n;
	int					neg;
	int					size;
	size_t				point;

	point = 0;
	n = ft_dtol(f, &point);
	neg = 1;
	size = 0;
	if (n < 0)
	{
		neg = -1;
		n = -n;
		size++;
		point++;
	}
	size = ft_size(n, size);
	str = ft_fullup(size, neg, n, point);
	return (str);
}
