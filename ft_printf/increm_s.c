/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increm_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 20:16:12 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/05 21:23:25 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		part_2(char *s, int p, int i)
{
	int flag;
	
	flag = 1;
	while (flag == 1)
	{
		if (s[i + p] == '.')
			i--;	
		if (s[i + p] == '9')
		{
			s[i + p] = '0';
			flag = 1;
		}
		else
		{
			s[i + p]++;
			flag = 0;
		}
		i--;
	}
}

void			increm_s(char *s, int p)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i] != '.')
		i++;
	if (strln(s) == i)
		return ;
	if (s[i + p + 1] >= '5')
	{
		if (s[i + p] == '.')
			i--;
		if (s[i + p] + 1 < '9')
			s[i + p]++;
		else
		{	
			part_2(s, p, i);	
		}	
	}
}

/*
**#include <stdio.h>
**int main()
**{
**	char *s;
**	int p;
**	
**	p = 1;
**	s = ft_strdup("19.95991");
**	increm_s(s, p);
**	s[2 + p] = 0;
**	printf("%s\n", s);
**}
*/
