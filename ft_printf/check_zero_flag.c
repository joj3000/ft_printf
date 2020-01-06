/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 13:17:33 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 17:46:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero_flag(char *str, int i, char specifier)
{
	int j;

	j = i;
	while (str[j] != specifier)
	{
		if (str[j] == '0')
		{
			if (str[j - 1] >= '0' && str[j] <= '9')
				return (0);
			else if (str[j - 1] == '.')
				return (0);
			else
				return (1);
		}
		j++;
	}
	return (0);
}
