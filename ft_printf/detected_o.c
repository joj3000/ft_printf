/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:59:42 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:01:12 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_if_o(char *str, va_list va, int i)
{
	char *length_o;

	length_o = NULL;
	if (chk_lng(str, i, 'o') == 'z')
		length_o = ft_ll_itoabase(va_arg(va, long int), 8);
	else if (chk_lng(str, i, 'o') == 'l')
		length_o = ft_ll_itoabase(va_arg(va, long int), 8);
	else if (chk_lng(str, i, 'o') == 'm')
		length_o = ft_ll_itoabase(va_arg(va, long long int), 8);
	else if (chk_lng(str, i, 'o') == 'h')
		length_o = ft_ll_itoabase(va_arg(va, int), 8);
	else if (chk_lng(str, i, 'o') == 'i')
		length_o = ft_ll_itoabase(va_arg(va, int), 8);
	if (ft_strcmp("0", length_o) == 0 && chk_flg(str, i, 'o', '#') == 1)
		return (ft_strdup(""));
	if (ft_strcmp("0", length_o) == 0 && chk_preciz(str, i, 'o') == 0
			&& chk_flg(str, i, 'o', '.') == 1)
		return (ft_strdup(""));
	return (length_o);
}

static char		*steptwo_if_o(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'o', '#') == 1)
	{
			tmp = ft_strjoin("0", s);
			free(s);
			return (tmp);
	}
	return (s);
}

static char		*step3_part2(char *str, char *tmp, int i)
{

		if (chk_preciz(str, i, 'o') > strln(tmp))
			tmp = ad_0_aftersign(tmp, chk_preciz(str, i, 'o') - strln(tmp));
		if (chk_fld_wth(str, i, 'o') > strln(tmp))
		{
			if (chk_flg(str, i, 'o', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'o') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'o') - strln(tmp));
		}
	return (tmp);
}

static char		*stepthree_if_o(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'o') == 0 && chk_flg(str, i, 'o', '.') == 0)
	{
		if (check_zero_flag(str, i, 'o') == 1)
		{
			if (chk_fld_wth(str, i, 'o') > strln(tmp))
				tmp = ad_0_aftersign(tmp, chk_fld_wth(str, i, 'o') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'o') > strln(tmp))
		{
			if (chk_flg(str, i, 'o', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'o') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'o') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}

void			detected_o(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_o(str, va, i);
//printf(">>%s<<", tmp);
	tmp = steptwo_if_o(str, tmp, i);
	tmp = stepthree_if_o(str, tmp, i);
	ft_putstr(tmp);
	return ;
}

/*
**int	detect_n_do(char *str, va_list va, int i)
**{
**	(void)va;
**	int j;
**
**	j = i;
**	while (str[j])
**	{
**		if (str[j] == 'o')
**		{
**			detected_o(str, va, i);
**			break;
**		}
**		j++;
**	}
**	return (j);
**}
**
**void	ft_printf(char *str, ...)
**{
**	va_list va;
**	int i;
**
**	i = 0;
**	if (str == NULL)
**	{
**		write(1, "No input arguments\n", 19);
**		return ;
**	}
**	va_start(va, str);
**	while (str[i])
**	{
**		if (str[i] == '%')
**		{
**			i = detect_n_do(str, va, i);
**		}
**		else
**			write(1, &str[i], 1);
**		i++;
**	}
**}
**
**int main()
**{
**
**long long int nb = 123;
**
**      ft_printf("bonjour %#-12.3llo a\n", nb);
**printf("--------\nbonjour %#-12.3llo a", nb);
**
**}
*/
