/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadress_tostr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:28:04 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 20:53:11 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		malloc_count(unsigned long adr)
{
	int	count;
	int	r;

	count = 0;
	while (adr >= 1)
	{
		r = adr % 16;
		adr = (adr - r) / 16;
		count++;
	}
	return (count);
}

char	*ft_hexadress_tostr(void *p)
{
	unsigned long	adr;
	char			*base;
	char			*res;
	int				i;

	if (!p)
		return (ft_strdup("0x0"));
	adr = (unsigned long)p;
	if (!(res = (char *)malloc(sizeof(char) * malloc_count(adr) + 1)))
		return (0);
	res[malloc_count(adr)] = 0;
	base = "0123456789abcdef";
	i = 0;
	while (adr >= 1)
	{
		res[i] = base[(adr % 16)];
		adr = (adr - (adr % 16)) / 16;
		i++;
	}
	ft_strrev(res);
	res = ft_strjoin_free2("0x", res);
	return (res);
}

/*
**int main (void)
**{
**	char *s;
**	s = "pd";
**	char *d;
**	while (1)
**	{
**	d = ft_hexadress_tostr(s);
**	free(d);
**	}
**	d = ft_hexadress_tostr(s);
**	printf("%d\n", malloc_count(adr));
**	printf("%p\n", (void*)s);
**	printf("%p\n",(void *) d);
**	printf("%s\n", s);
***	free(d);
**	free(d);
**}
*/
