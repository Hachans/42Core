/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:06:09 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:19 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long int n)
{
	int	digit;
	int	rez;

	digit = 0;
	rez = 0;
	if (n >= 16)
		rez += ft_printp(n / 16);
	if (rez == 0)
		rez += write(1, "0x", 2);
	digit = n % 16;
	rez += write(1, &"0123456789abcdef"[digit], 1);
	return (rez);
}
