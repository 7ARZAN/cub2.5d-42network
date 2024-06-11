/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:15:30 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 22:19:25 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void    move_player(t_map *game, double px , double py)
{
    double ppx;
    double ppy;

    ppx = (game->player.px * BLOCK_SIZE) + (px * PLAYER_SPEED);
    ppy = (game->player.py * BLOCK_SIZE) + (py * PLAYER_SPEED);
    if (
	game->map[(int) ((ppy + WALL_MARGIN) / BLOCK_SIZE)][(int)(ppx / BLOCK_SIZE)] == '1' ||
	game->map[(int) (ppy / BLOCK_SIZE)][(int)((ppx + WALL_MARGIN) / BLOCK_SIZE)] == '1' ||
	game->map[(int) ((ppy - WALL_MARGIN) / BLOCK_SIZE)][(int)(ppx / BLOCK_SIZE)] == '1' |
	game->map[(int) (ppy / BLOCK_SIZE)][(int)((ppx - WALL_MARGIN) / BLOCK_SIZE)] == '1' 
		    )
        return ;
    game->player.px = ((game->player.px * BLOCK_SIZE) + (px * PLAYER_SPEED))  /  BLOCK_SIZE;
    game->player.py = ((game->player.py * BLOCK_SIZE) + (py * PLAYER_SPEED)) /  BLOCK_SIZE;


}

void    keybinding(t_map *game)
{
	double rangle = game->pdir;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, cos(deg2rad(rangle)), -sin(deg2rad(rangle)));
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, -cos(deg2rad(rangle)), sin(deg2rad(rangle)));
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, sin(deg2rad(rangle)), cos(deg2rad(rangle)));
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, -sin(deg2rad(rangle)), -cos(deg2rad(rangle)));
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit(EXIT_SUCCESS);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->pdir = normalize_angle(game->pdir + ROTATION_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->pdir = normalize_angle(game->pdir - ROTATION_SPEED);
}

