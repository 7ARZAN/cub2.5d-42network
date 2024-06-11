/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:00:52 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 06:42:12 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	space_surrounding(t_map *map, int i, int j)
{
	if (map->map[i][j] == ' ' && (i != 0 || i != map->map_y - 1))
	{
		if (!ft_strchr("1 \t", map->map[i][j]))
		{
			printf("space not surrounded by 1 in this position: %d %d\n", i, j);
			return (-1);
		}
	}
	return (0);
}

static int	check_player_position(t_map *map, int i, int j)
{
	if (ft_strchr("NSEW", map->map[i][j]))
	{
		if (space_surrounding(map, i, j) == -1)
			return (-1);
		if (i == 0 || i == map->map_y - 1 || j == 0 || j == map->map_x - 1)
			return (printf("failed: player is at the edge of the map\n"), -1);
		if (ft_strchr("NSEW", map->map[i - 1][j]) ||
				ft_strchr("NSEW", map->map[i + 1][j])
				|| ft_strchr("NSEW", map->map[i][j - 1])
				|| ft_strchr("NSEW", map->map[i][j + 1]))
			return (printf("failed: player is not surrounded by walls\n"), -1);
	}
	return (0);
}

static int	player_dir(char dir)
{
	if (dir == 'N')
		return (270);
	else if (dir == 'S')
		return (90);
	else if (dir == 'E')
		return (0);
	else if (dir == 'W')
		return (180);
	return (-1);
}

static void	set_player_data(t_map *d, int row, int colmn)
{
	d->player.px = colmn + 0.5;
	d->player.py = row + 0.5;
	d->pdir = player_dir(d->map[row][colmn]);
	d->map[row][colmn] = '0';
}

int	count_player(t_map *map)
{
	int	i;
	int	idx;
	int	player;

	i = -1;
	player = 0;
	while (++i < map->map_y)
	{
		idx = -1;
		while (map->map[i][++idx])
		{
			if (space_surrounding(map, i, idx) == -1)
				return (-1);
			if (ft_strchr("NSEW", map->map[i][idx]))
			{
				if (check_player_position(map, i, idx) == -1)
					return (-1);
				set_player_data(map, i, idx);
				player++;
			}
		}
	}
	lerrx(player == 1, "Multiple players defined in the map");
	return (0);
}
