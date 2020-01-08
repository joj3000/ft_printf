/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_0_after0x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:50:26 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 18:14:18 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_0_after0x(char *s, int n)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) * (strln(s) + n) + 1)))
		return (0);
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		new[0] = s[0];
		new[1] = s[1];
		j += 2;
		i += 2;
	}
	while (n != 0)
	{
		new[j++] = '0';
		n--;
	}
	while (s[i])
		new[j++] = s[i++];
	new[j] = 0;
	free(s);
	return (new);
}

/*
**#include <stdio.h>
**int main()
**{
**	char *s;
**	s = (char *)malloc(sizeof(char) * 3);
**	s[2] = 0;
**	s[0] = '0';
**	s[1] = 'x';
**	printf("%s", ad_0_after0x(s, 3));
**	free(s);
**}
*/
