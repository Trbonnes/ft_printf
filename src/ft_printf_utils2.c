/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:49:44 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 10:51:57 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	**ft_flaglock(void)
{
	size_t	**flag;
	size_t	i;

	i = 0;
	if (!(flag = malloc(sizeof(size_t *) * 5)))
		return (NULL);
	while (i < 5)
	{
		if (!(flag[i++] = malloc(sizeof(size_t) * 2)))
			return (NULL);
	}
	return (flag);
}

size_t	ft_length(size_t **flag, int neg, void *obj)
{
	size_t length;

	length = 0;
	if (flag[0][0] && !flag[1][0] && flag[0][1] > flag[2][1])
		length = length + (flag[0][1] - flag[2][1] - (size_t)neg);
	if (flag[1][0] && flag[1][1] && flag[1][1] > flag[2][1])
		length = length + (flag[1][1] - flag[2][1] - (size_t)neg);
	if (flag[2][0] && flag[1][0])
		length = length + flag[2][1];
	else if (flag[2][0])
		length = length + flag[2][1];
	if (obj)
		free(obj);
	return (length);
}
