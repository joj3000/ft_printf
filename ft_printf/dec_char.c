/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:20:42 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:15:10 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*dec_char(long double f)
{
	long int nb;

	nb = 0;
	if (f > 0 && get_dec(f) < 0.1)
		nb = cv_prec_ftoi(get_dec(f) + 0.1);
	else if (f < 0 && get_dec_neg(f) < 0.1)
		nb = cv_prec_ftoi(get_dec_neg(f) + 0.1);
	else if (f > 0)
		nb = cv_prec_ftoi(get_dec(f));
	else if (f < 0)
		nb = cv_prec_ftoi(get_dec_neg(f));
	return (ft_ldtoa(nb));
}
