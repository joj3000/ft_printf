/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:22:15 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/05 21:23:35 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void			gotcha_bitch(char *s)
{
	int i;

	i = 0;
	while (s[i] != '.')
		i++;
	i++;
	s[i]--;
	return ;
}
*/
char				*ft_ldtoa(long double f)
{
	char	*s;

	if (f == 0)
		return (ft_strdup("0"));
	s = non_dec_char(f);
	if (is_dec(f) == 1)
	{
		s = ft_strjoin(s, ".");
		s = ft_strjoin(s, dec_char(f));
		if ((get_dec(f) > 0 && get_dec(f) < 0.1) || (get_dec_neg(f) > 0 && get_dec_neg(f) < 0.1))
			correct_back_ad01(s);
	}
/*	if (f > 0 && is_dec(f) == 1 && get_dec(f) < 0.1)
		gotcha_bitch(s);
	else if (f < 0 && is_dec(f) == 1 && get_dec_neg(f) < 0.1)
		gotcha_bitch(s);
*/	if (f < 0)
		s = ft_strjoin("-", s);
//printf("-> %s <-\n", s);
	return (s);
}

/*
int main()
{
	long double f;

	f = -123.01;

printf("%s\n", ft_ldtoa(f));
}
*/
