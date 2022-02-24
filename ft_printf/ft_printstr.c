/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:29:46 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:21 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;
	int	rez;

	i = 0;
	rez = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		rez += write(1, &s[i], 1);
		i++;
	}
	return (rez);
}
