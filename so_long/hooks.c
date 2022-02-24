/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 02:28:23 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/02 01:09:31 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*get_position(t_map_render *game, t_list *map)
{
	t_list	*temp;

	temp = map->next;
	while (temp)
	{
		game->pos_x = 0;
		while (*(char *)(temp->content + game->pos_x) \
		&& *(char *)(temp->content + game->pos_x) != 'P' \
		&& *(char *)(temp->content + game->pos_x) != '\n')
			++game->pos_x;
		if (*(char *)(temp->content + game->pos_x) == 'P')
			break ;
		map = temp;
		temp = temp->next;
	}
	return (map);
}

char	*next_move(t_list *temp, t_map_render *game, int keycode)
{
	char	*next;

	next = (char *)temp->content;
	if (keycode == UP)
		next = (char *)temp->content + game->pos_x;
	if (keycode == DOWN)
		next = (char *)temp->next->next->content + game->pos_x;
	if (keycode == LEFT)
		next = (char *) temp->next->content + game->pos_x - 1;
	if (keycode == RIGHT)
		next = (char *) temp->next->content + game->pos_x + 1;
	return (next);
}

void	player_position(t_map_render *game, int keycode)
{
	t_list	*temp;
	char	*next;

	temp = get_position(game, game->map);
	next = next_move(temp, game, keycode);
	if (*next != '1')
	{
		if (*next == 'C' || *next == '0')
		{
			if (*next == 'C')
				++game->collected;
			++game->moves;
		}
		else if (*next == 'E' && game->collected == game->collect)
		{
			++game->moves;
			finish_game(game);
		}
		else if (*next == 'E')
			return ;
		*next = 'P';
		*(char *)(temp->next->content + game->pos_x) = '0';
	}
	return ;
}

int	key_hook(int keycode, t_map_render *game)
{
	if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT)
	{
		player_position(game, keycode);
		make_map(game);
	}
	if (keycode == ESC)
		finish_game(game);
	return (0);
}
