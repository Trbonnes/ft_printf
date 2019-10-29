/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:38:16 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/29 11:44:40 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(size_t res_tmp)
{
	size_t len;
	size_t base_len;

	len = 0;
	base_len = 16;
	while (res_tmp >= base_len)
	{
		len++;
		res_tmp = res_tmp / base_len;
	}
	return (len);
}

char	*ft_convert_base(size_t nbr)
{
	char		*result;
	char		*base_to;
	size_t		to_len;
	size_t		rev;

	base_to = "0123456789abcdef";
	to_len = 16;
	if (nbr == 0)
	{
		if (!(result = malloc(sizeof(char) * 2)))
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (!(result = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1))))
		return (NULL);
	rev = (ft_nbrlen(nbr));
	while (nbr > 0)
	{
		result[rev--] = base_to[nbr % to_len];
		nbr = nbr / to_len;
	}
	result[rev] = '\0';
	return (result);
}
