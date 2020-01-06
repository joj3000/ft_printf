/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:18:37 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:27:15 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*steptwo_if_per(char *str, char *s, int i)
{
	int count;

	count = chk_fld_wth(str, i, '%');
	if (chk_flg(str, i, '%', '-') == 1)
		while (count > 1)
		{
			s = ft_strjoin(s, " ");
			count--;
		}
	else if (check_zero_flag(str, i, '%') == 1)
		while (count > 1)
		{
			s = ft_strjoin("0", s);
			count--;
		}
	else if (chk_fld_wth(str, i, '%') >= 2)
		while (count > 1)
		{
			s = ft_strjoin(" ", s);
			count--;
		}
	return (s);
}

void				detected_per(char *str, va_list va, int i)
{
	char *tmp;

	(void)va;
	tmp = ft_strdup("%");
	ft_putstr(steptwo_if_per(str, tmp, i));
	return ;
}

/*
**int	detect_n_do(char *str, va_list va, int i)
**{
**	(void)va;
**	int j;
**
**	j = i + 1;
**	while (str[j])
**	{
**		if (str[j] == '%')
**		{
**			detected_per(str, va, i + 1);
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
**
**      ft_printf("bonjour %-05%\n");
**printf("--------\nbonjour %-05%");
**
**}
*/
