/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realcast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:10:19 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 22:49:23 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	normalize_fov_angle(double *angle)
{
	double	for_angles[4];
	int		i;

	for_angles[0] = 360.0f;
	for_angles[1] = 90.0f;
	for_angles[2] = 180.0f;
	for_angles[3] = 270.0f;
	i = -1;
	while (++i < 4)
		if (fabs(for_angles[i] - *angle) < FLT_EPSILON)
			*angle += 0.1f;
	while (*angle > 360.0f)
		*angle -= 360.0f;
}

bool	check_inters(t_map *game, t_ray *ray)
{
	int	inters_x;
	int	inters_y;

	inters_y = floor(ray->ray_y / BLOCK_SIZE);
	inters_x = floor(ray->ray_x / BLOCK_SIZE);
	if (inters_y < 0)
		inters_y = 0;
	if (inters_x < 0)
		inters_x = 0;
	if (inters_y > game->map_y - 1 || inters_x > game->map_x - 1)
		return (true);
	if (game->map[inters_y][inters_x] == '1')
		return (true);
	return (false);
}

static void	finder(double x_step, double y_step, t_ray *player, t_map *game)
{
	while (check_inters(game, player) == false)
	{
		player->ray_x += x_step;
		player->ray_y += y_step;
	}
}

//if something is wrong, change return of hstep bye this:
//set [hstep.horizontal = true;] then [retuen hstep;]
t_ray	cast_ray(t_map *game, double fov)
{
	t_ray	hinter;
	t_ray	pinter;
	t_ray	hstep;
	t_ray	vstep;

	hinter.ray_x = game->player.px * BLOCK_SIZE;
	hinter.ray_y = game->player.py * BLOCK_SIZE;
	ft_memmove(&pinter, &hinter, sizeof(t_ray));
	pinter = vertical_intercept(game, fov, pinter);
	hinter = horizontal_intercept(game, fov, hinter);
	vstep = vertical_intercept(game, fov, pinter);
	hstep = horizontal_intercept(game, fov, hinter);
	finder(vstep.ray_x - pinter.ray_x, vstep.ray_y - pinter.ray_y,
		&vstep, game);
	finder(hstep.ray_x - hinter.ray_x, hstep.ray_y - hinter.ray_y,
		&hstep, game);
	vstep.distance = sqrt(pow(vstep.ray_x - game->player.px * BLOCK_SIZE, 2)
			+ pow(vstep.ray_y - game->player.py * BLOCK_SIZE, 2));
	hstep.distance = sqrt(pow(hstep.ray_x - game->player.px * BLOCK_SIZE, 2)
			+ pow(hstep.ray_y - game->player.py * BLOCK_SIZE, 2));
	if ((hstep.distance < vstep.distance))
		return (hstep.horizontal = true, hstep);
	return (vstep);
}
