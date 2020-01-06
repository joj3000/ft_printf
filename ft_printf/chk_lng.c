/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_lng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:24:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/01 13:44:45 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	chk_lng(char *str, int i, char specifier)
{
	int j;

	j = i;
	while (str[j] != specifier)
	{
		if (str[j] == 'l')
		{
			if (str[j + 1] == 'l')
				return ('m');
			else
				return ('l');
		}
		if (str[j] == 'h')
		{
			if (str[j + 1] == 'h')
				return ('i');
			else
				return ('h');
		}
		if (str[j] == 'L')
			return ('L');
		j++;
	}
	return ('z');
}
