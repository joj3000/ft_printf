/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_fld_strt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:30:53 by jerbs             #+#    #+#             */
/*   Updated: 2019/12/30 17:46:25 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ad_fld_strt(char *s, int nb_space)
{
	int		i;
	int		j;
	char	*new;
	char	*temp;

	i = 0;
	j = 0;
	new = NULL;
	if (!(temp = (char *)malloc(sizeof(char) * (nb_space) + 1)))
		return (NULL);
	while (nb_space != 0)
	{
		temp[i] = ' ';
		i++;
		nb_space--;
	}
	temp[i] = 0;
	new = ft_strjoin(temp, s);
	free(temp);
	return (new);
}
