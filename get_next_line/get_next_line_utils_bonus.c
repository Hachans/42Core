/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:01:16 by ekraujin          #+#    #+#             */
/*   Updated: 2022/01/10 21:41:05 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ("");
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (s[i] && i < len && (start + i) < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*s;
	int		total;

	total = nmemb * size;
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	s = p;
	while (total--)
	{
		*s = '\0';
		s++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	size_t			s1_len;
	char			*strjoin;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	s1_len = (ft_strlen(s1) + ft_strlen(s2));
	strjoin = (char *)malloc(s1_len + 1);
	if (strjoin == 0)
		return (0);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned int	k;
	char			*s1;
	char			*s2;

	if (!src && !dest)
		return (0);
	i = 0;
	k = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	if (src < dest)
	{
		i = n - 1;
		k = n - 1;
		while (n--)
			s1[i--] = s2[k--];
	}
	else if (src >= dest)
	{
		while (n--)
			s1[i++] = s2[k++];
	}
	return (s1);
}
