/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strln_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 19:06:43 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/31 19:12:15 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strln_sp(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == ' ')
		return (i - 1);
	return (i);
}
