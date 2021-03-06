/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:22:15 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 21:48:16 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if ((get_dec(f) > 0 && get_dec(f) < 0.1) ||
			(get_dec_neg(f) > 0 && get_dec_neg(f) < 0.1))
			correct_back_ad01(s);
	}
	if (f < 0)
		s = ft_strjoin("-", s);
	return (s);
}

/*
**int main()
**{
**	long double f;
**
**	f = -123.01;
**
**printf("%s\n", ft_ldtoa(f));
**}
*/
