/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strln_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:28:41 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 20:31:21 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strln_x(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		return (i - 2);
	return (i);
}