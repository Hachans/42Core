/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:52:03 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:23 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned int n)
{
	int		rez;
	char	digit;

	rez = 0;
	digit = 0;
	if (n > 9)
		rez += ft_printu(n / 10);
	digit = n % 10 + '0';
	rez += write(1, &digit, 1);
	return (rez);
}
