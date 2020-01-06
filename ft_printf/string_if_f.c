/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_if_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:29:19 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:22:42 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*string_if_f(char *str, va_list va, int i)
{
	char *length_f;

	length_f = NULL;
	if (chk_lng(str, i, 'f') == 'z' || chk_lng(str, i, 'f') == 'l')
		length_f = ft_dtoa(va_arg(va, double));
	else if (chk_lng(str, i, 'f') == 'L')
		length_f = ft_ldtoa(va_arg(va, long double));
	return (length_f);
}
