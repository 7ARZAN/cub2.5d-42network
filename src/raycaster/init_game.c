/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:16:18 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 07:28:01 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += 360;
	if (angle >= 360)
		angle -= 360;
	return (angle);
}

static void	game_loop(void *param)
{
	t_map	*game;
	t_ray	ray;

	ray = init_ray();
	game = (t_map *)param;
	keybinding(game);
	draw_view_angle(game, ray);
}

void	init_game(t_map *game)
{
	mlx_loop_hook(game->mlx, game_loop, game);
}
