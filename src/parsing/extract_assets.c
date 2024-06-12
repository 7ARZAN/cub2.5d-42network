/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:10:15 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/12 02:36:11 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free2d(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	extract_assets(char *line, t_map *cub)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		cub->ident[0] = north_texture(line);
	if (ft_strncmp(line, "SO", 2) == 0)
		cub->ident[1] = south_texture(line);
	if (ft_strncmp(line, "WE", 2) == 0)
		cub->ident[2] = west_texture(line);
	if (ft_strncmp(line, "EA", 2) == 0)
		cub->ident[3] = east_texture(line);
	if (ft_strncmp(line, "F", 1) == 0)
		cub->colors[0] = floor_color(line);
	if (ft_strncmp(line, "C", 1) == 0)
		cub->colors[1] = ceiling_color(line);
}

int	get_assets(t_map *cub, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	line = gnl(fd);
	i = 0;
	lerrx(fd != -1 || *line != '\0', "cant open FILE");
	while (line && ft_strchr("\t 10", line[0]) == NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		extract_assets(line, cub);
		free(line);
		line = gnl(fd);
		i++;
	}
	free(line);
	return (i);
}

unsigned int	*convert_tex_to_px(mlx_texture_t *tex)
{
	int				x;
	int				y;
	unsigned int	*pixels;

	x = 0;
	y = 0;
	pixels = ft_calloc(tex->width * tex->height, sizeof(unsigned int));
	while (x < (tex->width * tex->height))
	{
		pixels[x] = create_rgba(tex->pixels[y], tex->pixels[y + 1],
				tex->pixels[y + 2], tex->pixels[y + 3]);
		y += 4;
		x++;
	}
	return (pixels);
}

void	load_assets(t_map *text)
{
	int	i;

	i = -1;
	text->textures[0] = mlx_load_png(text->ident[0]);
	text->textures[1] = mlx_load_png(text->ident[1]);
	text->textures[2] = mlx_load_png(text->ident[2]);
	text->textures[3] = mlx_load_png(text->ident[3]);
	free(text->ident[0]);
	free(text->ident[1]);
	free(text->ident[2]);
	free(text->ident[3]);
	if (text->textures[0] == NULL || text->textures[1] == NULL
		|| text->textures[2] == NULL || text->textures[3] == NULL)
	{
		printf("failed: the textures are not loaded\n");
		exit(EXIT_FAILURE);
	}
	text->texture_pixels = ft_calloc(4, sizeof(unsigned int *));
	text->texture_pixels = convert_tex_to_px(text->textures[0]);
}
