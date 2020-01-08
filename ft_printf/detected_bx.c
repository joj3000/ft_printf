/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_bx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:33:33 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 15:55:36 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*string_if_bx(char *str, va_list va, int i)
{
	char *length_bx;

	length_bx = NULL;
	if (chk_lng(str, i, 'X') == 'z')
		length_bx = ft_bl_itoabase(va_arg(va, long int), 16);
	else if (chk_lng(str, i, 'X') == 'l')
		length_bx = ft_bl_itoabase(va_arg(va, long int), 16);
	else if (chk_lng(str, i, 'X') == 'm')
		length_bx = ft_bl_itoabase(va_arg(va, long long int), 16);
	else if (chk_lng(str, i, 'X') == 'h')
		length_bx = ft_bl_itoabase(va_arg(va, int), 16);
	else if (chk_lng(str, i, 'X') == 'i')
		length_bx = ft_bl_itoabase(va_arg(va, int), 16);
	if (ft_strcmp("0", length_bx) == 0 && chk_preciz(str, i, 'X') == 0
			&& chk_flg(str, i, 'X', '.') == 1)
	{
		free(length_bx);
		return (ft_strdup(""));
	}
	return (length_bx);
}

static char		*step2_if_bx(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'X', '#') == 1 && ft_strcmp(s, "0") == 0)
		return (s);
	if (chk_flg(str, i, 'X', '#') == 1 && ft_strcmp(s, "") == 0 &&
		chk_flg(str, i, 'X', '.') == 1)
	{
		free(s);
		return (ft_strdup(""));
	}
	if (chk_flg(str, i, 'X', '#') == 1)
	{
		tmp = ft_strjoin("0X", s);
		free(s);
		return (tmp);
	}
	return (s);
}

static char		*step3_part2(char *str, char *tmp, int i)
{
	if (chk_preciz(str, i, 'X') > strln_x(tmp))
		tmp = ad_0_after0x(tmp, chk_preciz(str, i, 'X') - strln_x(tmp));
	if (chk_fld_wth(str, i, 'X') > strln(tmp))
	{
		if (chk_flg(str, i, 'X', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'X') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'X') - strln(tmp));
	}
	return (tmp);
}

static char		*step3_if_bx(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'X') == 0 && chk_flg(str, i, 'X', '.') == 0)
	{
		if (check_zero_flag(str, i, 'X') == 1)
		{
			if (chk_fld_wth(str, i, 'X') > strln(tmp))
				tmp = ad_0_after0x(tmp, chk_fld_wth(str, i, 'X') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'X') > strln(tmp))
		{
			if (chk_flg(str, i, 'X', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'X') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'X') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}

void			detected_bx(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_bx(str, va, i);
	tmp = step2_if_bx(str, tmp, i);
	tmp = step3_if_bx(str, tmp, i);
	ft_putstr(tmp);
	free(tmp);
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
**		if (str[j] == 'X')
**		{
**			detected_bx(str, va, i);
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
**     ft_printf("bonjour %#-12.16llX a\n", nb);
**printf("--------\nbonjour %#-12.16llX a", nb);
**
**}
*/
