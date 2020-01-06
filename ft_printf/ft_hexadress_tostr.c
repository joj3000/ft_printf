/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadress_tostr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:28:04 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 18:07:50 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexadress_tostr(void *p)
{
	unsigned long	adr;
	char			*base;
	char			*res;
	int				i;

	if (!(res = (char *)malloc(sizeof(char) * 16) + 1))
		return (0);
	adr = (unsigned long)p;
	base = "0123456789abcdef";
	i = 0;
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i++;
	}
	res[i] = base[(adr % 16)];
	res[i + 1] = 'x';
	res[i + 2] = '0';
	res[i + 3] = 0;
	return (ft_strrev(ft_strdup(res)));
}

/*
**int main (void)
**{
**char *d = "h";
**
**printf("%p\n",(void *) d);
**printf("%s\n", ft_hexadress_tostr(d));
**
**}
*/
