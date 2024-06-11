/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:16:32 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 03:16:37 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray	init_ray(void)
{
	t_ray	ray;

	ray.distance = 0;
	ray.horizontal = 0;
	ray.looks[0] = 0;
	ray.looks[1] = 0;
	ray.looks[2] = 0;
	ray.looks[3] = 0;
	ray.ray_x = 0;
	ray.ray_y = 0;
	return (ray);
}

void	init_screen(t_map *game, char *title)
{
	game->mlx = mlx_init(WINDOW_X, WINDOW_Y, title, false);
	game->img = mlx_new_image(game->mlx, WINDOW_X, WINDOW_Y);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
