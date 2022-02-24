/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:56:43 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/02 01:09:05 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_map_render *game, char c, int x, int y)
{
	if (c == '1')
		game->img.img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/wall.xpm", &game->img.size_x, &game->img.size_y);
	else if (c == 'P')
		game->img.img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/player.xpm", &game->img.size_x, &game->img.size_y);
	else if (c == 'C')
		game->img.img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/collect.xpm", &game->img.size_x, &game->img.size_y);
	else if (c == 'E')
		game->img.img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/exit.xpm", &game->img.size_x, &game->img.size_y);
	else
		game->img.img = mlx_xpm_file_to_image(game->mlx, \
		"./assets/back.xpm", &game->img.size_x, &game->img.size_y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, x, y);
	mlx_destroy_image(game->mlx, game->img.img);
}

void	make_map(t_map_render *game)
{
	t_list	*temp;
	char	*line;
	int		i;

	i = 0;
	game->img.point_x = 0;
	game->img.point_y = 0;
	temp = game->map;
	while (temp)
	{
		line = temp->content;
		while (line[i] && line[i] != '\n')
		{
			load_assets(game, line[i], game->img.point_x, game->img.point_y);
			i++;
			game->img.point_x += 48;
		}
		temp = temp->next;
		game->img.point_x = 0;
		game->img.point_y += 48;
		i = 0;
	}
}
