/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:28:35 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 01:28:37 by tarzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = parser(ac, av);
	init_screen(map, "dummy cub2.5d");
	init_game(map);
	mlx_loop(map->mlx);
	return (0);
}
