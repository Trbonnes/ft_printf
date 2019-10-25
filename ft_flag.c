/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:34:08 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/25 12:28:28 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagspace(const char *str, int *i)
{
	if (str[*i] > '0' && str[*i] <= '9')
		return (1);
	return (0);
}

int	ft_flagz(const char *str, int *i)
{
	int j;

	j = 0;
	while ((str[(*i) + j] >= 'a' && str[(*i) + j] <= 'z') ||
	(str[(*i) + j] >= 'A' && str[(*i) + j] <= 'Z'))
	{
		if (str[*i] == '0' && !(str[(*i) + j] > '0' && str[(*i) + j] <= '9'))
		{
			while (str[*i] == '0')
				(*i)++;
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_flagpre(const char *str, int *i)
{
	int j;

	j = 0;
	while ((str[(*i) + j] >= 'a' && str[(*i) + j] <= 'z') ||
	(str[(*i) + j] >= 'A' && str[(*i) + j] <= 'Z'))
	{
		if (str[*i] == '.')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flaghash(const char *str, int *i)
{
	int j;

	j = 0;
	while ((str[(*i) + j] >= 'a' && str[(*i) + j] <= 'z') ||
	(str[(*i) + j] >= 'A' && str[(*i) + j] <= 'Z'))
	{
		if (str[*i] == '#')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagmoins(const char *str, int *i)
{
	int j;

	j = 0;
	while ((str[(*i) + j] >= 'a' && str[(*i) + j] <= 'z') ||
	(str[(*i) + j] >= 'A' && str[(*i) + j] <= 'Z'))
	{
		if (str[*i] == '-')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagplus(const char *str, int *i)
{
	int j;

	j = 0;
	while ((str[(*i) + j] >= 'a' && str[(*i) + j] <= 'z') ||
	(str[(*i) + j] >= 'A' && str[(*i) + j] <= 'Z'))
		if (str[(*i) + j] == '+')
			return (1);
	return (0);
}
