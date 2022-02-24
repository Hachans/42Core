/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:24:34 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/23 19:12:10 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	word_count(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			counter++;
			i = 1;
		}
		if (*s == c)
			i = 0;
		s++;
	}
	return (counter);
}

char	*dup_word(char const *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		start;
	char	**split;

	i = -1;
	j = 0;
	start = -1;
	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j++] = dup_word(s, start, i);
			start = -1;
		}
	}
	split[j] = 0;
	return (split);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	s2;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	s2 = ft_strlen(needle);
	if (len == 0)
		return (0);
	while (haystack[i] != '\0' && (s2 + i) <= len)
	{	
		if (ft_strncmp(haystack + i, needle, s2) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
