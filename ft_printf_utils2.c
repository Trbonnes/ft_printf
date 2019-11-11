/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:49:44 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/11 09:22:10 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

size_t	**ft_flaglock(void)
{
	size_t	**flag;
	size_t	i;

	i = 0;
	if (!(flag = malloc(sizeof(size_t *) * 8)))
		return (NULL);
	while (i < 8)
	{
		if (!(flag[i++] = malloc(sizeof(size_t) * 2)))
			return (NULL);
	}
	return (flag);
}

size_t	ft_length(size_t **flag, int neg)
{
	size_t length;

	length = 0;
	if (flag[0][0] && !flag[1][0])
		length = length + (flag[0][1] - flag[2][1] - (size_t)neg);
	if (flag[1][0])
		length = length + (flag[1][1] - flag[2][1] - (size_t)neg);
	if (flag[2][0] && flag[1][0])
		length = length + flag[2][1];
	else if (flag[2][0])
		length = length + flag[2][1];
	return (length);
}

size_t	ft_strllcpy(wchar_t *dest, wchar_t *src, size_t n)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	if (!dest || !src)
		return (0);
	while (src[count] != '\0')
		count++;
	if (n == 0)
		return (count);
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 1)
		dest[i] = '\0';
	return (count);
}

void	ft_longputstr(wchar_t *str)
{
	char	c;
	size_t	k;

	k = 0;
	while (str[k])
	{
		c = str[k++];
		write(1, &c, 1);
	}
}

char	*ft_commacpy(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	if (str[0] == '-')
		i--;
	return (str);
}
