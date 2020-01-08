/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_0_aftersign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:29:02 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 18:15:34 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_0_aftersign(char *s, int n)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) * (strln(s) + n) + 1)))
		return (0);
	if (s[0] == '-' || s[0] == '+')
	{
		new[0] = s[0];
		j++;
		i++;
	}
	while (n != 0)
	{
		new[j] = '0';
		n--;
		j++;
	}
	while (s[i])
		new[j++] = s[i++];
	new[j] = 0;
	free(s);
	return (new);
}
