/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:57:58 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/03 02:51:52 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_n_bot(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	line_error(t_map_render *game, char *line)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'P')
			++game->player;
		else if (line[i] == 'C')
			++game->collect;
		else if (line[i] == 'E')
			++game->exit;
		else if (line[i] != '1' && line[i] != '0')
			return (0);
		i++;
	}
	if (line[--i] != '1')
		return (0);
	return (1);
}

int	map_line_check(t_map_render *game, t_list **map, size_t len, int count)
{
	int		i;
	t_list	*temp;

	if (count < 3)
		return (0);
	i = 0;
	temp = (*map)->next;
	while (temp->next != NULL)
	{
		if (len_no_n(temp->content) != len)
			return (0);
		if (count - 1 != 1)
		{
			if (!line_error(game, temp->content))
				return (0);
		}
		temp = temp->next;
	}
	if (!check_top_n_bot(temp->content))
		return (0);
	if (game->player != 1 || !game->collect || !game->exit)
		return (0);
	return (1);
}

int	map_check(t_map_render *game, t_list **map, int fd)
{
	size_t	len;
	char	*temp;
	int		lc;

	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	lc = 0;
	temp = get_next_line(fd);
	if (!check_top_n_bot(temp))
		invalid_top();
	len = len_no_n(temp);
	while (temp)
	{
		ft_lstadd_back(map, ft_lstnew(temp));
		temp = get_next_line(fd);
		lc++;
	}
	if (!map_line_check(game, map, len, lc))
		return (0);
	return (1);
}
