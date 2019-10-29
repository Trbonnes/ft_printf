/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indicshort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:22:04 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/29 10:03:32 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printhn(va_list *ap, int r_value)
{
	short int *n;

	n = va_arg(*ap, short int *);
	*n = r_value;
	return (r_value);
}

int		ft_printhhn(va_list *ap, int r_value)
{
	char *n;

	n = va_arg(*ap, char *);
	*n = r_value;
	return (r_value);
}
