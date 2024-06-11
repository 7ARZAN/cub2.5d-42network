/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:40:37 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 22:33:57 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_vertical_line(t_map *game, double x, double *coords, int color)
{
	double	y;

	y = coords[0];
	while (y < coords[1])
	{
		if (y > 0 && y < WINDOW_Y)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}

static void	create_new_image(t_map *game)
{
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WINDOW_X, WINDOW_Y);
}

static void	calculate_ray_and_fov(t_map *game, double *rangle, double *fov_step)
{
	*rangle = game->pdir - 30;
	*fov_step = FOV / (double)WINDOW_X;
}

static void	draw_with_texture_mapping(t_map *game, t_ray ray, int x, t_pxl pxl)
{
	double	tstep;
	int		tx;
	int		index;
	int		color;
	double	coords[2];

	tx = 0;
	index = -1;
	tstep = (pxl.endy - pxl.starty) / BLOCK_SIZE;
	if (ray.horizontal == true)
		tx = (int)ray.ray_x % BLOCK_SIZE;
	else
		tx = (int)ray.ray_y % BLOCK_SIZE;
	while (++index < BLOCK_SIZE)
	{
		coords[0] = pxl.starty;
		coords[1] = pxl.starty + tstep;
		color = game->texture_pixels[BLOCK_SIZE * index + tx];
		draw_vertical_line(game, x, coords, color);
		pxl.starty += tstep;
	}
}

void	draw_view_angle(t_map *game, t_ray ray)
{
	double	rangle;
	double	fov_step;
	double	line_height;
	int		index;
	t_pxl	pxl;

	index = -1;
	create_new_image(game);
	draw_ceil_floor(game);
	calculate_ray_and_fov(game, &rangle, &fov_step);
	while (++index < WINDOW_X)
	{
		normalize_fov_angle(&rangle);
		ray = cast_ray(game, rangle);
		line_height = (double)BLOCK_SIZE / (ray.distance * cos(
					deg2rad(rangle - game->pdir))) * game->dproj;
		pxl.starty = (WINDOW_Y / 2) - (line_height / 2);
		pxl.endy = (WINDOW_Y / 2) + (line_height / 2);
		draw_with_texture_mapping(game, ray, index, pxl);
		rangle += fov_step;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
