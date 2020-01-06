/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 18:26:43 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:09:45 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*stepthree_if_p(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_fld_wth(str, i, 'p') > strln(tmp))
	{
		if (chk_flg(str, i, 'p', '-') == 1)
			tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'p') - strln(tmp));
		else
			tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'p') - strln(tmp));
	}
	return (tmp);
}

void			detected_p(char *str, va_list va, int i)
{
	char *tmp;

	tmp = ft_hexadress_tostr(va_arg(va, void *));
	tmp = stepthree_if_p(str, tmp, i);
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
**		if (str[j] == 'p')
**		{
**			detected_p(str, va, i);
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
**#include <stdio.h>
**int main()
**{
**int *p;
**int a;
**a = 123;
**p = &a;
**
**         ft_printf("bonjour_%16p-\n", p);
***	printf("--------\nbonjour_%16p-", p);
**
**}
*/
