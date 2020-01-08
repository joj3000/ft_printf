/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 13:03:14 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 16:32:34 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../LIBFT/libft.h"
# include <stdarg.h>
# include <stdlib.h>

void		detected_d(char *str, va_list va, int i);
void		detected_i(char *str, va_list va, int i);
void		detected_u(char *str, va_list va, int i);
void		detected_o(char *str, va_list va, int i);
void		detected_x(char *str, va_list va, int i);
void		detected_bx(char *str, va_list va, int i);
void		detected_c(char *str, va_list va, int i);
void		detected_s(char *str, va_list va, int i);
void		detected_p(char *str, va_list va, int i);
void		detected_f(char *str, va_list va, int i);
void		detected_per(char *str, va_list va, int i);

char		*ft_itoa_longlong(long long int n);
char		*ft_hexadress_tostr(void *p);
char		*ft_bl_itoabase(long long int value, int base);
char		*ft_ll_itoabase(long long int value, int base);
char		*ft_ldtoa(long double f);
char		*ft_dtoa(double f);
char		*ad_0_aftersign(char *s, int nb_zero);
char		*ad_0_after0x(char *s, int nb_zero);
char		*ad_0_aftersp(char *s, int nb_zero);
char		*ad_0_aftersps(char *s, int nb_zero);
char		*ad_fld_strt(char *s, int nb_space);
char		*ad_fld_end(char *s, int nb_space);
char		*ad_init_preciz(char *s);
char		*string_if_f(char *str, va_list va, int i);
char		*step2_if_f(char *str, char *s, int i);
char		*non_dec_char(long double f);
char		*dec_char(long double f);
char		chk_lng(char *str, int i, char specifier);
char		which_flag(char *str, int i);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strjoin_free2(char *s1, char *s2);
char		*ft_strsub_free(char *s, int start, int len);

int			chk_preciz(char *str, int i, char specifier);
int			chk_fld_wth(char *str, int i, char specifier);
int			chk_flg(char *str, int i, char specifier, char flag);
int			check_zero_flag(char *str, int i, char specifier);
int			strln(char *s);
int			strln_x(char *s);
int			strln_s(char *s);
int			strln_sp(char *s);
int			strln_sps(char *s);
int			ct_ndec_digit(long double f);
int			is_dec(long double f);
int			is_s_dec(char *s);
int			ct_af_dot(char *s);
int			locate_char_index(char *s, char c);

long double	get_dec(long double f);
long double	get_dec_neg(long double f);

long int	cv_prec_ftoi(long double d);

void		ft_printf(char *str, ...);
void		correct_back_ad01(char *s);
void		increm_s(char *s, int p);

#endif
