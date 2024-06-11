/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:16:51 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 07:42:39 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void    move_player(t_map *game, double px , double py)
{
    double ppx;
    double ppy;

    ppx = (game->player.px * BLOCK_SIZE) + (px * PLAYER_SPEED) + WALL_MARGIN;
    ppy = (game->player.py * BLOCK_SIZE) + (py * PLAYER_SPEED) + WALL_MARGIN;
    if (game->map[(int) floor(ppy / BLOCK_SIZE)][(int)floor(ppx / BLOCK_SIZE)] == '1')
        return ;
    game->player.px = ((game->player.px * BLOCK_SIZE) + (px * PLAYER_SPEED))  /  BLOCK_SIZE;
    game->player.py = ((game->player.py * BLOCK_SIZE) + (py * PLAYER_SPEED)) /  BLOCK_SIZE;
}

void    keybinding(t_map *game)
{
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        move_player(game, cos(deg2rad(game->pdir)), -sin(deg2rad(game->pdir)));
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        move_player(game, -cos(deg2rad(game->pdir)), sin(deg2rad(game->pdir)));
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        move_player(game, cos(deg2rad(game->pdir)), sin(deg2rad(game->pdir)));
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        move_player(game, -cos(deg2rad(game->pdir)), -sin(deg2rad(game->pdir)));
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        exit(EXIT_SUCCESS);
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        game->pdir = normalize_angle(game->pdir + ROTATION_SPEED);
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        game->pdir = normalize_angle(game->pdir - ROTATION_SPEED);
}
