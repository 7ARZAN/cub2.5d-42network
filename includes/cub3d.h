/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:16:50 by elakhfif          #+#    #+#             */
/*   Updated: 2024/06/11 23:15:03 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./lib.h"
# include "./structs.h"

# define BLOCK_SIZE 32
# define WINDOW_X 1200
# define WINDOW_Y 800
# define FOV 60
# define ROTATION_SPEED 1.4f
# define PLAYER_SPEED 2.0f
# define WALL_MARGIN 5

bool		check_inters(t_map *game, t_ray *ray);
char		*north_texture(char *line);
char		*south_texture(char *line);
char		*west_texture(char *line);
char		*east_texture(char *line);
void		free2d(char **split);
unsigned int		create_rgba(int r, int g, int b, int a);
int			floor_color(char *line);
int			ceiling_color(char *line);
int			check_file(int ac, char **av);
int			check_map(t_map *map);
int			count_player(t_map *map);
void		read_map(t_map *data, char *file, int skipped);
void		extract_assets(char *line, t_map *cub);
void		lerrx(bool condition, char *message);
t_map		*parser(int ac, char **av);
void		skip_spaces(char *line, int *j);
int			get_assets(t_map *map, char *line);
void		load_assets(t_map *text);
void		init_game(t_map *game);
double		normalize_angle(double angle);
void		draw_ceil_floor(t_map *game);
t_ray		init_ray(void);
void		init_screen(t_map *game, char *title);
void		keybinding(t_map *game);
void		draw_view_angle(t_map *game, t_ray ray);
t_ray		horizontal_intercept(t_map *game, double fov, t_ray player);
t_ray		vertical_intercept(t_map *game, double fov, t_ray player);
unsigned int	get_color_from_texture(mlx_texture_t *tex, int x, int y);
t_ray		cast_ray(t_map *game, double fov);
void		normalize_fov_angle(double *angle);
int			main(int ac, char **av);

#endif
