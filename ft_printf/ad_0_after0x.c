/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_0_after0x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:50:26 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 10:50:45 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_0_after0x(char *s, int nb_zero)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) *
		((int)ft_strlen(s) + nb_zero) + 1)))
		return (0);
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		new[0] = s[0];
		new[1] = s[1];
		j += 2;
		i += 2;
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
