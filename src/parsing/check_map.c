/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:50:42 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/12 00:07:23 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_first_last_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (!ft_strchr(" 1", map->map[0][i]))
			return (printf("failed: map is not closed\n"), -1);
		i++;
	}
	i = 0;
	while (map->map[map->map_y - 1][i])
	{
		if (!ft_strchr("1 ", map->map[map->map_y - 1][i]))
			return (printf("failed: map is not closed\n"), -1);
		i++;
	}
	return (0);
}

static int	check_map_closed(t_map *map)
{
	int	i;
	int	idx;

	i = 0;
	while (i < map->map_y)
	{
		idx = 0;
		while (map->map[i][idx])
		{
			if (map->map[i][idx] == '0')
			{
				if (i == 0 || i == map->map_y - 1 || idx == 0
					|| idx == (int)ft_strlen(map->map[i]) - 1)
					return (printf("failed: map is not closed\n"), -1);
				if (map->map[i - 1][idx] == ' ' || map->map[i + 1][idx] == ' '
						|| map->map[i][idx - 1] == ' '
						|| map->map[i][idx + 1] == ' ')
					return (printf("failed: map is not closed\n"), -1);
			}
			idx++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(" 01NSEW", map->map[i][j]))
				return (printf("failed: map contains invalid character\n"), -1);
			j++;
		}
		i++;
	}
	if (check_map_closed(map) == -1)
		return (-1);
	return (check_first_last_line(map));
}
