/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:53:05 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/13 14:52:25 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

int			ft_printf(const char *str, ...);
int			ft_indicconvert(va_list *ap, int r_value, char c, size_t **flag);
int			ft_indiclong(va_list *ap, int r_value, char c, size_t **flag);
int			ft_indichh(va_list *ap, int r_value, char c, size_t **flag);
int			ft_indich(va_list *ap, int r_value, char c, size_t **flag);
int			ft_flag(va_list *ap, int r_value, const char *str, int *i);
size_t		**ft_checkflag(va_list *ap, const char *str, int *i);
int			ft_flagspace(const char *str, int *i);
int			ft_flagz(const char *str, int *i);
int			ft_flagpre(const char *str, int *i);
int			ft_flaghash(const char *str, int *i);
int			ft_flagmoins(const char *str, int *i, size_t **flag);
int			ft_flagspacesize(va_list *ap, const char *str, int *i, size_t **c);
int			ft_flagzsize(va_list *ap, const char *str, int *i, size_t **c);
int			ft_flagpresize(va_list *ap, const char *str, int *i, size_t **c);
int			ft_printc(va_list *ap, int r_value, size_t **flag);
int			ft_prints(va_list *ap, int r_value, size_t **flag);
int			ft_printdi(va_list *ap, int r_value, size_t **flag);
int			ft_printp(va_list *ap, int r_value, size_t **flag);
int			ft_printu(va_list *ap, int r_value, size_t **flag);
int			ft_printx(va_list *ap, int r_value, int maj, size_t **flag);
int			ft_printn(va_list *ap, int r_value);
int			ft_printlc(va_list *ap, int r_value, size_t **flag);
int			ft_printls(va_list *ap, int r_value, size_t **flag);
int			ft_printldli(va_list *ap, int r_value, size_t **flag);
int			ft_printlu(va_list *ap, int r_value, size_t **flag);
int			ft_printlx(va_list *ap, int r_value, int maj, size_t **flag);
int			ft_println(va_list *ap, int r_value);
int			ft_printhx(va_list *ap, int r_value, int maj, size_t **flag);
int			ft_printhhx(va_list *ap, int r_value, int maj, size_t **flag);
int			ft_printhn(va_list *ap, int r_value);
int			ft_printhhn(va_list *ap, int r_value);
int			ft_doublef(va_list *ap, int r_value, size_t **flag);
long long	ft_dtol(double f, size_t *i);
void		ft_doublepres(char *str, size_t **flag, size_t *i, size_t *j);
int			ft_standisplay(const char *str, int *i, int r_value);
void		ft_fielddisplay(size_t **flag, size_t i, int bool, int neg);
void		ft_displaypres(size_t **flag, size_t i, int bool, int neg);
void		ft_longputstr(wchar_t *str);
int			ft_flagz(const char *str, int *i);
size_t		**ft_flaglock(void);
size_t		ft_strllcpy(wchar_t *dest, wchar_t *src, size_t n);
size_t		ft_nbrlen(size_t res_tmp, size_t base_len);
char		*ft_convert_base(size_t nbr);
char		*ft_longitoa(long long int n);
char		*ft_unsigneditoa(unsigned long long int n);
char		*ft_dtos(double f);
size_t		ft_isdouble(double dbl, size_t **flag);
size_t		ft_length(size_t **flag, int neg, void *obj);
int			ft_isnan(double dbl);
int			ft_ispinf(double dbl);
int			ft_isninf(double dbl);
int			ft_ismultiple(double dbl, long long mult);
int			ft_printpour(int r_value, size_t **flag);
int			ft_freeandreturn(int r_value, size_t **flag);

#endif
