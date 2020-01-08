/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:07:46 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 16:08:28 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	free(s2);
	return (str);
}

/*
**#include <stdio.h>
**int main()
**{
**	char s1[] = "ceci est un ";
**	char s2[] = "test !";
**
**	printf("%s", ft_strjoin(s1, s2));
**}
*/
