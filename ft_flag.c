/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:34:08 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/25 16:11:40 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagspace(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]))
	{
		if ((str[(*i) + j] > '0' && str[*i] <= '9') &&
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
	while (!ft_isalpha(str[(*i) + j]))
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
	while (!ft_isalpha(str[(*i) + j]))
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
	while (!ft_isalpha(str[(*i) + j]))
	{
		if (str[(*i) + j] == '+')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagspacesize(va_list *ap, const char *str, int *i, int check)
{
	int j;

	j = 0;
	if (!check)
		return (0);
	while (str[(*i) + j] <= '0' || str[*i] > '9')
	{
		if (str[(*i) + j] == '*')
			return (va_arg(*ap, int));
		j++;
	}
	return (ft_atoi(str + *i + j));
}

int	ft_flagzsize(va_list *ap, const char *str, int *i, int check)
{
	int j;

	j = 0;
	if (!check)
		return (0);
	while (str[(*i) + j] != '0')
		j++;
	while (str[(*i) + j] <= '0' || str[*i] > '9')
	{
		if (str[(*i) + j] == '*')
			return (va_arg(*ap, int));
		j++;
	}
	return (ft_atoi(str + *i + j));
}

int	ft_flagpresize(va_list *ap, const char *str, int *i, int check)
{
	int j;

	j = 0;
	if (!check)
		return (0);
	while (str[(*i) + j] != '.')
		j++;
	j++;
	if (str[(*i) + j] == '*')
		return (va_arg(*ap, int));
	return (ft_atoi(str + *i + j));
}
