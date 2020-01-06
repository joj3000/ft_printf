/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:40:26 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/06 11:38:11 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_til_specif(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p'
			|| str[i] == 'd' || str[i] == 'i' || str[i] == 'o'
			|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '%' || str[i] == 'f')
			break;
		i++;
	}
	return (i);
}

static void	detected_xX(char *str, va_list va, int i, char ch)
{
		if (ch == 'x' )
			detected_x(str, va, i);
		else if (ch == 'X')
			detected_bx(str, va, i);
		else if (ch == 'o')
			detected_o(str, va, i);
}

static int	detect_n_do(char *str, va_list va, int i)
{
	int j;
	char ch;

	j = i + 1;
	ch = which_flag(str, j);
		if (ch == 'd' )
			detected_d(str, va, i);
		else if (ch == 's')
			detected_s(str, va, i);
		else if (ch == 'p')
			detected_p(str, va, i);
		else if (ch == 'c')
			detected_c(str, va, i);
		else if (ch == 'i')
			detected_i(str, va, i);
		else if (ch == 'u')
			detected_u(str, va, i);
		else if (ch == 'x' || ch == 'X' || ch == 'o')
			detected_xX(str, va, i, ch);
		else if (ch == 'f')
			detected_f(str, va, i);
		else if (ch == '%')
			detected_per(str, va, i + 1);
		else if (ch == 'z')
		{	
			write(1, "%", 1);
			return (i);
		}
	return (count_til_specif(str, j));
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

/*
int main()
{
//	unsigned int u = 4294967295;
//	int c = 0;
//	long double c = 1.5;
	       ft_printf("%Lx", 42);
	printf("\n------\n%Lx", 42);
    // ft_printf("%#.5x", 21);
//ft_printf("\n-----\n%o", c);	
	//ft_printf("ergserg%-12daa", 123);
	//   printf("\nergserg%-12daa", 123);
}
*/
