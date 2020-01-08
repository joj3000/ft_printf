/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_init_preciz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:26:45 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 15:59:09 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_init_preciz(char *s)
{
	int		count;
	char	*new;

	count = 0;
	new = NULL;
	if (ct_af_dot(s) == 0)
		new = ft_strjoin(s, ".000000");
	else if (ct_af_dot(s) > 0 && ct_af_dot(s) < 6)
	{
		count = 6 - ct_af_dot(s);
		new = ft_strjoin(s, "0");
		while (count != 1)
		{
			new = ft_strjoin_free(new, "0");
			count--;
		}
	}
	if (ct_af_dot(s) >= 6)
		return (s);
	free(s);
	return (new);
}
