/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 08:51:27 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/22 14:14:29 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_fielddisplay(size_t l, size_t *length, size_t i, int bool)
{
	if (length[1] > i && bool == 0)
		if (length[0] == 0)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
	if (length[1] > i && bool == 0)
		if (length[0] == 1)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	if (length[1] > i && bool == 0)
		if (length[0] == 3)
			while (l++ < (length[1] - i))
				ft_putchar_fd('0', 1);
	if (length[1] > i && bool == 1)
		if (length[0] == 2)
			while (l++ < (length[1] - i))
				ft_putchar_fd(' ', 1);
}
