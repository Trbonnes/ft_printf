/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:34:08 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/28 13:52:26 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagspace(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]))
	{
		if (((str[(*i) + j] > '0' && str[*i] <= '9') || str[(*i) + j] == '*') &&
		str[(*i) + (j - 1)] != '.' && str[(*i) + (j - 1)] != '0')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagz(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '0' &&
		!(str[(*i) + (j - 1)] > '0' && str[(*i) + (j - 1)] <= '9'))
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagpre(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '.')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flaghash(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '#')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagmoins(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '-')
			return (1);
		j++;
	}
	return (0);
}
