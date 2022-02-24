/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:39:02 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/03 02:49:58 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	loop(t_map_render *game)
{	
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, 30, 30, 0xffff00, moves);
	return (0);
}

int	finish_game(t_map_render *game)
{
	ft_lstclear(&game->map, free);
	mlx_destroy_window(game->mlx, game->mlx_win);
	write(1, "Game closed!\n", 13);
	exit(0);
}

int	arg_check(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!ft_strncmp(s + (len - 4), ".ber", 4))
		return (1);
	return (0);
}

size_t	len_no_n(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}	

int	main(int argc, char **argv)
{
	t_map_render	game;
	int				fdm;

	fdm = open(argv[1], O_RDONLY);
	if (argc != 2 || !arg_check(argv[1]) || fdm <= 0)
		invalid_arg();
	if (!(map_check(&game, &game.map, fdm)))
		invalid_map(&game);
	close(fdm);
	game.moves = 0;
	game.collected = 0;
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, len_no_n(game.map->content) * 48, \
	ft_lstsize(game.map) * 48, "so_long");
	make_map(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, ON_DESTROY, 0, finish_game, &game);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_loop(game.mlx);
}
