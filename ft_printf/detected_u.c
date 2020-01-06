/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detected_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:26:34 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:00:43 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*string_if_u(char *str, va_list va, int i)
{
	char *length_u;

	length_u = NULL;
	if (chk_lng(str, i, 'u') == 'z')
		length_u = ft_itoa_longlong(va_arg(va, unsigned int));
	else if (chk_lng(str, i, 'u') == 'l')
		length_u = ft_itoa_longlong(va_arg(va, long unsigned int));
	else if (chk_lng(str, i, 'u') == 'm')
		length_u = ft_itoa_longlong(va_arg(va, long long int));
	else if (chk_lng(str, i, 'u') == 'h')
		length_u = ft_itoa_longlong(va_arg(va, int));
	else if (chk_lng(str, i, 'u') == 'i')
		length_u = ft_itoa_longlong(va_arg(va, int));
	if (ft_strcmp("0", length_u) == 0 && chk_preciz(str, i, 'u') == 0
		&& chk_flg(str, i, 'u', '.') == 1)
		return (ft_strdup(""));
	return (length_u);
}

static char		*step3_part2(char *str, char *tmp, int i)
{

		if (chk_preciz(str, i, 'u') > strln(tmp))
			tmp = ad_0_aftersign(tmp, chk_preciz(str, i, 'u') - strln(tmp));
		if (chk_fld_wth(str, i, 'u') > strln(tmp))
		{
			if (chk_flg(str, i, 'u', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'u') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'u') - strln(tmp));
		}
	return (tmp);
}

static char		*stepthree_if_u(char *str, char *s, int i)
{
	char *tmp;

	tmp = s;
	if (chk_preciz(str, i, 'u') == 0 && chk_flg(str, i, 'u', '.') == 0)
	{	
		if (check_zero_flag(str, i, 'u') == 1)
		{
			if (chk_fld_wth(str, i, 'u') > strln(tmp))
				tmp = ad_0_aftersign(tmp, chk_fld_wth(str, i, 'u') - strln(tmp));
		}
		else if (chk_fld_wth(str, i, 'u') > strln(tmp))
		{
			if (chk_flg(str, i, 'u', '-') == 1)
				tmp = ad_fld_end(tmp, chk_fld_wth(str, i, 'u') - strln(tmp));
			else
				tmp = ad_fld_strt(tmp, chk_fld_wth(str, i, 'u') - strln(tmp));
		}
	}
	else
	{
		tmp = step3_part2(str, tmp, i);
	}
	return (tmp);
}

void			detected_u(char *str, va_list va, int i)
{
	char *tmp;

	tmp = string_if_u(str, va, i);
	tmp = stepthree_if_u(str, tmp, i);
	ft_putstr(tmp);
	return ;
}
/*
int	detect_n_do(char *str, va_list va, int i)
{
	(void)va;
	int j;

	j = i;
	while (str[j])
	{
		if (str[j] == 'u')
		{
			detected_u(str, va, i);
			break;
		}
		j++;
	}
	return (j);
}

void	ft_printf(char *str, ...)
{
	va_list va;
	int i;

	i = 0;
	if (str == NULL)
	{
		write(1, "No input arguments\n", 19);
		return ;
	}
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = detect_n_do(str, va, i);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main()
{

int nb = 123;

     ft_printf("%.5u", nb);
printf("\n--------\n%.5u", nb);

}
*/
