/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:13:37 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 06:28:24 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static e_idents	identifiers(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (NO);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (SO);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (WE);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (EA);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (F);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (C);
	else
		return (NONE);
}

static int	check_ident_if_valid(char *path)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(path, '.');
	if (ft_strncmp(ext, ".png", 4) != 0)
		return (printf("failed: invalid file extension\n"), -1);
	path = ft_strtrim(path, " \t\n");
	fd = open(path, O_RDONLY | 0644);
	if (fd < 0 || ft_strlen(path) == 0)
		return (printf("failed: invalid file path\n"), -1);
	close(fd);
	return (0);
}

static int	colors_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 24 | g << 16 | b << 8);
}

static int	extract_map_vars(t_map *map, char **vals)
{
	char	**rgb;
	int		i;

	i = 0;
	while (vals[i])
		i++;
	if (i != 2)
		return (printf("failed: invalid map variables\n"), -1);
	rgb = ohmysplit(vals[1], ',');
	if (rgb[0] && rgb[1] && rgb[2] && !rgb[3])
	{
		if (colors_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2])) == -1)
			return (printf("failed: invalid color\n"), -1);
		if (identifiers(vals[0]) == F)
			map->colors[0] = colors_rgb(ft_atoi(rgb[0]),
					ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		else if (identifiers(vals[0]) == C)
			map->colors[1] = colors_rgb(ft_atoi(rgb[0]),
					ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		return (free2d(rgb), 0);
	}
	return (printf("failed: to extract map variables\n"), -1);
}

int	check_elements(t_map *map, char *line)
{
	char	**vals;

	if (!line)
		return (0);
	vals = ohmysplit(line, ' ');
	if (vals[0] && vals[1])
	{
		if (identifiers(vals[0]) == NO)
			map->ident[0] = ft_strdup(vals[1]);
		else if (identifiers(vals[0]) == SO)
			map->ident[1] = ft_strdup(vals[1]);
		else if (identifiers(vals[0]) == WE)
			map->ident[2] = ft_strdup(vals[1]);
		else if (identifiers(vals[0]) == EA)
			map->ident[3] = ft_strdup(vals[1]);
		else if (identifiers(vals[0]) == F)
			extract_map_vars(map, vals);
		else if (identifiers(vals[0]) == C)
			extract_map_vars(map, vals);
		else
			return (printf("failed: invalid identifier\n"), -1);
		return (free2d(vals), 0);
	}
	return (printf("failed: to extract map variables\n"), -1);
}
