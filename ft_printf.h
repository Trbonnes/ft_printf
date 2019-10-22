/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:53:05 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/22 08:56:15 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libftfolder/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printc(va_list *ap, int r_value, size_t *length);
int		ft_prints(va_list *ap, int r_value, size_t *length);
int		ft_printdi(va_list *ap, int r_value, size_t *length);
int		ft_printp(va_list *ap, int r_value, size_t *length);
int		ft_printu(va_list *ap, int r_value, size_t *length);
int		ft_printx(va_list *ap, int r_value, int maj, size_t *length);
int		ft_indicconvert(va_list *ap, int r_value, char c, size_t *length);
size_t	ft_nbrlen(size_t res_tmp);
char	*ft_convert_base(size_t nbr);
int		ft_flag(va_list *ap, int r_value, const char *str, int *i);
int		ft_standisplay(const char *str, int *i, int r_value);
void	ft_fielddisplay(size_t l, size_t *length, size_t i, int bool);

#endif
