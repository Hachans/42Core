/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:05:45 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:12 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdi(int n)
{
	int		rez;
	char	digit;

	rez = 0;
	digit = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			rez += write(1, "-", 1);
			n = n * -1;
		}
		if (n > 9)
			rez += ft_printdi(n / 10);
		digit = n % 10 + '0';
		rez += write(1, &digit, 1);
	}
	return (rez);
}
