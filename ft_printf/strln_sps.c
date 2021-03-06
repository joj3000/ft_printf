/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strln_sps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:23:51 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/05 10:24:42 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strln_sps(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '-' || s[0] == '+' || s[0] == ' ')
		return (i - 1);
	return (i);
}
