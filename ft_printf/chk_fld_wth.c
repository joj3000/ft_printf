/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_fld_wth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:21:21 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 17:47:32 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chk_fld_wth(char *str, int i, char specifier)
{
	int j;

	j = i;
	while (str[j] != specifier && str[j] != '.')
	{
		if ((str[j] >= '1' && str[j] <= '9'))
			return (ft_atoi(&str[j]));
		j++;
	}
	return (0);
}
