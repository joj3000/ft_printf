/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv_prec_ftoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:14:52 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:14:51 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int				cv_prec_ftoi(long double d)
{
	int			neg;
	int			i;
	long int	tmp;

	i = -1;
	neg = (d < 0 ? -1 : 1);
	d *= neg;
	while (++i < 6)
		d *= 10;
	d += 0.5;
	d *= neg;
	tmp = (long int)d;
	while (tmp % 10 == 0 && tmp != 0)
		tmp /= 10;
	return (tmp);
}

/*
int main()
{
	long double i = 1100001.0999996861231;
	printf("%ld\n", cv_prec_ftoi(i));

	printf("%s\n", dec_char(i));
}
*/
