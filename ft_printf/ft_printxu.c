/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:48:56 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:29 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printxu(unsigned int n)
{
	int	rez;
	int	digit;

	rez = 0;
	digit = 0;
	if (n >= 16)
		rez += ft_printxu(n / 16);
	digit = n % 16;
	rez += write(1, &"0123456789ABCDEF"[digit], 1);
	return (rez);
}
