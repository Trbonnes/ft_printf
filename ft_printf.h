/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:53:05 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/18 16:00:50 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libftfolder/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int 	ft_printf(const char *str, ...);
int		ft_printc(va_list *ap, int r_value);
int		ft_prints(va_list *ap, int r_value);
int		ft_printdi(va_list *ap, int r_value);
int		ft_printp(va_list *ap, int r_value);
int		ft_indicconvert(va_list *ap, int r_value, char c);
size_t	ft_nbrlen(size_t res_tmp);
char	*ft_convert_base(size_t nbr);

#endif