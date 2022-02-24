/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:52:15 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:15:55 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *s, int i, va_list args)
{
	int	rez;

	rez = 0;
	if (s[i] == 'c')
		rez += ft_printc(va_arg(args, int));
	else if (s[i] == 's')
		rez += ft_printstr(va_arg(args, char *));
	else if (s[i] == 'p')
		rez += ft_printp(va_arg(args, unsigned long int));
	else if (s[i] == 'd' || s[i] == 'i')
		rez += ft_printdi(va_arg(args, int));
	else if (s[i] == 'u')
		rez += ft_printu(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		rez += ft_printx(va_arg(args, unsigned int));
	else if (s[i] == 'X')
		rez += ft_printxu(va_arg(args, unsigned int));
	else if (s[i] == '%')
		rez += write(1, "%", 1);
	return (rez);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		rez;
	va_list	args;

	i = 0;
	rez = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			rez += conversion(s, i + 1, args);
			i++;
		}
		else
			rez += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (rez);
}

// #include <stdio.h>
// int main()
// {
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200876;
// 	int		k = 123456789;
// 	char	*n = "azdsfsfsdfs";
// 	char	p[] = "134124";
// 	char 	r = '9';
// 	char	c = 'a';

// 	printf("-----------\n");
// 	printf("%c, %s, %p, %c, %s, %p\n", c, n, n, r, p, p);
// 	ft_printf("%c, %s, %p, %c, %s, %p\n", c, n, n, r, p, p);
// 	printf("-----------\n");
// 	printf("%i, %d, %u, %i, %d, %u\n", d, d, d, e, e, e);
// 	ft_printf("%i, %d, %u, %i, %d, %u\n", d, d, d, e, e, e);
// 	printf("-----------\n");
// 	printf("%x, %X, %x, %X\n", h, k, f, g);
// 	ft_printf("%x, %X, %x, %X\n", h, k, f, g);
// 	printf("-----------\n");
// 	printf("%x, and %X, %x, %X\n", h, k, f, g);
// 	ft_printf("%x, and %X, %x, %X\n", h, k, f, g);
// }