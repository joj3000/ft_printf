/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:28:54 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/07 20:44:00 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub_free(char *s, int start, int len)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
	{
		cpy[i] = s[start + i];
		len--;
		i++;
	}
	cpy[i] = 0;
	free(s);
	return (cpy);
}

/*
**#include <stdio.h>
**int main()
**{
**	const char str[] = "this is a test";
**
**	printf("%s", ft_substr(str, 1, 15));
**}
*/
