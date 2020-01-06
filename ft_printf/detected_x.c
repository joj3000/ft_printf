/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:14:21 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:02:26 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*string_if_x(char *str, va_list va, int i)
{
	char *length_x;

	length_x = NULL;
	if (chk_lng(str, i, 'x') == 'z')
		length_x = ft_ll_itoabase(va_arg(va, long int), 16);
	else if (chk_lng(str, i, 'x') == 'l')
		length_x = ft_ll_itoabase(va_arg(va, long int), 16);
	else if (chk_lng(str, i, 'x') == 'm')
		length_x = ft_ll_itoabase(va_arg(va, long long int), 16);
	else if (chk_lng(str, i, 'x') == 'h')
		length_x = ft_ll_itoabase(va_arg(va, int), 16);
	else if (chk_lng(str, i, 'x') == 'i')
		length_x = ft_ll_itoabase(va_arg(va, int), 16);
	if (ft_strcmp("0", length_x) == 0 && chk_preciz(str, i, 'x') == 0
			&& chk_flg(str, i, 'x', '.') == 1)
		return (ft_strdup(""));
	return (length_x);
}

static char		*steptwo_if_x(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'x', '#') == 1 && ft_strcmp(s, "0") == 0)
			return (s);
	if (chk_flg(str, i, 'x', '#') == 1 && ft_strcmp(s, "") == 0 &&
		chk_flg(str, i, 'x', '.') == 1)
	{
		free(s);
		return (ft_strdup(""));
	}
	else if (chk_flg(str, i, 'x', '#') == 1)
	{
			tmp = ft_strjoin("0x", s);
			free(s);
			return (tmp);
	}
	return (s);
}


static char		*step3_part2(char *str, char *tmp, int i)
{

		if (chk_preciz(str, i, 'x') > strln_x(tmp))
			tmp = ad_0_after0x(tmp, chk_preciz(str, i, 'x') - strln_x(tmp));
		if (chk_fld_wth(str, i, 'x') > strln(tmp))
		{
			if (chk_flg(str, i, 'x', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
		}
	return (tmp);
}

static char		*stepthree_if_x(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'x') == 0 && chk_flg(str, i, 'x', '.') == 0)
	{
		if (check_zero_flag(str, i, 'x') == 1)
		{
			if (chk_fld_wth(str, i, 'x') > strln(tmp))
				tmp = ad_0_after0x(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'x') > strln(tmp))
		{
			if (chk_flg(str, i, 'x', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}

/*
static char		*stepthree_if_x(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'x') > strln_x(s))
		tmp = ad_0_after0x(s, chk_preciz(str, i, 'x') - strln_x(s));
	if (chk_fld_wth(str, i, 'x') > strln(tmp))
	{
		if (chk_flg(str, i, 'x', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
	}
	else if (chk_fld_wth(str, i, 'x') > strln(tmp) &&
			chk_flg(str, i, 'x', '0') == 1)
		tmp = ad_0_after0x(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
	else if (chk_fld_wth(str, i, 'x') > strln(tmp))
	{
		if (chk_flg(str, i, 'x', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'x') - strln(tmp));
	}
	return (tmp);
}
*/

void			detected_x(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_x(str, va, i);
	tmp = steptwo_if_x(str, tmp, i);
	tmp = stepthree_if_x(str, tmp, i);
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
**		if (str[j] == 'x')
**		{
**			detected_x(str, va, i);
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
**      ft_printf("bonjour %#llx a\n", nb);
**printf("--------\nbonjour %#llx a", nb);
**
**}
*/
