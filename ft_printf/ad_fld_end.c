/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_fld_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:32:22 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 19:22:49 by jerbs            ###   ########.fr       */
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
	free(s);
	return (new);
}

/*
**int main()
**{
**	char *s;
**
**	s = (char *)malloc(sizeof(char) * 2);
**	s[0] = '1';
**	s[1] = '2';
**	printf("%s", ad_fld_end(s, 2));
**	free(s);
**}
*/
