/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 17:45:27 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 15:54:24 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_if_s(char *str, va_list va, int i)
{
	char *length_s;

	(void)str;
	(void)i;
	length_s = va_arg(va, char *);
	if (length_s == NULL)
		return (length_s = ft_strdup("(null)"));
	return (ft_strdup(length_s));
}

static char		*step3_if_s(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 's') < strln_s(s) && chk_flg(str, i, 's', '.') == 1)
	{
		tmp = ft_strsub(s, 0, chk_preciz(str, i, 's'));
		free(s);
	}
	if (chk_fld_wth(str, i, 's') > strln(tmp))
	{
		if (chk_flg(str, i, 's', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 's') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 's') - strln(tmp));
	}
	return (tmp);
}

void			detected_s(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_s(str, va, i);
	tmp = step3_if_s(str, tmp, i);
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
**		if (str[j] == 's')
**		{
**			detected_s(str, va, i);
**			break;
**		}
**		j++;
**	}
**	return (j);
**}
**
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
**
**#include <stdio.h>
**int main()
**{
**char *s = NULL;
**
**      ft_printf("bonjour, %s.", s);
**
**printf("\n--------\nbonjour,  %s.", s);
**
**}
*/
