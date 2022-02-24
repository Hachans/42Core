/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:24:04 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/24 18:38:46 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_check(char *nptr)
{
	int	result;
	int		i;

	result = 0;
	i = 0;
	if (!*nptr)
		return (-1);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-' || nptr[++i] == '\0')
			return (-1);
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			result = result * 10 + (nptr[i] - '0');
		else
			return (-1);
		i++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\t'
			|| nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-' )
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}