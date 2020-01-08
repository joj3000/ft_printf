/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 21:09:34 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 21:45:21 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	which_flag(char *str, int i)
{
	int flag;

	flag = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p'
			|| str[i] == 'd' || str[i] == 'i' || str[i] == 'o'
			|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%' || str[i] == 'f')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		return (str[i]);
	return ('z');
}
