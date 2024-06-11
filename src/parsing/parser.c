/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:28:19 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 02:09:02 by tarzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*parser(int ac, char **av)
{
	t_map	*map;
	int		skipped;

	if (check_file(ac, av) == -1)
		exit(1);
	map = (t_map *)malloc(sizeof(t_map));
	lerrx(map != NULL, "Cant allocate map struct, increase the program break");
	skipped = get_assets(map, av[1]);
	read_map(map, av[1], skipped);
	lerrx(check_map(map) == 0, "something is wrong with the fucking map");
	lerrx(count_player(map) == 0, "something wrong with the map");
	load_assets(map);
	map->dproj = ((double)WINDOW_X / 2) / tan(deg2rad(FOV / 2));
	return (map);
}
