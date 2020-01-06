/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_fld_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:32:22 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 17:45:54 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_fld_end(char *s, int nb_space)
{
	char *temp;
	char *new;

	new = NULL;
	if (!(temp = (char *)malloc(sizeof(char) * (nb_space) + 1)))
		return (NULL);
	temp[nb_space] = 0;
	while (nb_space != 0)
	{
		temp[nb_space - 1] = ' ';
		nb_space--;
	}
	new = ft_strjoin(s, temp);
	free(temp);
	return (new);
}
