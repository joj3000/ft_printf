/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:58:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 15:54:15 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_if_c(char *str, va_list va, int i)
{
	char *length_c;

	(void)str;
	(void)i;
	length_c = (char*)malloc(sizeof(char) + 1);
	length_c[0] = (char)va_arg(va, int);
	length_c[1] = 0;
	if (length_c[0] == 0)
	{
		free(length_c);
		return (ft_strdup(""));
	}
	return (length_c);
}

static char		*step3_if_c(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_fld_wth(str, i, 'c') > strln(tmp))
	{
		if (chk_flg(str, i, 'c', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'c') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'c') - strln(tmp));
	}
	return (tmp);
}

void			detected_c(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_c(str, va, i);
	tmp = step3_if_c(str, tmp, i);
	ft_putstr(tmp);
	free(tmp);
	return ;
}

/*
**int				detect_n_do(char *str, va_list va, int i)
**{
**	int j;
**
**	(void)va;
**	j = i;
**	while (str[j])
**	{
**		if (str[j] == 'c')
**		{
**			detected_c(str, va, i);
**			break ;
**		}
**		j++;
**	}
**	return (j);
**}
**
**void			ft_printf(char *str, ...)
**{
**	va_list	va;
**	int		i;
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
**#include <stdio.h>
**int main()
**{
**char c = 48;
**
**write(1, "\n", 1);
**  printf("hello %-2c_\n", c);
**ft_printf("hello %-2c_\n", c);
**
**}
*/
