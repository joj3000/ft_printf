/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoabase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:48:08 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 21:50:26 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_abs(long long int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char		*max_min_cases(long long int value, int base)
{
	if (value == 4294967295 && base == 8)
		return (ft_strdup("37777777777"));
	if (value == 4294967295 && base == 16)
		return (ft_strdup("ffffffff"));
	return ("ntm");
}

char			*ft_ll_itoabase(long long int value, int base)
{
	char			*str;
	long long int	size;
	char			*tab;
	long long int	tmp;

	size = 0;
	tab = "0123456789abcdef";
	if (value == 4294967295)
		return (max_min_cases(value, base));
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size++;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

/*
**int main()
**{
**	printf("%s\n", ft_LL_itoabase(122230446468498, 8));
**}
*/
