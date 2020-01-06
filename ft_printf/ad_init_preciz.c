/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_init_preciz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:26:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/05 21:23:28 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ad_init_preciz(char *s)
{
	int count;

	count = 0;
	if (ct_af_dot(s) == 0)
		s = ft_strjoin(s, ".000000");
	else if	(ct_af_dot(s) > 0)
	{
		count = 6 - ct_af_dot(s);
		while (count != 0)
		{
			s = ft_strjoin(s, "0");
			count--;
		}
	}
	return (s);
}
