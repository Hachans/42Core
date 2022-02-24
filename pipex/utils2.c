/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgars <edgars@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:27:54 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/22 13:52:13 by edgars           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	int		total;

	total = nmemb * size;
	p = malloc(total);
	while (total--)
		*(char *)p++ = 0;
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char )c)
		return ((char *)s);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	len;
	char			*s2;

	if (!s1 || !set)
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len]))
		len--;
	s2 = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!s2)
		return (0);
	k = 0;
	len = (len - i + 1);
	while (k < len)
		s2[k++] = s1[i++];
	s2[k] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	size_t			s1_len;
	char			*strjoin;

	if (!s1 || !s2)
		return (0);
	i = -1;
	j = -1;
	s1_len = (ft_strlen(s1) + ft_strlen(s2));
	strjoin = (char *)malloc(s1_len + 1);
	if (strjoin == 0)
		return (0);
	while (s1[++i])
		strjoin[i] = s1[i];
	while (s2[++j])
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	return (strjoin);
}
