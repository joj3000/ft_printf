/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:18:37 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 20:44:34 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*step2_if_per(char *str, char *s, int i)
{
	int		count;
	char	*tmp;

	tmp = s;
	count = chk_fld_wth(str, i, '%');
	if (chk_flg(str, i, '%', '-') == 1)
		while (count > 1)
		{
			tmp = ft_strjoin_free(tmp, " ");
			count--;
		}
	else if (check_zero_flag(str, i, '%') == 1)
		while (count > 1)
		{
			tmp = ft_strjoin_free2("0", tmp);
			count--;
		}
	else if (chk_fld_wth(str, i, '%') >= 2)
		while (count > 1)
		{
			tmp = ft_strjoin_free2(" ", tmp);
			count--;
		}
	return (tmp);
}

void				detected_per(char *str, va_list va, int i)
{
	char *tmp;

	(void)va;
	tmp = ft_strdup("%");
	tmp = step2_if_per(str, tmp, i);
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
**
**int main()
**{
**	char *s;
**
**	s = ft_strdup("bonjour %%\n");
**
**     ft_printf(s);
**printf("--------\nbonjour %%");
**free(s);
**}
*/
