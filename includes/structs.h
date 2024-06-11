/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:04:34 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 23:14:16 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "./MLX42/MLX42/MLX42.h"

typedef struct	s_coords
{
	double	px;
	double	py;
}		t_coords;

typedef struct	s_pxl
{
	double	starty;
	double	endy;
}		t_pxl;

typedef struct	s_map
{
	t_coords	player;
	char	**map;
	int	map_x;
	int	map_y;
	double	pdir;
	int	colors[2];
	char	*ident[4];
	mlx_texture_t	*textures[4];
	mlx_t	*mlx;
	mlx_image_t	*img;
	unsigned int	*texture_pixels;
	double	dproj;
}		t_map;

typedef struct	s_ray
{
	double	distance;
	double	ray_x;
	double	ray_y;
	int		looks[4];
	bool	horizontal;
}		t_ray;

#endif
