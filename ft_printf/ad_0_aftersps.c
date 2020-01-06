/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_0_aftersps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:26:38 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/05 10:27:08 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_0_aftersps(char *s, int nb_zero)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) *
		((int)ft_strlen(s) + nb_zero) + 1)))
		return (0);
	if (s[0] == '-' || s[0] == '+' || s[0] == ' ')
	{
		new[0] = s[0];
		j++;
		i++;
	}
	while (nb_zero != 0)
	{
		new[j] = '0';
		nb_zero--;
		j++;
	}
	while (s[i])
		new[j++] = s[i++];
	new[j] = 0;
	return (new);
}
