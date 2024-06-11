/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarzan <elakhfif@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:28:59 by tarzan            #+#    #+#             */
/*   Updated: 2024/06/11 03:14:59 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file(int ac, char **av)
{
	int	fd;

	fd = 0;
	if (ac != 2)
		return (printf("failed: invalid number of arguments\n"), -1);
	if (ft_strlen(av[1]) < 5)
		return (printf("failed: invalid file extension\n"), -1);
	if (ft_strncmp(ft_strlen(av[1]) - 4 + av[1], ".cub", 4) == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (printf("failed: invalid file path\n"), -1);
		return (fd);
	}
	return (printf("failed: invalid file extension\n"), -1);
}
