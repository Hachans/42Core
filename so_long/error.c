/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:57:16 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/03 02:52:29 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_arg(void)
{
	write(1, "Error\nInvalid argument.\n", 24);
	exit(0);
}

void invalid_top(void)
{
	write(1, "Error\nInvalid map\n", 18);
	exit(0);
}
void	invalid_map(t_map_render *game)
{
	ft_lstclear(&game->map, free);
	write(1, "Error\nInvalid map\n", 18);
	exit(0);
}
