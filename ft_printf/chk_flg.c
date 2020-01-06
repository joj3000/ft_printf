/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_flg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:23:27 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 18:06:29 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chk_flg(char *str, int i, char specifier, char flag)
{
	int j;

	j = i;
	while (str[j] != specifier)
	{
		if (str[j] == flag)
			return (1);
		j++;
	}
	return (0);
}
