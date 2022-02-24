/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:31:44 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/03 02:52:47 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"mlx/mlx.h"
# include	"libft/libft.h"
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# define UP 13 
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_image
{
	void	*img;
	int		size_x;
	int		size_y;
	int		point_x;
	int		point_y;
}				t_image;

typedef struct s_map_render
{
	void	*mlx;
	void	*mlx_win;
	int		moves;
	int		collect;
	int		collected;
	int		player;
	int		exit;
	int		pos_x;
	t_list	*map;
	t_image	img;
}				t_map_render;

enum {
	ON_DESTROY = 17
};

void	invalid_arg(void);
void	invalid_map(t_map_render *game);
void invalid_top(void);
void	make_map(t_map_render *game);
void	load_assets(t_map_render *game, char c, int x, int y);
int		map_check(t_map_render *game, t_list **map, int fd);
size_t	len_no_n(char *s);
int		key_hook(int keycode, t_map_render *game);
void	player_position(t_map_render *game, int keycode);
int		finish_game(t_map_render *game);

#endif