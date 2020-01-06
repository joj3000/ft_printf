/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:15:13 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 10:59:32 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_if_i(char *str, va_list va, int i)
{
	char *length_i;

	length_i = NULL;
	if (chk_lng(str, i, 'i') == 'z')
		length_i = ft_itoa_longlong(va_arg(va, int));
	else if (chk_lng(str, i, 'i') == 'l')
		length_i = ft_itoa_longlong(va_arg(va, long int));
	else if (chk_lng(str, i, 'i') == 'm')
		length_i = ft_itoa_longlong(va_arg(va, long long int));
	else if (chk_lng(str, i, 'i') == 'h')
		length_i = ft_itoa_longlong(va_arg(va, int));
	else if (chk_lng(str, i, 'i') == 'i')
		length_i = ft_itoa_longlong(va_arg(va, int));
	if (ft_strcmp("0", length_i) == 0 && chk_preciz(str, i, 'i') == 0
		&& chk_flg(str, i, 'i', '.') == 1)
		return (ft_strdup(""));
	return (length_i);
}

static char		*steptwo_if_i(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'i', '+') == 1)
	{
		if (s[0] != '-')
		{
			tmp = ft_strjoin("+", s);
			free(s);
			return (tmp);
		}
	}
	else if (chk_flg(str, i, 'i', ' ') == 1)
	{
		if (s[0] != '-')
		{
			tmp = ft_strjoin(" ", s);
			free(s);
			return (tmp);
		}
	}
	return (s);
}
/*
static char		*steptwo_if_i(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'i', '#') == 1)
	{
			tmp = ft_strjoin("0", s);
			free(s);
			return (tmp);
	}
	return (s);
}
*/
static char		*step3_part2(char *str, char *tmp, int i)
{

		if (chk_preciz(str, i, 'i') > strln_sps(tmp))
			tmp = ad_0_aftersps(tmp, chk_preciz(str, i, 'i') - strln_sps(tmp));
		if (chk_fld_wth(str, i, 'i') > strln(tmp))
		{
			if (chk_flg(str, i, 'i', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
		}
	return (tmp);
}

static char		*stepthree_if_i(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'i') == 0 && chk_flg(str, i, 'i', '.') == 0)
	{
		if (check_zero_flag(str, i, 'i') == 1)
		{
			if (chk_fld_wth(str, i, 'i') > strln(tmp))
				tmp = ad_0_aftersps(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'i') > strln(tmp))
		{
			if (chk_flg(str, i, 'i', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}


/*
static char		*stepthree_if_i(char *str, char *s, int i) // free shit ??
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'i') > (int)strln_s(s))
		tmp = ad_0_aftersign(s, chk_preciz(str, i, 'i') - strln_s(s));
	if (chk_fld_wth(str, i, 'i') > strln(tmp))
	{
		if (chk_flg(str, i, 'i', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
	}
	else if (chk_fld_wth(str, i, 'i') > strln(tmp) && chk_flg(str, i, 'i', '0') == 1)
		tmp = ad_0_aftersign(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
	else if (chk_fld_wth(str, i, 'i') > strln(tmp))
	{
		if (chk_flg(str, i, 'i', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'i') - strln(tmp));
	}
	return (tmp);
}
*/
void			detected_i(char *str, va_list va, int i)
{
	char *tmp;
	int j;

	j = 0;
	tmp = string_if_i(str, va, i);
	tmp = steptwo_if_i(str, tmp, i);
	tmp = stepthree_if_i(str, tmp, i);
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
**		if (str[j] == 'i')
**		{
**			detected_i(str, va, i);
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

**	i = 0;
**	if (str == NULL)
**	{
***		write(1, "No input arguments\n", 19);
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
**       ft_printf("bonjour %+012.3lli a\n", nb);
**printf("--------\nbonjour %+012.3lli a", nb);
**
**}
*/
