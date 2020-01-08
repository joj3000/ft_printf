/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:52:56 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 15:53:16 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_if_d(char *str, va_list va, int i)
{
	char *length_d;

	length_d = NULL;
	if (chk_lng(str, i, 'd') == 'z')
		length_d = ft_itoa_longlong(va_arg(va, int));
	else if (chk_lng(str, i, 'd') == 'l')
		length_d = ft_itoa_longlong(va_arg(va, long int));
	else if (chk_lng(str, i, 'd') == 'm')
		length_d = ft_itoa_longlong(va_arg(va, long long int));
	else if (chk_lng(str, i, 'd') == 'h')
		length_d = ft_itoa_longlong(va_arg(va, int));
	else if (chk_lng(str, i, 'd') == 'i')
		length_d = ft_itoa_longlong(va_arg(va, int));
	if (ft_strcmp("0", length_d) == 0 && chk_preciz(str, i, 'd') == 0
		&& chk_flg(str, i, 'd', '.') == 1)
	{
		free(length_d);
		return (ft_strdup(""));
	}
	return (length_d);
}

static char		*step2_if_d(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'd', '+') == 1)
	{
		if (s[0] != '-')
		{
			tmp = ft_strjoin("+", s);
			free(s);
			return (tmp);
		}
	}
	else if (chk_flg(str, i, 'd', ' ') == 1)
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

static char		*step3_part2(char *str, char *tmp, int i)
{
	if (chk_preciz(str, i, 'd') > strln_sps(tmp))
		tmp = ad_0_aftersps(tmp, chk_preciz(str, i, 'd') - strln_sps(tmp));
	if (chk_fld_wth(str, i, 'd') > strln(tmp))
	{
		if (chk_flg(str, i, 'd', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'd') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'd') - strln(tmp));
	}
	return (tmp);
}

static char		*step3_if_d(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'd') == 0 && chk_flg(str, i, 'd', '.') == 0)
	{
		if (check_zero_flag(str, i, 'd') == 1)
		{
			if (chk_fld_wth(str, i, 'd') > strln(tmp))
				tmp = ad_0_aftersps(tmp, chk_fld_wth(str, i, 'd') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'd') > strln(tmp))
		{
			if (chk_flg(str, i, 'd', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'd') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'd') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}

void			detected_d(char *str, va_list va, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = string_if_d(str, va, i);
	tmp = step2_if_d(str, tmp, i);
	tmp = step3_if_d(str, tmp, i);
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
**      ft_printf("bonjour %+012.3lli a\n", nb);
**printf("--------\nbonjour %+012.3lli a", nb);
**
**}
*/
