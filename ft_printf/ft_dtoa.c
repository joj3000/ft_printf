/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 12:04:52 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 21:40:40 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_dtoa(double d)
{
	char		*s;
	long double	f;

	f = d;
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
**	f = -21.0112359815641251;
**printf("%d\n", ct_ndec_digit(f));
**printf("%s\n", ft_dtoa(f));
**ft_dtoa(f);
**}
*/
