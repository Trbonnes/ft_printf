/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:31:32 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 10:51:54 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_insertwcharinchar(wchar_t wchar, char *cpy, int i)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		cpy[i++] = wchar;
	else if (size == 2)
	{
		cpy[i++] = (wchar >> 6) + 0xC0;
		cpy[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		cpy[i++] = (wchar >> 12) + 0xE0;
		cpy[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		cpy[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		cpy[i++] = (wchar >> 18) + 0xF0;
		cpy[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		cpy[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		cpy[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

char	*ft_wchartochar(wchar_t *str)
{
	char	*cpy;
	int		i;
	int		j;
	size_t	len;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	len = ft_wbytelen(str);
	if (!(cpy = malloc(sizeof(char*) * len)))
		return (NULL);
	cpy[len] = '\0';
	while (str[j])
	{
		i = ft_insertwcharinchar(str[j], cpy, i);
		j++;
	}
	return (cpy);
}

size_t	ft_wbytelen(wchar_t *str)
{
	size_t	len;
	size_t	bytelen;

	len = ft_wstrlen(str);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += ft_wcharlen(*str);
		str++;
		len--;
	}
	return (bytelen);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*(str++))
		len++;
	return (len);
}

int		ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}
