/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2_if_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:29:00 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 11:22:45 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*step2_if_f(char *str, char *s, int i)
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
