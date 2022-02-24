/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:40:45 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:26 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int n)
{
	int	rez;
	int	digit;

	rez = 0;
	digit = 0;
	if (n >= 16)
		rez += ft_printx(n / 16);
	digit = n % 16;
	rez += write(1, &"0123456789abcdef"[digit], 1);
	return (rez);
}
