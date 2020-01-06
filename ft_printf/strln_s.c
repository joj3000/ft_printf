/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strln_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:16:58 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 17:17:00 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strln_s(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '-' || s[0] == '+')
		return (i - 1);
	return (i);
}