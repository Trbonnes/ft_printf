/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:51:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/04 08:28:15 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagplus(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]) && str[(*i) + j] != '%')
	{
		if (str[(*i) + j] == '+')
			return (1);
		j++;
	}
	return (0);
}

int	ft_flagcomma(const char *str, int *i)
{
	int j;

	j = 0;
	while (!ft_isalpha(str[(*i) + j]) && str[(*i) + j] != '%')
	{
		if (str[(*i) + j] == '\'')
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
	while (str[(*i) + j] <= '0' || str[(*i) + j] > '9')
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
	while (str[(*i) + j] <= '0' || str[(*i) + j] > '9')
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
