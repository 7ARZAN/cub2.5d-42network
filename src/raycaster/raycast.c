/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:39:56 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/12 01:29:34 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	normalize_ray(t_ray *ray, t_map *game)
{
	if (ray->ray_x > ((game->map_x) * BLOCK_SIZE))
		ray->ray_x = ((game->map_x) * BLOCK_SIZE) - 1;
	else if (ray->ray_x < 0)
		ray->ray_x = 1;
	if (ray->ray_y > ((game->map_y) * BLOCK_SIZE))
		ray->ray_y = ((game->map_y) * BLOCK_SIZE) - 1;
	else if (ray->ray_y < 0)
		ray->ray_y = 1;
}

static void	ray_looks(t_ray *ray, t_map *game, double fov)
{
	ray->looks[1] = (fov > 0.0 && fov < 180.0);
	ray->looks[0] = !ray->looks[1];
	ray->looks[3] = (fov > 90.0 && fov < 270.0);
	ray->looks[2] = !ray->looks[3];
}

t_ray	vertical_intercept(t_map *game, double fov, t_ray player)
{
	int		dmax;
	t_ray	ray;

	if (check_inters(game, &player) == true)
	{
		ft_memmove(&ray, &player, sizeof(t_ray));
		return (ray);
	}
	ray_looks(&ray, game, fov);
	dmax = game->map_x * game->map_y;
	if (fov == 90.0 || fov == 270.0)
		dmax = game->map_x;
	if (ray.looks[3])
	{
		ray.ray_x = floor(player.ray_x / BLOCK_SIZE) * BLOCK_SIZE - 0.001;
		ray.ray_y = player.ray_y + fabs(
				ray.ray_x - player.ray_x) * tan(fov * (M_PI / 180));
	}
	else
	{
		ray.ray_x = floor((player.ray_x + BLOCK_SIZE
					) / BLOCK_SIZE) * BLOCK_SIZE;
		ray.ray_y = player.ray_y + fabs(ray.ray_x - player.ray_x
				) * -tan(fov * (M_PI / 180));
	}
	normalize_ray(&ray, game);
	return (ray);
}

t_ray	horizontal_intercept(t_map *game, double fov, t_ray player)
{
	int		dmax;
	t_ray	ray;

	if (check_inters(game, &player) == true)
	{
		ft_memmove(&ray, &player, sizeof(t_ray));
		return (ray);
	}
	ray_looks(&ray, game, fov);
	dmax = game->map_y;
	if (fov == 0.0 || fov == 180.0 || fov == 360.0)
		dmax = 0;
	if (ray.looks[1])
	{
		ray.ray_y = floor(player.ray_y / BLOCK_SIZE) * BLOCK_SIZE - 0.001;
		ray.ray_x = player.ray_x + fabs(
				ray.ray_y - player.ray_y) / tan(fov * (M_PI / 180));
	}
	else
	{
		ray.ray_y = floor(
				(player.ray_y + BLOCK_SIZE) / BLOCK_SIZE) * BLOCK_SIZE;
		ray.ray_x = player.ray_x + fabs(
				ray.ray_y - player.ray_y) / -tan(fov * (M_PI / 180));
	}
	normalize_ray(&ray, game);
	return (ray);
}
