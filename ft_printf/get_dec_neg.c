/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:13:02 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/02 20:25:12 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		get_dec_neg(long double f)
{
	int			count;
	long double	nb;

	nb = -1;
	count = ct_ndec_digit(f);
	if (count == 0)
		return (-f);
	while (count != 1)
	{
		nb = nb * 10;
		count--;
	}
	while (f <= -1)
	{
		while (ct_ndec_digit(f) == ct_ndec_digit(nb))
			f = f - nb;
		nb /= 10;
		if (nb == 0)
			break ;
	}
	if (f == 0)
		return (0);
	return (-f);
}
