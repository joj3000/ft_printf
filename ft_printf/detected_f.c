/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 11:18:07 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:05:44 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *preciz_part2(char *str, int i, char *s, int ct)
{
	int count;

	count = 0;
	if (ct >= 6)
	{
		increm_s(s, chk_preciz(str, i, 'f')); 
		while (ct > 6)
		{
			s = ft_strjoin(s, "0");
			ct--;
		}
	}
	else
	{	
		ct = 6 - ct;
		s = ft_strsub(s, 0, strln(s) - ct);
	}
	return (s);
}

static char *preciz(char *str, char *s, int i)
{
	int ct;

	if (chk_preciz(str, i, 'f') == 0 && chk_flg(str, i, 'f', '.') == 1)
	{
		if (locate_char_index(s, '.') != -41)
		{	
			if (s[locate_char_index(s, '.') + 1] >= 53)
				s[locate_char_index(s, '.') - 1]++;
		}
		if (chk_flg(str, i, 'f', '#'))
			s = ft_strsub(s, 0, (size_t)locate_char_index(s, '.') + 1);
		else
			s = ft_strsub(s, 0, (size_t)locate_char_index(s, '.'));
	}
	else if (chk_preciz(str, i, 'f') > 0)
	{
		ct = chk_preciz(str, i, 'f');
		s = preciz_part2(str, i, s, ct);	
	}
	return (s);
}

static char		*steptwo_if_f(char *str, char *s, int i)
{
	char *tmp;

	if (chk_flg(str, i, 'f', '+') == 1)
	{
		if (s[0] != '-')
		{
			tmp = ft_strjoin("+", s);
			free(s);
			return (tmp);
		}
	}
	else if (chk_flg(str, i, 'f', ' ') == 1)
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
		if (chk_fld_wth(str, i, 'f') > strln(tmp))
		{
			if (check_zero_flag(str, i, 'f') == 1)
			{
				if (chk_flg(str, i, 'f', '-') == 1)
					tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
				else
					tmp = ad_0_aftersps(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
			}
			else
			{	
				if (chk_flg(str, i, 'f', '-') == 1)
					tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
				else
					tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
			}
		}
	return (tmp);
}

static char		*stepthree_if_f(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'f') == 0 && chk_flg(str, i, 'f', '.') == 0)
	{
		if (check_zero_flag(str, i, 'f') == 1)
		{
			if (chk_fld_wth(str, i, 'f') > strln(tmp))
				tmp = ad_0_aftersps(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'f') > strln(tmp))
		{
			if (chk_flg(str, i, 'f', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'f') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}

void			detected_f(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_f(str, va, i);
	tmp = steptwo_if_f(str, tmp, i);
	tmp = ad_init_preciz(tmp);
	tmp = preciz(str, tmp, i);
	tmp = stepthree_if_f(str, tmp, i);
	
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
**		if (str[j] == 'f')
**		{
**			detected_f(str, va, i);
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
**long double nb = 0;
**
**      ft_printf("bonjour %-+8.04Lf a\n", nb);
**printf("--------\nbonjour %-+8.04Lf a", nb);
**
**}
*/
