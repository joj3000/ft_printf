/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_preciz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:19:58 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/03 17:59:51 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chk_preciz(char *str, int i, char specifier)
{
	int j;
	int nb;

	j = i;
	nb = 0;
	while (str[j] != specifier)
	{
		if (str[j] == '.')
		{
			if (!(str[j + 1] >= '0' && str[j + 1] <= '9'))
				return (0);
			nb = ft_atoi(&str[j + 1]);
			return (nb);
		}
		j++;
	}
	return (0);
}
