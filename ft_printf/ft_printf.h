/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:19:05 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/13 20:02:18 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	conversion(const char *s, int i, va_list args);
int	ft_printc(int c);
int	ft_printp(unsigned long int n);
int	ft_printdi(int n);
int	ft_printstr(char *s);
int	ft_printu(unsigned int n);
int	ft_printx(unsigned int n);
int	ft_printxu(unsigned int n);

#endif